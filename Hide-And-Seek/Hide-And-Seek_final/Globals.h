#ifndef GLOBALS_H
#define GLOBALS_H

#include "config.h"
#include <vector>

namespace psp {

class TSingletonManager;
class TMemoryDomain;
typedef std::vector<TMemoryDomain*> TDomainVect;

extern TSingletonManager	GSingletonManager;
extern TDomainVect			GDomainList;

} // psp namespace

#endif
