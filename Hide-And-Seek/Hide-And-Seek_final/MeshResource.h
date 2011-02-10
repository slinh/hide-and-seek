#ifndef MESH_RESOURCE_H
#define MESH_RESOURCE_H

#include "DrawingParameters.h"
#include "engineArray.h"
#include "vector3d.h"
#include "StaticMeshOBJ.h"
#include "Transform.h"
#include "NetworkData.h"

namespace psp { namespace engine { 
	using namespace core;
	using namespace video;

	namespace object {

		/*	Forward declaration	*/
		class TMap;

		class TMeshResource
		{
			friend class TMap;

			/*	Fields	*/
		private:
			MESH_TYPE FType;				// saved in map
			IMesh* FMesh;
			u32 FProperties;				// saved in map
			array<u32> FState;
			array<u32> FCheckIAState;
			array<TTransform> FTransform;	// saved in map
			array<bb2Df> FBBox2Df;
			array<u8> FGameState;
			u8 FIdSoundForPathMarker;

			/*	Method	*/
		private:
			void Init(const c8* parFileName, u32 parProperties, array<TTransform> &parTransform);	
			//void Init(const c8* parFileName, u32 parProperties, const array<TTransform> &parTransform);	

		public:
			TMeshResource();
			TMeshResource(c8** parBuffer);
			TMeshResource(const c8* parFileName, u32 parItemType, array<TTransform> &parTransform,  u8 parIdSoundForPathMarker = 0 );
			//TMeshResource(const c8* parFileName, u32 parItemType, const array<TTransform> &parTransform,  u8 parIdSoundForPathMarker = 0 );
			~TMeshResource(void);

			//void AddTransformation(const TTransform &parTransform);
			void AddTransformation(TTransform &parTransform);
			void SetAllStates(const u32& parState);
			void SetAllCheckIAStates(const u32& parState);

			u32 SerializedSize();
			void Serialize(c8** parBuffer);
			void Deserialize(c8** parBuffer);

			static MESH_TYPE GetExtension(const c8* parFileName);
			static bool CompareExtension(const c8* parFileName, const c8* parExt);

			GETTER(MESH_TYPE, Type)
			GETTER_PTR(IMesh, Mesh)
			GETTER(u32, Properties)
			GETTER(array<TTransform>, Transform)
			GETTER_SETTER(array<u8>, GameState)
			GETTER_SETTER(u8, IdSoundForPathMarker)

			// Functions to manage object drawing state and transformations
			void InitAllDrawingState()
			{
				for(u32 i=0; i<FState.size(); ++i)
				{
					FState[i] = NOT_DRAWN;
				}
			}

			const u32& GetDrawingState(const u32& parId) const 
			{ 
				LAssert(parId < FState.size()); 
				return FState[parId];
			}

			void SetDrawingState(const u32& parId, const u32& parState) 
			{
				LAssert(parId < FState.size()); 
				FState[parId] = parState;
			}

			void AddDrawingState(const u32& parId, const u32& parState) 
			{
				LAssert(parId < FState.size()); 
				FState[parId] = FState[parId]|parState;
			}

			const u32& GetCheckIAState(const u32& parId) const 
			{ 
				LAssert(parId < FCheckIAState.size()); 
				return FCheckIAState[parId];
			}

			void SetCheckIAState(const u32& parId, const u32& parState) 
			{
				LAssert(parId < FCheckIAState.size()); 
				FCheckIAState[parId] = parState;
			}

			const u32 GetNbTransform() const
			{
				return FTransform.size();
			}
 
			const TTransform& GetTransform(const u32 &parId) const 
			{ 
				LAssert(parId < FTransform.size()); 
				return FTransform[parId]; 
			}

			const u32 GetNbBBox2Df() const
			{
				return FBBox2Df.size();
			}

			const bb2Df& GetBBox2Df(const u32 &parId) const 
			{ 
				LAssert(parId < FBBox2Df.size()); 
				return FBBox2Df[parId]; 
			}

			friend void* ::psp::engine::net::NetworkPacketMaker::Serialize(const TNetworkPacketMetaData& parDiff);
			friend void ::psp::engine::net::NetworkPacketMaker::Deserialize(void* parData);
		};

	} // object namespace
} // engine namespace
} // psp namespace

#endif