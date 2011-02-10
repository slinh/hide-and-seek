#include "GenericVirtualCallback.h"

namespace psp { namespace engine {

//TNamedCallBackManager::TNamedCallBackManager()
//{
//	SINGLETONREGINSTANCE
//}
//
//TNamedCallBackManager::~TNamedCallBackManager()
//{
//	Free();
//}
//
//void TNamedCallBackManager::Free()
//{
//
//}
//
//void TVirtualNamedCallback::RegisterSelf()
//{
//	TNamedCallBackManager & locCallbackManager = TNamedCallBackManager::Instance();
//
//	// iterator
//	std::map<core::stringc, TVirtualNamedCallback*>::const_iterator
//	  mit((locCallbackManager.FCallbacks).find(this->FName)),
//	  mend((locCallbackManager.FCallbacks).end());
//
//	// if current callback hasn't been registered yet
//	if(mit == mend){
//
//		// insert into the callbackmanager
//		locCallbackManager.FCallbacks.insert(std::pair<core::stringc, TVirtualNamedCallback*>(this->FName, this));
//	}
//
//}
//
//void TVirtualNamedCallback::UnregisterSelf()
//{
//	TNamedCallBackManager & locCallbackManager = TNamedCallBackManager::Instance();
//
//	// iterator
//	std::map<core::stringc, TVirtualNamedCallback*>::const_iterator
//	  mit((locCallbackManager.FCallbacks).find(this->FName)),
//	  mend((locCallbackManager.FCallbacks).end());
//
//	// if current callback has been registered
//	if(mit != mend){
//
//		// delete from the callbackmanager
//		locCallbackManager.FCallbacks.erase(this->FName);
//	}
//}


} // engine namespace
} // psp namespace