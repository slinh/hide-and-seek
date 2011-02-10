#include "Common.h"
#include "Plugin.h"

namespace psp { namespace meta {

template<class T>
TPlugin<T>::TPlugin()
{
	LAssertNotImplemented();
}

template<class T>
TPlugin<T>::~TPlugin()
{
	LAssertNotImplemented();
}

template<class T>
T* TPlugin<T>::Load(const core::stringc& parFilename)
{
	LAssertNotImplemented();
	return NULL;
}

} // psp namespace
} // meta namespace
