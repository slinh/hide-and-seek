#include "Common.h"
#include "Renderer.h"
#include "Vertex3D.h"
#include "TextureItem.h"
#include "Camera.h"
#include "LightManager.h"
#include "Functions.h"

#ifdef COMPILE_PSP
#include <pspgu.h>
#include <pspgum.h>
#include "vram.h"
#endif

namespace psp { namespace engine { namespace video {

// -----------------------------------------------
//				IRenderer
// -----------------------------------------------

IRenderer* IRenderer::Make()
{
	return NEW_IN_DOMAIN(Video) TVideoRenderer();
}

// -----------------------------------------------
//				TVideoRenderer
// -----------------------------------------------

TVideoRenderer::TVideoRenderer()
#ifdef COMPILE_PSP
	:
FDrawBuffer(NULL), FDisplayBuffer(NULL), FDepthBuffer(NULL)
#endif
{

}

TVideoRenderer::~TVideoRenderer()
{
	// TODO texture management dont have to be in Renderer
	FTexture.Free();
}

void TVideoRenderer::Initialize3D()
{
#ifdef COMPILE_PSP
	// flush cache so that no stray data remains
	sceKernelDcacheWritebackAll();

	// Setup GU
	if(FDrawBuffer == NULL)
		FDrawBuffer		= getStaticVramBuffer(BUFFER_WIDTH, SCREEN_HEIGHT, GU_PSM_8888);
	if(FDisplayBuffer == NULL)
		FDisplayBuffer	= getStaticVramBuffer(BUFFER_WIDTH, SCREEN_HEIGHT, GU_PSM_8888);
	if(FDepthBuffer == NULL)
		FDepthBuffer	= getStaticVramBuffer(BUFFER_WIDTH, SCREEN_HEIGHT, GU_PSM_4444);

	sceGuInit();

	sceGuStart(GU_DIRECT, FDisplayList);

	sceGuDrawBuffer(GU_PSM_8888, FDrawBuffer, BUFFER_WIDTH);
	sceGuDispBuffer(SCREEN_WIDTH, SCREEN_HEIGHT, FDisplayBuffer, BUFFER_WIDTH);
	sceGuDepthBuffer(FDepthBuffer, BUFFER_WIDTH);

	// Drawing settings
	sceGuOffset(2048 - (SCREEN_WIDTH/2), 2048 - (SCREEN_HEIGHT/2));
	sceGuViewport(2048, 2048, SCREEN_WIDTH, SCREEN_HEIGHT);
	sceGuDepthRange(65535, 0);
	//sceGuDepthRange(0xc350,0x2710);
	sceGuScissor(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	sceGuDepthFunc(GU_GEQUAL);
	sceGuShadeModel(GU_SMOOTH);

	// Enabling default states
	sceGuEnable(GU_SCISSOR_TEST);
	sceGuEnable(GU_DEPTH_TEST);
	sceGuEnable(GU_TEXTURE_2D);
	sceGuEnable(GU_CLIP_PLANES);
	//sceGuFrontFace(GU_CW);
	//sceGuEnable(GU_CULL_FACE);
	//sceGuEnable(GU_ALPHA_TEST);

#ifdef WITH_LIGHTS
	// Light Initializing
	sceGuEnable(GU_LIGHTING);
	sceGuEnable(GU_LIGHT0);
	//sceGuEnable(GU_LIGHT1);
	//sceGuEnable(GU_LIGHT2);
	//sceGuEnable(GU_LIGHT3);
#endif

	// Synchronise display list
	sceGuFinish();
	sceGuSync(0,0);

	sceDisplayWaitVblankStart();
	sceGuDisplay(GU_TRUE);
#endif
}

void TVideoRenderer::Enable(const u32& parState)
{
#ifdef COMPILE_PSP
	sceGuEnable(parState);
#endif
}

void TVideoRenderer::Disable(const u32& parState)
{
#ifdef COMPILE_PSP
	sceGuDisable(parState);
#endif
}

void TVideoRenderer::Begin3DScene(const TCamera& parCamera, const TLightManager& parLightManager)
{
#ifdef COMPILE_PSP
	// Initialize display list
	sceGuStart(GU_DIRECT, FDisplayList);

	// Delete buffer for new rendering
	//sceGuClearColor(0xffff00ff);
	sceGuClearColor(0x0);
	//sceGuClearColor(0x0);
	sceGuClearDepth(0);
	sceGuClear(GU_COLOR_BUFFER_BIT | GU_DEPTH_BUFFER_BIT);

	// Test
	//sceGuColorMaterial(GU_AMBIENT);
	sceGuColorMaterial(GU_DIFFUSE);

#ifdef WITH_LIGHTS
	// Set level lights
	u32 locNBLights = parLightManager.GetLightList().size();
	for(u32 i=0; i<locNBLights; ++i)
	{
		const TLight& locLight = parLightManager.GetLight(i);

		ScePspFVector3 pos = { 0.f, 0.f, 0.f };
		parLightManager.FillPosition(locLight.GetId(), pos);
		
		sceGuLight( locLight.GetId(), GU_POINTLIGHT, GU_DIFFUSE_AND_SPECULAR, &pos);
		sceGuLightColor(locLight.GetId(), GU_DIFFUSE, locLight.GetDiffuseColor().FColor);
		sceGuLightColor(locLight.GetId(), GU_SPECULAR, locLight.GetAuxComponentColor().FColor);
		sceGuLightAtt(locLight.GetId(), 3.0f, 1.0f, 0.0f);
	}

	sceGuSpecular(12.0f);
	sceGuAmbient(0x00222222);
#endif

	// Setup projection of items in scene
	sceGumMatrixMode(GU_PROJECTION);
	sceGumLoadIdentity();
	sceGumPerspective(parCamera.GetFovy(), parCamera.GetAspect(), parCamera.GetNear(), parCamera.GetFar());
	
	// Set camera position and target
	sceGumMatrixMode(GU_VIEW);
	sceGumLoadIdentity();

	ScePspFVector3 locEye;
	ScePspFVector3 locTarget;
	ScePspFVector3 locUp;

	parCamera.CopyLookAt(locEye, locTarget, locUp);
	sceGumLookAt(&locEye, &locTarget, &locUp);	

	// Init matrix position of items in scene
	sceGumMatrixMode(GU_MODEL);
	sceGumLoadIdentity();

	{		
		ScePspFVector3 locPos = { 0, 0, 0 };
		ScePspFVector3 locRot = { 0, 0, 0 };

		sceGumTranslate(&locPos);
		sceGumRotateXYZ(&locRot);
	}
#endif
}

void TVideoRenderer::FlushTexture()
{
#ifdef COMPILE_PSP
	// TO DO : Fix bug on psp launching
#ifdef WITH_BLEND
	sceGuDisable(GU_LIGHTING);
	sceGuEnable(GU_BLEND);

	sceGuEnable(GU_ALPHA_TEST);
	sceGuAlphaFunc(GU_EQUAL, 0xff, 0xff);
	
	sceGuBlendFunc(GU_ADD, GU_SRC_ALPHA, GU_ONE_MINUS_SRC_ALPHA, 0, 0);
	sceGuPixelMask(0x00000000);
#endif

	// Setup texture
	if(FTexture.GetImage() == NULL)
	{
		//FTexture.Load("ms0:/PSP/GAME/Hide-And-Seek/Data/texture/World.ppm", CF_A1R5G5B5);
		FTexture.LoadWithTransparentColor("ms0:/PSP/GAME/Hide-And-Seek/Data/texture/World.ppm", CF_A1R5G5B5, TColor(255, 255, 0, 255));
	}

	// Flush texture already loaded in memory
	// Load texture just one time in memory
	sceGuTexMode(GU_PSM_5551, 0, 0, FTexture.GetIsSwizzled());
	sceGuTexImage(0, 512, 512, 512, FTexture.GetImage());

	sceGuTexScale(1.0f, 1.0f);
	sceGuTexOffset(0.0f, 0.0f);

	sceGuTexEnvColor(0x0);

	sceGuTexFunc(
#if defined(WITH_LIGHTS)
		GU_TFX_MODULATE
#elif defined(WITH_BLEND)
		GU_TFX_MODULATE
#else
		GU_TFX_REPLACE
#endif
		,
#ifdef WITH_BLEND
		GU_TCC_RGBA
#else
		GU_TCC_RGB
#endif
		);

	sceGuTexFilter(GU_LINEAR, GU_LINEAR);
	sceGuTexWrap(GU_REPEAT, GU_REPEAT);

	sceGuColor(0xffffffff);
#endif
}

void TVideoRenderer::FreeTextures()
{
	FTexture.Free();
}

void TVideoRenderer::TextureMode(const u32& parBlendMode, const u32& parColorMode)
{
#ifdef COMPILE_PSP
	sceGuTexFunc(parBlendMode, parColorMode);
#endif
}

#ifdef COMPILE_PSP
void TVideoRenderer::LoadMatrix(ScePspFMatrix4* parMatrix)
{
	LAssert(parMatrix);
	sceGumLoadMatrix(parMatrix);
}
#endif

void TVideoRenderer::PushMatrix()
{
#ifdef COMPILE_PSP
	sceGumPushMatrix();
#endif
}

void TVideoRenderer::PopMatrix()
{
#ifdef COMPILE_PSP
	sceGumPopMatrix();
#endif
}

void TVideoRenderer::LoadIdentity()
{
#ifdef COMPILE_PSP
	sceGumLoadIdentity();
#endif
}

void TVideoRenderer::Scale(const vector3df& parScale)
{
#ifdef COMPILE_PSP
	ScePspFVector3 locScale = { parScale.X, parScale.Y, parScale.Z };

	sceGumScale(&locScale);
#endif
}

void TVideoRenderer::Translate(const vector3df& parTranslation)
{
#ifdef COMPILE_PSP
	ScePspFVector3 locPos = { parTranslation.X, parTranslation.Y, parTranslation.Z };

	sceGumTranslate(&locPos);
#endif
}

void TVideoRenderer::Rotate(const vector3df& parRotation)
{
#ifdef COMPILE_PSP
	ScePspFVector3 locRot = { parRotation.X * DEG_TO_RAD, parRotation.Y * DEG_TO_RAD, parRotation.Z * DEG_TO_RAD };

	sceGumRotateXYZ(&locRot);
#endif
}

void TVideoRenderer::RotateOnDirection(const vector3df& parDirection)
{
#ifdef COMPILE_PSP
	ScePspFMatrix4 locMatrix =
	{{parDirection.X, -parDirection.Z, 0, 0},
	{parDirection.Z, parDirection.X, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}};
	
	sceGumMultMatrix(&locMatrix);
#endif
}

void TVideoRenderer::End3DScene(bool parWithSwapping)
{
#ifdef COMPILE_PSP
	// Treat display list
	sceGuFinish();
	sceGuSync(0, 0);

	// Swap buffers
	sceDisplayWaitVblankStart();
	if(parWithSwapping)
		sceGuSwapBuffers();
#endif
}

void TVideoRenderer::DrawLine(const vector3df& parStart, const vector3df& parEnd, const TColor& parColor)
{
#ifdef COMPILE_PSP
	TVertex3DC* locVertexList = (TVertex3DC*)sceGuGetMemory(2 * sizeof(TVertex3DC));

	sceGuDisable(GU_LIGHTING);	
	sceGuDisable(GU_TEXTURE_2D);

	// Set top left vertex
	locVertexList[0].Color = parColor;
	locVertexList[0].X = parStart.X;
	locVertexList[0].Y = parStart.Y;
	locVertexList[0].Z = parStart.Z;

	// Set top right vertex
	locVertexList[1].Color = parColor;
	locVertexList[1].X = parEnd.X;
	locVertexList[1].Y = parEnd.Y;
	locVertexList[1].Z = parEnd.Z;

	DrawArrayList(locVertexList, 2, GU_TEXTURE_32BITF|GU_COLOR_8888|GU_NORMAL_32BITF|GU_VERTEX_32BITF|GU_TRANSFORM_3D, GU_LINES);

	sceGuEnable(GU_TEXTURE_2D);
#ifdef WITH_LIGHTS
	sceGuEnable(GU_LIGHTING);
#endif
#endif
}

void TVideoRenderer::DrawRectangle3D(const vector3df& parTopLeft, const vector3df& parTopRight, const vector3df& parBottomRight, const TColor& parColor)
{
#ifdef COMPILE_PSP
	TVertex3DC* locVertexList = (TVertex3DC*)sceGuGetMemory(6 * sizeof(TVertex3DC));

	// First Triangle
	// Set top left vertex
	locVertexList[0].U = 0.f;
	locVertexList[0].V = 0.f;
	locVertexList[0].Color = parColor;
	locVertexList[0].X = parTopLeft.X;
	locVertexList[0].Y = parTopLeft.Y;
	locVertexList[0].Z = parTopLeft.Z;

	// Set top right vertex
	locVertexList[1].U = 1.f;
	locVertexList[1].V = 0.f;
	locVertexList[1].Color = parColor;
	locVertexList[1].X = parTopRight.X;
	locVertexList[1].Y = parTopRight.Y;
	locVertexList[1].Z = parTopRight.Z;

	// Set bottom right vertex
	locVertexList[2].U = 1.f;
	locVertexList[2].V = 1.f;
	locVertexList[2].Color = parColor;
	locVertexList[2].X = parBottomRight.X;
	locVertexList[2].Y = parBottomRight.Y;
	locVertexList[2].Z = parBottomRight.Z;

	// Second Triangle
	// Set bottom right vertex
	locVertexList[3].U = 1.f;
	locVertexList[3].V = 1.f;
	locVertexList[3].Color = parColor;
	locVertexList[3].X = parBottomRight.X;
	locVertexList[3].Y = parBottomRight.Y;
	locVertexList[3].Z = parBottomRight.Z;

	// Set bottom left vertex
	locVertexList[4].U = 0.f;
	locVertexList[4].V = 1.f;
	locVertexList[4].Color = parColor;
	locVertexList[4].X = parTopLeft.X;
	locVertexList[4].Y = parBottomRight.Y;
	locVertexList[4].Z = parBottomRight.Z;

	// Set top left vertex
	locVertexList[5].U = 0.f;
	locVertexList[5].V = 0.f;
	locVertexList[5].Color = parColor;
	locVertexList[5].X = parTopLeft.X;
	locVertexList[5].Y = parTopLeft.Y;
	locVertexList[5].Z = parTopLeft.Z;

	DrawArrayList(locVertexList, 6, GU_TEXTURE_32BITF|GU_COLOR_8888|GU_NORMAL_32BITF|GU_VERTEX_32BITF|GU_TRANSFORM_3D);
#endif
}

void TVideoRenderer::DrawRectangle(const p2Df& parTopLeft, const p2Df& parBottomRight, const TColor& parColor, const u32& parAxis)
{
#ifdef COMPILE_PSP
	TVertex3DC* locVertexList = (TVertex3DC*)sceGuGetMemory(5 * sizeof(TVertex3DC));

	sceGuDisable(GU_LIGHTING);	
	sceGuDisable(GU_TEXTURE_2D);

	// Set top left vertex
	locVertexList[0].U = 0.f;
	locVertexList[0].V = 0.f;
	locVertexList[0].Color = parColor;
	locVertexList[0].X = parTopLeft.X;
	locVertexList[0].Y = 0.f;
	locVertexList[0].Z = parTopLeft.Y;

	// Set top right vertex
	locVertexList[1].U = 1.f;
	locVertexList[1].V = 0.f;
	locVertexList[1].Color = parColor;
	locVertexList[1].X = parBottomRight.X;
	locVertexList[1].Y = 0.f;
	locVertexList[1].Z = parTopLeft.Y;

	// Set bottom right vertex
	locVertexList[2].U = 1.f;
	locVertexList[2].V = 1.f;
	locVertexList[2].Color = parColor;
	locVertexList[2].X = parBottomRight.X;
	locVertexList[2].Y = 0.f;
	locVertexList[2].Z = parBottomRight.Y;

	// Set bottom left vertex
	locVertexList[3].U = 1.f;
	locVertexList[3].V = 1.f;
	locVertexList[3].Color = parColor;
	locVertexList[3].X = parTopLeft.X;
	locVertexList[3].Y = 0.f;
	locVertexList[3].Z = parBottomRight.Y;

	// Set top left vertex
	locVertexList[4].U = 0.f;
	locVertexList[4].V = 1.f;
	locVertexList[4].Color = parColor;
	locVertexList[4].X = parTopLeft.X;
	locVertexList[4].Y = 0.f;
	locVertexList[4].Z = parTopLeft.Y;

	DrawArrayList(locVertexList, 5, GU_TEXTURE_32BITF|GU_COLOR_8888|GU_NORMAL_32BITF|GU_VERTEX_32BITF|GU_TRANSFORM_3D, GU_LINE_STRIP);

	sceGuEnable(GU_TEXTURE_2D);
#ifdef WITH_LIGHTS
	sceGuEnable(GU_LIGHTING);
#endif
#endif
}

void TVideoRenderer::DrawRectangle(const bb2Df& parBBox, const TColor& parColor)
{
#ifdef COMPILE_PSP
	TVertex3DC* locVertexList = (TVertex3DC*)sceGuGetMemory(5 * sizeof(TVertex3DC));

	sceGuDisable(GU_LIGHTING);	
	sceGuDisable(GU_TEXTURE_2D);

	// TO DO : See if its necesary to add - on parameters

	// Set top left vertex
	locVertexList[0].U = 0.f;
	locVertexList[0].V = 0.f;
	locVertexList[0].Color = parColor;
	locVertexList[0].X = parBBox.GetLeft();
	locVertexList[0].Y = 0.f;
	locVertexList[0].Z = parBBox.GetTop();
	//locVertexList[0].X = parBBox.GetTop();
	//locVertexList[0].Z = parBBox.GetLeft();

	// Set top right vertex
	locVertexList[1].U = 1.f;
	locVertexList[1].V = 0.f;
	locVertexList[1].Color = parColor;
	locVertexList[1].X = parBBox.GetRight();
	locVertexList[1].Y = 0.f;
	locVertexList[1].Z = parBBox.GetTop();
	//locVertexList[1].X = parBBox.GetTop();
	//locVertexList[1].Z = parBBox.GetRight();

	// Set bottom right vertex
	locVertexList[2].U = 1.f;
	locVertexList[2].V = 1.f;
	locVertexList[2].Color = parColor;
	locVertexList[2].X = parBBox.GetRight();
	locVertexList[2].Y = 0.f;
	locVertexList[2].Z = parBBox.GetBottom();
	//locVertexList[2].X = parBBox.GetBottom();
	//locVertexList[2].Z = parBBox.GetRight();

	// Set bottom left vertex
	locVertexList[3].U = 1.f;
	locVertexList[3].V = 1.f;
	locVertexList[3].Color = parColor;
	locVertexList[3].X = parBBox.GetLeft();
	locVertexList[3].Y = 0.f;
	locVertexList[3].Z = parBBox.GetBottom();
	//locVertexList[3].X = parBBox.GetBottom();
	//locVertexList[3].Z = parBBox.GetLeft();

	// Set top left vertex
	locVertexList[4].U = 0.f;
	locVertexList[4].V = 1.f;
	locVertexList[4].Color = parColor;
	locVertexList[4].X = parBBox.GetLeft();
	locVertexList[4].Y = 0.f;
	locVertexList[4].Z = parBBox.GetTop();
	//locVertexList[4].X = parBBox.GetTop();
	//locVertexList[4].Z = parBBox.GetLeft();

	DrawArrayList(locVertexList, 5, GU_TEXTURE_32BITF|GU_COLOR_8888|GU_NORMAL_32BITF|GU_VERTEX_32BITF|GU_TRANSFORM_3D, GU_LINE_STRIP);

	sceGuEnable(GU_TEXTURE_2D);
#ifdef WITH_LIGHTS
	sceGuEnable(GU_LIGHTING);
#endif
#endif
}

void TVideoRenderer::DrawRepere(const f32& parLength, const f32& parThickness)
{	
	TVertex3DC* locVertexList = (TVertex3DC*)sceGuGetMemory(6 * sizeof(TVertex3DC));

	sceGuDisable(GU_LIGHTING);	
	sceGuDisable(GU_TEXTURE_2D);

	// Set x axis
	locVertexList[0].Color = TColor(255, 255, 0, 0);
	locVertexList[0].X = 0.f;
	locVertexList[0].Y = 0.f;
	locVertexList[0].Z = 0.f;

	locVertexList[1].Color = TColor(255, 255, 0, 0);
	locVertexList[1].X = parLength;
	locVertexList[1].Y = 0.f;
	locVertexList[1].Z = 0.f;

	// Set y axis
	locVertexList[2].Color = TColor(255, 0, 255, 0);
	locVertexList[2].X = 0.f;
	locVertexList[2].Y = 0.f;
	locVertexList[2].Z = 0.f;

	locVertexList[3].Color = TColor(255, 0, 255, 0);
	locVertexList[3].X = 0.f;
	locVertexList[3].Y = parLength;
	locVertexList[3].Z = 0.f;

	// Set z axis
	locVertexList[4].Color = TColor(255, 0, 0, 255);
	locVertexList[4].X = 0.f;
	locVertexList[4].Y = 0.f;
	locVertexList[4].Z = 0.f;

	locVertexList[5].Color = TColor(255, 0, 0, 255);
	locVertexList[5].X = 0.f;
	locVertexList[5].Y = 0.f;
	locVertexList[5].Z = parLength;

	DrawArrayList(locVertexList, 6, GU_TEXTURE_32BITF|GU_COLOR_8888|GU_NORMAL_32BITF|GU_VERTEX_32BITF|GU_TRANSFORM_3D, GU_LINES);

	sceGuEnable(GU_TEXTURE_2D);
#ifdef WITH_LIGHTS
	sceGuEnable(GU_LIGHTING);
#endif
}

void TVideoRenderer::DrawCube(const p2Df& parTopLeft, const f32& parRadius, const TColor& parColor)
{

}

void TVideoRenderer::DrawArrayList(const void* parVertexList, const u32& parVertexCount, const u32& parFormat, const s32& parPrim)
{
#ifdef COMPILE_PSP
	sceGumDrawArray(parPrim, parFormat, parVertexCount, 0, parVertexList);
#endif
}

void TVideoRenderer::DrawArrayList(const void* parVertexList, const void* parIndexList, const u32& parIndexCount, const u32& parFormat, const s32& parPrim)
{
#ifdef COMPILE_PSP
	sceGumDrawArray(parPrim, parFormat, parIndexCount, parIndexList, parVertexList);
#endif
}

} // namespace video
} // namespace engine
} // namespace psp
