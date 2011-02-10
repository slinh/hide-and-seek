#ifndef TGENERICVIRTUALCALLBACK_H
#define TGENERICVIRTUALCALLBACK_H

#include "config.h"
#include "34LettresEngine.h"

#ifndef COMPILE_PSP
#include <iostream>
#endif

namespace psp { namespace engine {

// ---------------------------------
//          TCallbackItem
// ---------------------------------

class TVirtualNamedCallback
{
public:
    virtual void VirtualCall() = 0;

    template < typename T, void (T::*_CallMethod)() >
    static TVirtualNamedCallback* Make(const core::stringc& parName, T* parObjectToCall);

    template < typename T >
    static TVirtualNamedCallback* Make(const core::stringc& parName, T* parObjectToCall);

    TVirtualNamedCallback(const core::stringc& parName);
    virtual ~TVirtualNamedCallback();
	
private:
    void RegisterSelf();
    void UnregisterSelf();

    core::stringc FName;
};

// ---------------------------------
//             TCallbackItem
// ---------------------------------

template<typename T, void (T::*_CallMethod)()>
class TNamedCallbackItem : public TVirtualNamedCallback
{
public:
    TNamedCallbackItem(const core::stringc& parName, T* parObjectToCall) :
    TVirtualNamedCallback(parName), FObjectToCall(parObjectToCall)
    {}

    virtual ~TNamedCallbackItem()
    {}

    virtual void VirtualCall() 
    {
        (FObjectToCall->*_CallMethod)();
    }

private:	
    T* FObjectToCall;
};

// ------------------------------------------------------------------------------
//                       TNamedCallBackManager
// ------------------------------------------------------------------------------
class TNamedCallBackManager : public TSingleton<TNamedCallBackManager>
{
private:
    std::map<core::stringc, TVirtualNamedCallback*> FCallbacks;
    friend class TVirtualNamedCallback;
public:
    TNamedCallBackManager();
    virtual ~TNamedCallBackManager();
	void Free();
    TVirtualNamedCallback* GetCallbackIFP(const core::stringc& parCallbackName);
    void Call(const core::stringc& parCallbackName);

    bool Contains(const core::stringc& parCallbackName) const;
};

} // engine namespace
} // psp namespace

#endif 
