#ifndef SINGLETON_H
#define SINGLETON_H

#include "Assert.h"

#include <vector>
#include <algorithm>

namespace psp {

class TSingletonBase;

//////////////////////////////////
//		TSingletonManager	   //
////////////////////////////////
class TSingletonManager
{
private:
    std::vector<TSingletonBase*> FInstances;
public:
				TSingletonManager();
				~TSingletonManager();

    static void RegisterInstance(TSingletonBase* parInstance);
    static void DeleteInstance(TSingletonBase* parInstance);
};

//////////////////////////////////
//		TSingletonBase  	   //
////////////////////////////////

class TSingletonBase
{
private:
	TSingletonBase(const TSingletonBase&) {}
	TSingletonBase& operator =(const TSingletonBase&);

protected:
    bool FWasAutoCreated;
    TSingletonBase() : FWasAutoCreated(false) {}

public:
    virtual ~TSingletonBase() {};
    bool WasAutoCreated() const {return FWasAutoCreated;}
};

//////////////////////////////////
//		TSingleton       	   //
////////////////////////////////

template<class T, bool parAuto = false>
class TSingleton : public TSingletonBase
{
	friend class TSingletonManager;
public:
	TSingleton(T* parInstance)
    {
        LAssert(FInstance == NULL);
        FInstance = parInstance;
        TSingletonManager::RegisterInstance(FInstance);
    }

	static T* CreateInstance()
    {
        LAssert(FInstance == NULL);
        T* locInstance = new T();
        return locInstance;
    }

	static void SetInstance(T* parInstance)
	{
		LAssert(parInstance);
		LAssert(!FInstance);
		FInstance = parInstance;
		TSingletonManager::RegisterInstance(FInstance);
	}

    static T& Instance()
	{
		LAssert(FInstance);
		return *FInstance;
	}

	static T* InstancePtr()
	{
		LAssert(FInstance);
		return FInstance;
	}

    static void Destroy()
	{
		LAssert(FInstance);
		delete FInstance;
		FInstance = NULL;
	}

	static bool HasInstance() {return FInstance != NULL;}

protected:
    virtual ~TSingleton()
    {
        TSingletonManager::DeleteInstance(FInstance);
        FInstance = NULL;
    };

private:
    static T* FInstance;
protected:
	TSingleton() {}
};

template<class T>
class TSingleton<T, true> : public TSingletonBase
{
	friend class TSingletonManager;
public:
	TSingleton(T* parInstance)
    {
        LAssert(FInstance == NULL);
        FInstance = parInstance;
        TSingletonManager::RegisterInstance(FInstance);
    }

	static T* CreateInstance()
    {
        LAssert(FInstance == NULL);
        T* locInstance = new T();
		locInstance->FWasAutoCreated = true;
        return locInstance;
    }

	static void SetInstance(T* parInstance)
	{
		LAssert(parInstance);
		LAssert(!FInstance);
		FInstance = parInstance;
		TSingletonManager::RegisterInstance(FInstance);
	}

    static T& Instance()
	{
		LAssert(FInstance);
		return *FInstance;
	}

	static T* InstancePtr()
	{
		LAssert(FInstance);
		return FInstance;
	}

    static void Destroy()
	{
		LAssert(FInstance);
		delete FInstance;
		FInstance = NULL;
	}

	static bool HasInstance() {return FInstance != NULL;}

protected:
    ~TSingleton()
    {
        TSingletonManager::DeleteInstance(FInstance);
        FInstance = NULL;
    };

private:
    static T* FInstance;
protected:
	TSingleton() {}
};

// Static parameters
template <class T, bool parAuto> T* psp::TSingleton<T, parAuto>::FInstance;
template <class T> T* psp::TSingleton<T, true>::FInstance;

//////////////////////////////////
//		TSingletonVirtual 	   //
////////////////////////////////

template<class T, bool parAuto = false>
class TSingletonVirtual : public TSingletonBase
{
	friend class TSingletonManager;
public:
	static void SetInstance(T* parInstance)
	{
		LAssert(parInstance);
		LAssert(!FInstance);
		FInstance = parInstance;
		TSingletonManager::RegisterInstance(FInstance);
	}

    static T& Instance()
	{
		LAssert(FInstance);
		return *FInstance;
	}

	static T* InstancePtr()
	{
		LAssert(FInstance);
		return FInstance;
	}

    static void Destroy()
	{
		LAssert(FInstance);
		delete FInstance;
		FInstance = NULL;
	}

	static bool HasInstance() {return FInstance != NULL;}

protected:
    virtual ~TSingletonVirtual()
    {
        TSingletonManager::DeleteInstance(FInstance);
        FInstance = NULL;
    };

private:
    static T* FInstance;
protected:
	TSingletonVirtual() {}
};

template<class T>
class TSingletonVirtual<T, true> : public TSingletonBase
{
	friend class TSingletonManager;
public:
	static void SetInstance(T* parInstance)
	{
		LAssert(parInstance);
		LAssert(!FInstance);
		FInstance = parInstance;
		FInstance->FWasAutoCreated = true;
		TSingletonManager::RegisterInstance(FInstance);
	}

    static T& Instance()
	{
		LAssert(FInstance);
		return *FInstance;
	}

	static T* InstancePtr()
	{
		LAssert(FInstance);
		return FInstance;
	}

    static void Destroy()
	{
		LAssert(FInstance);
		delete FInstance;
		FInstance = NULL;
	}

	static bool HasInstance() {return FInstance != NULL;}

protected:
    ~TSingletonVirtual()
    {
        TSingletonManager::DeleteInstance(FInstance);
        FInstance = NULL;
    };

private:
    static T* FInstance;
protected:
	TSingletonVirtual() {}
};

// Static parameters
template <class T, bool parAuto> T* psp::TSingletonVirtual<T, parAuto>::FInstance;
template <class T> T* psp::TSingletonVirtual<T, true>::FInstance;

#define SINGLETONREGINSTANCE SetInstance(this);

} // namespace psp

#endif
