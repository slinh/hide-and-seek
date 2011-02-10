#include "Common.h"
#include "Page.h"
#include "Location.h"

namespace psp { namespace engine { namespace gui {

TPage::TPage()
	: FIdPage(0),
	FBackground(TLocation())
{}

TPage::TPage(u8 parIdPage)
	: FIdPage(parIdPage),
	FBackground(TLocation())
{}

TPage::~TPage()
{}

} // gui namespace
} // engine namespace
} // psp namespace
