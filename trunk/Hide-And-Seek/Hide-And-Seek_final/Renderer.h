#ifndef RENDERER_H
#define RENDERER_H

#include "config.h"
#include "RendererConstants.h"
#include "Point2D.h"
#include "vector3d.h"
#include "TextureItem.h"
#include "BoundingBox2D.h"
#ifdef COMPILE_PSP
#include <psptypes.h>
#endif

using namespace psp::engine::core;

namespace psp { namespace engine { namespace video {

	struct TColor;
	class  TCamera;
	class  TLightManager;

// -----------------------------------------------
//				IRenderer
// -----------------------------------------------

class TVideoRenderer;
struct TVertex3D;

class IRenderer
{
public:
	VIRTUAL_DESTRUCTOR(IRenderer)

	//! Create a new Renderer
	static IRenderer* Make();

	//! Initialize Renderer
	virtual void Initialize3D() = 0;

	// Enable/Disable game states
	virtual void Enable(const u32& parState) = 0;
	virtual void Disable(const u32& parState) = 0;

	//! Call this before start drawing a new 3D scene
	virtual void Begin3DScene(const TCamera& parCamera, const TLightManager& parLightManager) = 0;

	//! Function for flush texture from main RAM to vRAM
	// TODO : it not what it do in reality - texture management dont have to be in Renderer
	virtual void FlushTexture() = 0;
	virtual void FreeTextures() = 0;

	//! define Texture application mode
	virtual void TextureMode(const u32& parBlendMode, const u32& parColorMode) = 0;

#ifdef COMPILE_PSP
	virtual void LoadMatrix(ScePspFMatrix4* parMatrix) = 0;
#endif

	// Push current matrix onto stack
	virtual void PushMatrix() = 0;

	// Pop matrix from stack
	virtual void PopMatrix() = 0;

	// Init current matrix stack
	virtual void LoadIdentity() = 0;

	// Set scale for current matrix
	virtual void Scale(const vector3df& parScale) = 0;

	// Translate current scene of parTranslatioin
	virtual void Translate(const vector3df& parTranslation) = 0;

	// Rotate current scene of parRotation
	virtual void Rotate(const vector3df& parRotation) = 0;

	virtual	void RotateOnDirection(const vector3df& parDirection) = 0;

	//! Call this at end of 3D scene drawing
	virtual void End3DScene(bool parWithSwapping = true) = 0;

	// Draws a line
	virtual void DrawLine(const vector3df& parStart, const vector3df& parEnd, const TColor& parColor) = 0;

	// Draw a rectangle in 3D
	virtual void DrawRectangle3D(const vector3df& parTopLeft, const vector3df& parTopRight, const vector3df& parBottomRight, const TColor& parColor) = 0;

	//! Draws a rectangle
	virtual void DrawRectangle(const p2Df& parTopLeft, const p2Df& parBottomRight, const TColor& parColor, const u32& parAxis = 0) = 0;
	virtual void DrawRectangle(const bb2Df& parBBox, const TColor& parColor) = 0;
#ifdef COMPILE_PSP
	// Draw basic repere of scene
	virtual void DrawRepere(const f32& parLength = LINE_LENGTH, const f32& parThickness = LINE_THICKNESS) = 0;
#endif

	virtual void DrawCube(const p2Df& parTopLeft, const f32& parRadius, const TColor& parColor) = 0;

	//! Draws a arrayLits of triangles
#ifdef COMPILE_PSP
	virtual void DrawArrayList(const void* parVertexList, const u32& parVertexCount, const u32& parFormat, const s32& parPrim = GU_TRIANGLES) = 0;
	virtual void DrawArrayList(const void* parVertexList, const void* parIndexList, const u32& parIndexCount, const u32& parFormat, const s32& parPrim = GU_TRIANGLES) = 0;
#endif
};

// -----------------------------------------------
//				TVideoRenderer
// -----------------------------------------------

class TVideoRenderer : public IRenderer
{
public:
	TVideoRenderer();
	~TVideoRenderer();

	virtual void Initialize3D();

	virtual void Enable(const u32& parState);
	virtual void Disable(const u32& parState);

	virtual void Begin3DScene(const TCamera& parCamera, const TLightManager& parLightManager);

	// TODO : texture loading and management don't have to be in Renderer
	virtual void FlushTexture();
	virtual void FreeTextures();
	virtual void TextureMode(const u32& parBlendMode, const u32& parColorMode);

#ifdef COMPILE_PSP
	virtual void LoadMatrix(ScePspFMatrix4* parMatrix);
#endif

	virtual void PushMatrix();

	virtual void PopMatrix();

	virtual void LoadIdentity();

	virtual void Scale(const vector3df& parScale);

	virtual void Translate(const vector3df& parTranslation);

	virtual void Rotate(const vector3df& parRotation);

	virtual	void RotateOnDirection(const vector3df& parDirection);

	virtual void End3DScene(bool parWithSwapping = true);

	virtual void DrawLine(const vector3df& parStart, const vector3df& parEnd, const TColor& parColor);

	virtual void DrawRectangle3D(const vector3df& parTopLeft, const vector3df& parTopRight, const vector3df& parBottomRight, const TColor& parColor);

	virtual void DrawRectangle(const p2Df& parTopLeft, const p2Df& parBottomRight, const TColor& parColor, const u32& parAxis = 0);
	virtual void DrawRectangle(const bb2Df& parBBox, const TColor& parColor);
#ifdef COMPILE_PSP
	virtual void DrawRepere(const f32& parLength = LINE_LENGTH, const f32& parThickness = LINE_THICKNESS);
#endif
	virtual void DrawCube(const p2Df& parTopLeft, const f32& parRadius, const TColor& parColor);
#ifdef COMPILE_PSP
	virtual void DrawArrayList(const void* parVertexList, const u32& parVertexCount, const u32& parFormat, const s32& parPrim = GU_TRIANGLES);
	virtual void DrawArrayList(const void* parVertexList, const void* parIndexList, const u32& parIndexCount, const u32& parFormat, const s32& parPrim = GU_TRIANGLES);
#endif

private:
#ifdef COMPILE_PSP
	// Buffers list use by pspgu to do rendering
	void* FDrawBuffer;
	void* FDisplayBuffer;
	void* FDepthBuffer;

	u32 __attribute__((aligned(16))) FDisplayList[DISPLAY_LIST_SIZE];
#endif
	TTextureItem FTexture;

	// Forbidden to copy a renderer
	NON_COPYABLE(TVideoRenderer)
};

} // namespace video
} // namespace engine
} // namespace psp

#endif
