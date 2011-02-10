#ifndef GUI_IN_GAME_H
#define GUI_IN_GAME_H

#include "intraFont.h"
#include "RendererConstants.h"
#include "Color.h"

namespace psp { namespace engine { namespace gui {

class TGuiInGame
{
public:
	TGuiInGame();
	~TGuiInGame();

	// To call once per frame to initialize Gfx drawing
	// Must be called after 3D rendering if possible
	void InitGfxDraw();

	void SetStyle(const f32& parSize, const video::TColor& parTextColor, const video::TColor& parBackColor, const s32& parAlignment = INTRAFONT_ALIGN_CENTER);

	void DrawMessage(const c8* parMessage, const f32& parX, const f32& parY);
	void DrawMessage(const core::stringc& parMessage, const f32& parX, const f32& parY);

	void EndGfxDraw();
private:
	intraFont* FFont;
};

} // gui namespace
} // engine namespace
} // psp namespace
#endif