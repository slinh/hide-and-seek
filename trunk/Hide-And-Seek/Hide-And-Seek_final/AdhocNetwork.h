#ifndef ADHOC_NETWORK_H
#define ADHOC_NETWORK_H

#include "config.h"
#include "Singleton.h"
#include "Logger.h"

#ifdef COMPILE_PSP
#include <pspctrl.h>
#endif

#ifdef COMPILE_PC
#include <iostream>
#endif

namespace psp { namespace engine { namespace net {

class AdhocNetwork : public TSingleton<AdhocNetwork, true>
{
public :
    AdhocNetwork();
	~AdhocNetwork();

	void Init();
	void Free();

#ifdef COMPILE_PSP
	void Update(SceCtrlData parPad);
#endif

	void RequestConnection();
	void WaitForConnection();

private :
	
};

} // net namespace
} // engine namespace
} // psp namespace

#endif // ADHOC_NETWORK_H
