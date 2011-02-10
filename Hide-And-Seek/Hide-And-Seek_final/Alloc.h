#ifndef ALLOC_H
#define ALLOC_H

#include "config.h"
#include "Globals.h"
#include "Logger.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>

// Allocation config
#define ROUND_TO_NEXT_4(v)   ((((psp::ptr_t)(v)) + 3) &  ~3)
#define ROUND_TO_NEXT_16(v)  ((((psp::ptr_t)(v)) + 15) & ~15)
#define ROUND_TO_NEXT_32(v)  ((((psp::ptr_t)(v)) + 31) & ~31)
#define ROUND_TO_NEXT_64(v)  ((((psp::ptr_t)(v)) + 63) & ~63)
#define ROUND_TO_NEXT_128(v) ((((psp::ptr_t)(v)) + 127) & ~127)

#define OVERHEAD_DOMAIN_HEADER			ROUND_TO_NEXT_16(sizeof(psp::TMemoryBlockHeader))
#define HEADER_FROM_MEMORY_BLOCK(PTR)   (reinterpret_cast< psp::TMemoryBlockHeader* >(reinterpret_cast< char* >(PTR) - OVERHEAD_DOMAIN_HEADER))
#define MEMORY_BLOCK_FROM_HEADER(PTR)   (reinterpret_cast< void* >(reinterpret_cast< char* >(PTR) + OVERHEAD_DOMAIN_HEADER))

namespace psp {

	class TMemoryDomain;

	struct TMemoryBlockHeader
	{
		size_t			FCheckPtr;
		TMemoryDomain*	FDomain;
	};

    struct TMemoryBlock
    {
        TMemoryBlock():FSize(0), FIsArray(false), FLine(-1)
        {
			FFile[0] = '\0';
		}

        TMemoryBlock(size_t parSize, bool parIsArray, const char* parFile, int& parLine):FSize(parSize), FIsArray(parIsArray), FLine(parLine)
        {
#ifdef COMPILE_PC
			strncpy_s(FFile, SMALL_BUFFER_SIZE, parFile, strlen(parFile));
#elif defined(COMPILE_PSP)
			strncpy(FFile, parFile, SMALL_BUFFER_SIZE);
#endif
		}

        size_t		FSize;
        bool		FIsArray;
		c8			FFile[SMALL_BUFFER_SIZE];
		s32			FLine;
    };

    typedef std::map<void*, TMemoryBlock>		TBlockMap;

    class TMemoryDomain
    {
    public:
        TMemoryDomain(const c8* parName);

		const c8* Name() const {return FName;}

		//! Returns number of blocks allocated in this memory domain
        size_t NbBytes() const {return FBytes;}

		//! Returns number of blocks in this memory domain
        size_t NbBlocks() const {return FBlocksMap.size();}

		//! Allocate some memory
        void* Allocate(size_t parSize, bool parIsArray, const char* parFile, int parLine);

		//! Release allocated memory
        //void Release(void* parPtr, bool parIsArray)
        void Release(void* parPtr);

		static void ReportLeaks();

    private :
        size_t					FBytes;
        const c8*				FName;
        TBlockMap				FBlocksMap;

    public:
		static TDomainVect		FTempDomainList;
    };             

// Macros for domain allocations
#define INITDOMAINMEMORYMANAGER psp::GDomainList = psp::TMemoryDomain::FTempDomainList; \
								psp::TMemoryDomain::FTempDomainList.clear();

#define LOG_DOMAIN(NAME)	TMemoryDomain TMemory ## NAME ## Domain::Domain( #NAME );

#define WITH_DOMAIN(NAME)                                               \
    namespace Memory                                                    \
    {                                                                   \
        struct TMemory ## NAME ## Domain                                \
        {                                                               \
            static TMemoryDomain Domain;                                \
        };                                                              \
    }

#define DOMAIN_FROM_NAME(NAME) ::psp::Memory::TMemory ## NAME ## Domain

#include "DomainList.h"

#define NEW_IN_DOMAIN(NAME) new(DOMAIN_FROM_NAME(NAME)::Domain, __FILE__, __LINE__) 
#define NEW_ NEW_IN_DOMAIN(NoDomain)

#define REPORT_LEAKS psp::TMemoryDomain::ReportLeaks();

// -----------------------------------------------------
//      Alloc/Release functions
// -----------------------------------------------------

// malloc and free
void* malloc_for_new(size_t parSize, psp::TMemoryDomain& parDomain, const c8* parFile, const u32& parLine);
void free_for_delete(void* parPtr);

} // psp namespace

// Overriding of new rustiness
/*
void* operator new(size_t parSize);
void* operator new[](size_t parSize);
//*/
void* operator new(size_t parSize, psp::TMemoryDomain& parDomain, const char* parFile, const int& parLine);
void* operator new[](size_t parSize, psp::TMemoryDomain& parDomain, const char* parFile, const int& parLine);

// Overriding of delete rustiness
void operator delete(void* parPtr);
//void operator delete[](void* parPtr);

void operator delete(void* parPtr, psp::TMemoryDomain& parDomain, const char* parFile, const int& parLine);
void operator delete[](void* parPtr, psp::TMemoryDomain& parDomain, const char* parFile, const int& parLine);

#endif
