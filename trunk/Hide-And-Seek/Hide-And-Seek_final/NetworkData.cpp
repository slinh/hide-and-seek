#include "config.h"
#include "NetworkData.h" 
#include "Game.h"
#if defined(DEBUG) && defined(COMPILE_PC)
#include <string>
#include <sstream>
#include <iostream>
#endif
#include <cstdlib>

#ifdef COMPILE_PSP
# include <oslib/oslib.h>
# define memcpy_(dest, src, size) sceDmacTryMemcpy(dest, src, size)
#endif
#ifdef COMPILE_PC
# define memcpy_(dest, src, size) memcpy(dest, src, size)
#endif

#define inc(pointer, type, offset) { type* __Tmp__ = static_cast< type* >(pointer); __Tmp__ += offset; pointer = static_cast< void* >(__Tmp__); } 

#define WriteAtom(dest, type, value) \
	memcpy_(dest, &value, sizeof(type)); \
	inc(dest, type, 1);

#define ReadAtom(Src, type, dest) \
	dest = *((type*)Src); \
	inc(Src, type, 1);

#define MESH_ATTR_STATE 1
#define MESH_ATTR_TRANSFORM 2
#define MESH_ATTR_BBOX 4
#define MESH_ATTR_GAMESTATE 8

#define CHAR_ATTR_POSITION 1
#define CHAR_ATTR_DIRECTION 2
#define CHAR_ATTR_DIRECTIONTOGO 4
#define CHAR_ATTR_SPEED 8
#define CHAR_ATTRCURRENTSTATE 16

namespace psp { namespace engine { namespace net {
	void* NetworkPacketMaker::Serialize(const TNetworkPacketMetaData& parDiff)
	{
		::psp::game::TGame& locGame = ::psp::game::TGame::Instance();

		u8 locSize1 = parDiff.FMeshResourcesDiff.size();
		u8 locSize2 = 0;
		u8 diff = 0;
		size_t locSizeToAllocate = 0;
		size_t locMetadataSize = 0;

		void* locSerializedMetaData = parDiff.Serialize(&locMetadataSize);
		locSizeToAllocate += locMetadataSize;

		//> Calculate size
		for(u8 i = 0 ; i < locSize1 ; i++)
		{
			locSize2 = parDiff.FMeshResourcesDiff[i].second.size();
			for(u16 j = 0 ; j < locSize2 ; j++)
			{
				diff = parDiff.FMeshResourcesDiff[i].second[j].second;
				if(diff && MESH_ATTR_STATE) locSizeToAllocate += sizeof(u32);
				if(diff && MESH_ATTR_TRANSFORM) locSizeToAllocate += sizeof(TTransform);
				if(diff && MESH_ATTR_BBOX) locSizeToAllocate += sizeof(bb2Df);
				if(diff && MESH_ATTR_GAMESTATE) locSizeToAllocate += sizeof(u8);
			}
		}

		locSize1 = parDiff.FCharactersDiff.size();
		for(u8 i = 0 ; i < locSize1 ; i++)
		{
			diff = parDiff.FCharactersDiff[i].second;
			if(diff && CHAR_ATTR_POSITION) locSizeToAllocate += sizeof(::psp::engine::core::vector3df);
			if(diff && CHAR_ATTR_DIRECTION) locSizeToAllocate += sizeof(::psp::engine::core::vector3df);
			if(diff && CHAR_ATTR_DIRECTIONTOGO) locSizeToAllocate += sizeof(::psp::engine::core::vector3df);
			if(diff && CHAR_ATTR_SPEED) locSizeToAllocate += sizeof(f32);
			if(diff && CHAR_ATTRCURRENTSTATE) locSizeToAllocate += sizeof(s32);
		}
		//<

		void* locResult = malloc(locSizeToAllocate);
		memset(locResult, 0, locSizeToAllocate);
		memcpy_(locResult, locSerializedMetaData, locMetadataSize);
		void* locPivot = locResult;
		// Offset the pivot to start at the end of the metadata serialization
		{
			c8* locPivotTmp = (c8*) locPivot;
			locPivotTmp += (locMetadataSize / sizeof(c8));
			locPivot = (c8*) locPivotTmp;
		}

		//> Writing data
		for(u8 i = 0 ; i < locSize1 ; i++)
		{
			locSize2 = parDiff.FMeshResourcesDiff[i].second.size();
			for(u16 j = 0 ; j < locSize2 ; j++)
			{
				diff = parDiff.FMeshResourcesDiff[i].second[j].second;
				if(diff && MESH_ATTR_STATE)
				{
					WriteAtom(locPivot, u32, locGame.FAllInteractiveItems[parDiff.FMeshResourcesDiff[i].first]->FState[parDiff.FMeshResourcesDiff[i].second[j].first]);
				}
				if(diff && MESH_ATTR_TRANSFORM)
				{
					WriteAtom(locPivot, TTransform, locGame.FAllInteractiveItems[parDiff.FMeshResourcesDiff[i].first]->FTransform[parDiff.FMeshResourcesDiff[i].second[j].first]);
				}
				if(diff && MESH_ATTR_BBOX)
				{
					WriteAtom(locPivot, bb2Df, locGame.FAllInteractiveItems[parDiff.FMeshResourcesDiff[i].first]->FBBox2Df[parDiff.FMeshResourcesDiff[i].second[j].first]);
				}
				if(diff && MESH_ATTR_GAMESTATE)
				{
					WriteAtom(locPivot, u8, locGame.FAllInteractiveItems[parDiff.FMeshResourcesDiff[i].first]->FGameState[parDiff.FMeshResourcesDiff[i].second[j].first]);
				}
			}
		}

		locSize1 = parDiff.FCharactersDiff.size();
		for(u8 i = 0 ; i < locSize1 ; i++)
		{
			diff = parDiff.FCharactersDiff[i].second;
			if(diff && CHAR_ATTR_POSITION)
			{
				WriteAtom(locPivot, ::psp::engine::core::vector3df, locGame.FCharacterList[parDiff.FCharactersDiff[i].first].FPosition);
			}
			if(diff && CHAR_ATTR_DIRECTION)
			{
				WriteAtom(locPivot, ::psp::engine::core::vector3df, locGame.FCharacterList[parDiff.FCharactersDiff[i].first].FDirection);
			}
			if(diff && CHAR_ATTR_DIRECTIONTOGO)
			{
				WriteAtom(locPivot, ::psp::engine::core::vector3df, locGame.FCharacterList[parDiff.FCharactersDiff[i].first].FDirectionToGo);
			}
			if(diff && CHAR_ATTR_SPEED)
			{
				WriteAtom(locPivot, f32, locGame.FCharacterList[parDiff.FCharactersDiff[i].first].FSpeed);
			}
			if(diff && CHAR_ATTRCURRENTSTATE)
			{
				WriteAtom(locPivot, s32, locGame.FCharacterList[parDiff.FCharactersDiff[i].first].FCurrentState);
			}
		}
		//<

		return locResult;
	}

	void NetworkPacketMaker::Deserialize(void* parData)
	{
		void* locPivot = parData;
		TNetworkPacketMetaData locMetadata = TNetworkPacketMetaData::Deserialize(&locPivot);

		::psp::game::TGame& locGame = ::psp::game::TGame::Instance();

		u8 locSize1 = locMetadata.FMeshResourcesDiff.size();
		u8 locSize2 = 0;
		u8 diff = 0;

		for(u8 i = 0 ; i < locSize1 ; i++)
		{
			locSize2 = locMetadata.FMeshResourcesDiff[i].second.size();
			for(u16 j = 0 ; j < locSize2 ; j++)
			{
				diff = locMetadata.FMeshResourcesDiff[i].second[j].second;
				if(diff && MESH_ATTR_STATE)
				{
					ReadAtom(locPivot, u32, locGame.FAllInteractiveItems[locMetadata.FMeshResourcesDiff[i].first]->FState[locMetadata.FMeshResourcesDiff[i].second[j].first]);
				}
				if(diff && MESH_ATTR_TRANSFORM)
				{
					ReadAtom(locPivot, TTransform, locGame.FAllInteractiveItems[locMetadata.FMeshResourcesDiff[i].first]->FTransform[locMetadata.FMeshResourcesDiff[i].second[j].first]);
				}
				if(diff && MESH_ATTR_BBOX)
				{
					ReadAtom(locPivot, bb2Df, locGame.FAllInteractiveItems[locMetadata.FMeshResourcesDiff[i].first]->FBBox2Df[locMetadata.FMeshResourcesDiff[i].second[j].first]);
				}
				if(diff && MESH_ATTR_GAMESTATE)
				{
					ReadAtom(locPivot, u8, locGame.FAllInteractiveItems[locMetadata.FMeshResourcesDiff[i].first]->FGameState[locMetadata.FMeshResourcesDiff[i].second[j].first]);
				}
			}
		}

		locSize1 = locMetadata.FCharactersDiff.size();
		for(u8 i = 0 ; i < locSize1 ; i++)
		{
			diff = locMetadata.FCharactersDiff[i].second;
			if(diff && CHAR_ATTR_POSITION)
			{
				WriteAtom(locPivot, ::psp::engine::core::vector3df, locGame.FCharacterList[locMetadata.FCharactersDiff[i].first].FPosition);
			}
			if(diff && CHAR_ATTR_DIRECTION)
			{
				WriteAtom(locPivot, ::psp::engine::core::vector3df, locGame.FCharacterList[locMetadata.FCharactersDiff[i].first].FDirection);
			}
			if(diff && CHAR_ATTR_DIRECTIONTOGO)
			{
				WriteAtom(locPivot, ::psp::engine::core::vector3df, locGame.FCharacterList[locMetadata.FCharactersDiff[i].first].FDirectionToGo);
			}
			if(diff && CHAR_ATTR_SPEED)
			{
				WriteAtom(locPivot, f32, locGame.FCharacterList[locMetadata.FCharactersDiff[i].first].FSpeed);
			}
			if(diff && CHAR_ATTRCURRENTSTATE)
			{
				WriteAtom(locPivot, s32, locGame.FCharacterList[locMetadata.FCharactersDiff[i].first].FCurrentState);
			}
		}
		//<
	}

#if defined(DEBUG) && defined(COMPILE_PC)
	void TNetworkPacketMetaData::Print()
	{
		std::cout << ToString();
	}

	std::string TNetworkPacketMetaData::ToString() const
	{
		std::ostringstream os;
		os << "Nb elt : " << FMeshResourcesDiff.size() << std::endl;
		for(u8 i = 0 ; i < FMeshResourcesDiff.size() ; i++)
		{
			os << "MeshResource index : " << (int)FMeshResourcesDiff[i].first << std::endl;
			for(u8 j = 0 ; j < FMeshResourcesDiff[i].second.size() ; j++)
			{
				os << "(" << (int)FMeshResourcesDiff[i].second[j].first << ", " << (int)FMeshResourcesDiff[i].second[j].second << ")" << std::endl;
			}
		}
		return os.str();
	}
#endif

	void* TNetworkPacketMetaData::Serialize(size_t* outAllocatedSize) const
	{
		//> calculate size to alloc
		size_t locSizeToAlloc = sizeof(u8);
		u8 locSize = (u8)FMeshResourcesDiff.size();
		u8 locSize2 = 0;
		u8 loc8Pivot = 0;
		u16 loc16Pivot = 0;

		for(u8 i = 0 ; i < locSize ; i++)
		{
			locSizeToAlloc += 2 * sizeof(u8); // index + array size
			locSizeToAlloc += (sizeof(u16) + sizeof(u8)) * FMeshResourcesDiff[i].second.size();
		}
		//<

		//> Allocate memory
		void* locResult = malloc(locSizeToAlloc);
		*outAllocatedSize = locSizeToAlloc;
		memset(locResult, 0, locSizeToAlloc);
		void* locPivot = locResult;
		//<

		//> Fill memory
		WriteAtom(locPivot, u8, locSize);
		for(u8 i = 0 ; i < locSize ; i++)
		{
			loc8Pivot = ((u8)FMeshResourcesDiff[i].first);
			WriteAtom(locPivot, u8, loc8Pivot);

			locSize2 = FMeshResourcesDiff[i].second.size();
			loc8Pivot = ((u8)locSize2);
			WriteAtom(locPivot, u8, loc8Pivot);

			for(u8 j = 0 ; j < locSize2 ; j++)
			{
				loc16Pivot = ((u16)FMeshResourcesDiff[i].second[j].first);
				WriteAtom(locPivot, u16, loc16Pivot);

				loc8Pivot = ((u8)FMeshResourcesDiff[i].second[j].second);
				WriteAtom(locPivot, u8, loc8Pivot);
			}
		}
		//<

		return locResult;
	}

	TNetworkPacketMetaData TNetworkPacketMetaData::Deserialize(void** parData)
	{
		TNetworkPacketMetaData locResult;
		u16 loc16Index = 0;
		u8 loc8Index = 0;
		u8 locSize2 = 0;
		u8 locSize = 0;
		void* locPivot = *parData;

		ReadAtom(locPivot, u8, locSize);
		for(u8 i = 0 ; i < locSize ; i++)
		{
			ReadAtom(locPivot, u8, loc8Index);
			locResult.FMeshResourcesDiff.push_back(std::make_pair(loc8Index, psp::engine::core::array< std::pair< u16, u8 > >()));
			
			ReadAtom(locPivot, u8, locSize2);
			for(u8 j = 0 ; j < locSize2 ; j++)
			{
				ReadAtom(locPivot, u16, loc16Index);
				ReadAtom(locPivot, u8, loc8Index);

				locResult.FMeshResourcesDiff[i].second.push_back(std::make_pair(loc16Index, loc8Index));
				
			}
		}
		// Assign parameters to the point where the serialized data start
		*parData = locPivot;
		return locResult;
	}
}}}