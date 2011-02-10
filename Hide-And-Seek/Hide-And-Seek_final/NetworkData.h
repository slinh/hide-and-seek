#ifndef H_NETWORK_DATA_INCLUDE
#define H_NETWORK_DATA_INCLUDE

#include "config.h"

#ifdef DEBUG
# include <string>
#endif

#include <utility>

#include "engineTypes.h"
#include "vector3d.h"
#include "engineArray.h"

namespace psp { namespace engine { namespace net {

	class TNetworkPacketMetaData
	{
	public:
		TNetworkPacketMetaData(){}
		// array< pair< MeshResourceIndex, array< pair< ResourceInstanceIndex, Diff > > > >
		psp::engine::core::array< std::pair< u8, psp::engine::core::array< std::pair< u16, u8 > > > > FMeshResourcesDiff;
		// array< pair< CharacterIndex, Diff > > >
		psp::engine::core::array< std::pair< u8, u8 > > FCharactersDiff;

		void* Serialize(size_t* outAllocatedSize) const;
		static TNetworkPacketMetaData Deserialize(void** parData);

#ifdef DEBUG
		std::string ToString() const;
		void Print();
#endif
	};

	namespace NetworkPacketMaker
	{
		void* Serialize(const TNetworkPacketMetaData& parDiff);
		void Deserialize(void* parData);
	}

}}}

#endif