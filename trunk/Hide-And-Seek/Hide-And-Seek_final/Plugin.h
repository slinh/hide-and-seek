#ifndef PLUGIN_H
#define PLUGIN_H

#include "config.h"

namespace psp { 

namespace core {
	class stringc;
}
	
namespace meta {

template<class T>
class TPlugin
{
public:
    TPlugin();
    ~TPlugin();

    T* Load(const core::stringc& parFilename);
/*
private:
    typedef T* (*PtrFunc)();
    HMODULE m_Library;
//*/
};

} // psp namespace
} // meta namespace

#endif
