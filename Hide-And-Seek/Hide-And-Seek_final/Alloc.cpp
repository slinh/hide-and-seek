#include "Alloc.h"

namespace psp { 

TDomainVect		TMemoryDomain::FTempDomainList;

namespace Memory {
	
	LOG_DOMAIN(NoDomain)
	LOG_DOMAIN(GameEngine)
	LOG_DOMAIN(Sound)
	LOG_DOMAIN(Video)
	LOG_DOMAIN(Video_Light)
	LOG_DOMAIN(MD2)
	LOG_DOMAIN(GUI)
	LOG_DOMAIN(IA)
	LOG_DOMAIN(Map)
	LOG_DOMAIN(Game)

#ifdef COMPILE_TOOLS
	LOG_DOMAIN(Tools)
#endif

} // Memory namespace

	TMemoryDomain::TMemoryDomain(const c8* parName): 
	FBytes(0), FName(parName)
	{
		FTempDomainList.push_back(this);
	}

	void* TMemoryDomain::Allocate(size_t parSize, bool parIsArray, const char* parFile, int parLine)
	{
		// Allocate memory
		void* locPtr = malloc(parSize);

		// Store allocation informations
		TMemoryBlock locBlock(parSize, parIsArray, parFile, parLine);
		FBytes  += (long)parSize;
		FBlocksMap[locPtr] = locBlock;

		return locPtr;
	}

	void TMemoryDomain::Release(void* parPtr)
	{
		// Looking for pointer
		TBlockMap::iterator locIt = FBlocksMap.find(parPtr);

		// If it is not allocated in this specific domain
		if(locIt == FBlocksMap.end())
		{
			free(parPtr);
			return;
		}

		FBytes  -= (long)((*locIt).second.FSize);
		FBlocksMap.erase(locIt);

		free(parPtr);
	}

	void TMemoryDomain::ReportLeaks()
	{
		// Use default logger
		LAssert(HasLoggerInstance());

		LOGC_MEM("Leaks Report on %d domains: ", GDomainList.size());
		for (TDomainVect::iterator locMemoryDomain = GDomainList.begin(); locMemoryDomain != GDomainList.end(); ++locMemoryDomain)
		{
			size_t locTotalSize = 0;
			LOGC_MEM("\n-> Domain %s :\n", (*locMemoryDomain)->Name());
			for (TBlockMap::iterator i = (*locMemoryDomain)->FBlocksMap.begin(); i != (*locMemoryDomain)->FBlocksMap.end(); ++i)
			{
				// Adding in total size
				locTotalSize += i->second.FSize;

				// Writing information of current block in default logger
				LOGC_MEM(" %p | %d bytes | %s(%d)\n", i->first, static_cast<int>(i->second.FSize), i->second.FFile, i->second.FLine);

				// free(i->first);
			}

			// Writing leaks addition
			LOGC_MEM("\n-- %d unallocated blocks of size %d bytes\n", static_cast<int>((*locMemoryDomain)->FBlocksMap.size()), locTotalSize);
		}
		LOGC_MEM("\n");
	}

// -----------------------------------------------------
//      Alloc/Release functions
// -----------------------------------------------------

void* malloc_for_new(size_t parSize, psp::TMemoryDomain& parDomain, const c8* parFile, const u32& parLine)
{
	void* locResult = NULL;
	static const size_t OVERHEAD = OVERHEAD_DOMAIN_HEADER;

	psp::TMemoryBlockHeader locHeader;

	locResult = parDomain.Allocate(parSize + OVERHEAD, false, parFile, parLine);

	// We store pointer value to compare our allocations with others
	locHeader.FCheckPtr = (size_t)locResult;
	locHeader.FDomain = &parDomain;
	// ----------------------------------------------------------------------------- 
	*((psp::TMemoryBlockHeader*)locResult) = locHeader;

	locResult = (reinterpret_cast<c8*>(locResult) + OVERHEAD);
	// -----------------------------------------------------------------------------
	return locResult;
}

void free_for_delete(void* parPtr)
{
	if(parPtr == NULL)
		return;

	psp::TMemoryBlockHeader* locHeader = HEADER_FROM_MEMORY_BLOCK(parPtr);
	
	if((size_t)locHeader == locHeader->FCheckPtr)
		(locHeader->FDomain)->Release(locHeader);
	else
		free(parPtr);
}

} // psp namespace

// Allocation functions overriding
/*
void* operator new(size_t parSize)
{
	return psp::malloc_for_new(parSize, psp::Memory::TMemoryNoDomainDomain::Domain, "Unknown file", 0);
}

void* operator new[](size_t parSize)
{
	return psp::malloc_for_new(parSize, psp::Memory::TMemoryNoDomainDomain::Domain, "Unknown file", 0);
}
//*/
void* operator new(size_t parSize, psp::TMemoryDomain& parDomain, const char* parFile, const int& parLine) 
{
	return psp::malloc_for_new(parSize, parDomain, parFile, parLine);
}

void* operator new[](size_t parSize, psp::TMemoryDomain& parDomain, const char* parFile, const int& parLine) 
{
	return psp::malloc_for_new(parSize, parDomain, parFile, parLine);
}

// Releasing functions overriding

void operator delete(void* parPtr)
{
	psp::free_for_delete(parPtr);
}
/*
void operator delete[](void* parPtr)
{
	psp::free_for_delete(parPtr);
}
//*/

// delete called for new(psp::TMemoryDomain, const char*, cp,st s32&) fail
void operator delete(void* parPtr, psp::TMemoryDomain& parDomain, const char* parFile, const s32& parLine)
{
	LOGC_MEM("new failed in %s(%d)\n", parFile, parLine);

	parDomain.Release(parPtr);
}

void operator delete[](void* parPtr, psp::TMemoryDomain& parDomain, const char* parFile, const s32& parLine) 
{
	LOGC_MEM("new failed in %s(%d)\n", parFile, parLine);

	parDomain.Release(parPtr);
}

