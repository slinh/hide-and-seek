#include "Common.h"
#include "GuiInGame.h"
#include <pspgum.h>

namespace psp { namespace engine { namespace gui {

TGuiInGame::TGuiInGame()
{
	  // setup IntraFont
	  intraFontInit();
	  FFont = intraFontLoad("flash0:/font/ltn8.pgf", INTRAFONT_CACHE_MED);
}

TGuiInGame::~TGuiInGame()
{
	intraFontUnload(FFont);
	intraFontShutdown();
}

//InitGfxDraw
void TGuiInGame::InitGfxDraw()
{
#ifdef COMPILE_PSP
	sceGuDisable(GU_LIGHTING);
	sceGuEnable(GU_BLEND);

	sceGuDisable(GU_DEPTH_TEST);
	sceGuDisable(GU_ALPHA_TEST);

	sceGuBlendFunc(GU_ADD, GU_SRC_ALPHA, GU_ONE_MINUS_SRC_ALPHA, 0, 0);
	sceGuPixelMask(0x00000000);
#endif
}

void TGuiInGame::SetStyle(const f32& parSize, const video::TColor& parTextColor, const video::TColor& parBackColor, const s32& parAlignment)
{
#ifdef COMPILE_PSP
	intraFontSetStyle(FFont, parSize, parTextColor.FColor, parBackColor.FColor, parAlignment);
#endif
}

void TGuiInGame::DrawMessage(const c8* parMessage, const f32& parX, const f32& parY)
{
#ifdef COMPILE_PSP
	intraFontPrintf(FFont, parX, parY, "%s", parMessage);
#endif
}

void TGuiInGame::DrawMessage(const core::stringc& parMessage, const f32& parX, const f32& parY)
{
#ifdef COMPILE_PSP
	intraFontPrintf(FFont, parX, parY, "%s", parMessage.c_str());
#endif
}

void TGuiInGame::EndGfxDraw()
{
#ifdef COMPILE_PSP

#ifdef WITH_LIGHTS
	sceGuEnable(GU_LIGHTING);
#endif
#ifndef WITH_BLEND
	sceGuDisable(GU_BLEND);
#endif

	sceGuEnable(GU_DEPTH_TEST);
#endif
}


} // gui namespace
} // engine namespace
} // psp namespace