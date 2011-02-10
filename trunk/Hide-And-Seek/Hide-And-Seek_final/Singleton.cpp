#include <typeinfo>

#include "Singleton.h"
#include "Alloc.h"
#include "Globals.h"
#include "Assert.h"
#ifdef DEBUG
#include "LoggerTypes.h"
#endif

namespace psp {

//////////////////////////////////
//		TSingletonManager	   //
////////////////////////////////
TSingletonManager::TSingletonManager()
{}

TSingletonManager::~TSingletonManager()
{
	// Leak file output
	//std::ofstream file("Log/output.log", std::ios_base::app);

    while(!FInstances.empty())
    {
        TSingletonBase* currentSingleton = FInstances.back();

        // If an instance is hand created - its better to release by yourself
        if (currentSingleton->WasAutoCreated())
		{
            delete currentSingleton;
		}
        else
        {
#ifndef COMPILE_FINAL_RELEASE
            static const size_t BUFFER_SIZE = 4096;
            char msg[BUFFER_SIZE];
#if defined(COMPILE_PC) && (defined(WIN32) || defined(WIN64))
			if((size_t)sprintf_s(msg, BUFFER_SIZE, "Leak for singleton <%s>!\n", typeid(*currentSingleton).name()) < BUFFER_SIZE)
#else
			if((size_t)sprintf(msg, "Leak for singleton <%s>!\n", typeid(*currentSingleton).name()) < BUFFER_SIZE)
#endif
            {
				//file << msg;
            }
#endif
			FInstances.pop_back();
        }
    }

	//file.close();
}
//-----------------------------------------------------------------------------
void TSingletonManager::RegisterInstance(TSingletonBase* parInstance)
{
    LAssert(parInstance);
    GSingletonManager.FInstances.push_back(parInstance);
}
//-----------------------------------------------------------------------------
void TSingletonManager::DeleteInstance(TSingletonBase* parInstance)
{
    LAssert(parInstance);
    std::vector<TSingletonBase*>::iterator findPos =  std::find(GSingletonManager.FInstances.begin(), GSingletonManager.FInstances.end(), parInstance);

    LAssert(findPos != GSingletonManager.FInstances.end());
    GSingletonManager.FInstances.erase(findPos);
}

} // psp namespace
