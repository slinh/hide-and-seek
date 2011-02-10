#include "stdafx.h"
#include <vector>
#include "NetworkData.h"
#include <assert.h>

#include "FSMMachine.h"
#include "FSMState.h"
#include "FSMCondition.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

#pragma warning(disable: 4368)

namespace UnitTest
{
	[TestClass]
	public ref class UnitTest1
	{
	private:
		TestContext^ testContextInstance;

		static psp::ia::TFSMMachine* FFSM;
	public: 
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		#pragma region Additional test attributes
		//
		//You can use the following additional attributes as you write your tests:
		//
		//Use ClassInitialize to run code before running the first test in the class
		[ClassInitialize()]
		static void MyClassInitialize(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ testContext) 
		{
			//> Create state machine
			FFSM = new psp::ia::TFSMMachine();
			psp::ia::TFSMState* locState000 = new psp::ia::TFSMState(0);
			psp::ia::TFSMState* locState001 = new psp::ia::TFSMState(1);
			psp::ia::TFSMState* locState011 = new psp::ia::TFSMState(3);
			psp::ia::TFSMState* locState010 = new psp::ia::TFSMState(2);
			psp::ia::TFSMState* locState110 = new psp::ia::TFSMState(6);
			psp::ia::TFSMState* locState111 = new psp::ia::TFSMState(7);
			psp::ia::TFSMState* locState101 = new psp::ia::TFSMState(5);
			psp::ia::TFSMState* locState100 = new psp::ia::TFSMState(4);

			locState000->LinkTo(new psp::ia::TFSMDebugCondition(locState000), locState110);
			locState000->LinkTo(new psp::ia::TFSMDebugCondition(locState000), locState101);

			locState001->LinkTo(new psp::ia::TFSMDebugCondition(locState001), locState000);

			locState010->LinkTo(new psp::ia::TFSMDebugCondition(locState010), locState011);

			locState011->LinkTo(new psp::ia::TFSMDebugCondition(locState011), locState100);

			locState100->LinkTo(new psp::ia::TFSMDebugCondition(locState100), locState001);

			locState101->LinkTo(new psp::ia::TFSMDebugCondition(locState101), locState100);

			locState110->LinkTo(new psp::ia::TFSMDebugCondition(locState110), locState010);

			locState111->LinkTo(new psp::ia::TFSMDebugCondition(locState111), locState000);

			FFSM->AddState(locState000);
			FFSM->AddState(locState001);
			FFSM->AddState(locState011);
			FFSM->AddState(locState010);
			FFSM->AddState(locState110);
			FFSM->AddState(locState111);
			FFSM->AddState(locState101);
			FFSM->AddState(locState100);

			FFSM->SetCurrentState(locState000);
			//<
		};
		//
		//Use ClassCleanup to run code after all tests in a class have run
		[ClassCleanup()]
		static void MyClassCleanup() 
		{
			delete FFSM;
		};
		//
		//Use TestInitialize to run code before running each test
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//Use TestCleanup to run code after each test has run
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
		#pragma endregion 

		[TestMethod]
		void SerializeMetadata()
		{
			psp::engine::net::TNetworkPacketMetaData FMetaData;
			FMetaData.FMeshResourcesDiff.push_back(std::make_pair((u8) 0, psp::engine::core::array< std::pair< u16, u8 > >()));
			FMetaData.FMeshResourcesDiff.push_back(std::make_pair((u8) 1, psp::engine::core::array< std::pair< u16, u8 > >()));
			FMetaData.FMeshResourcesDiff.push_back(std::make_pair((u8) 3, psp::engine::core::array< std::pair< u16, u8 > >()));
			FMetaData.FMeshResourcesDiff[0].second.push_back(std::make_pair((u16) 0, (u8) 3));
			FMetaData.FMeshResourcesDiff[0].second.push_back(std::make_pair((u16) 1, (u8) 7));
			FMetaData.FMeshResourcesDiff[0].second.push_back(std::make_pair((u16) 5, (u8) 2));
			FMetaData.FMeshResourcesDiff[1].second.push_back(std::make_pair((u16) 0, (u8) 3));
			FMetaData.FMeshResourcesDiff[2].second.push_back(std::make_pair((u16) 6, (u8) 4));
			FMetaData.FMeshResourcesDiff[2].second.push_back(std::make_pair((u16) 5, (u8) 10));
			FMetaData.FMeshResourcesDiff[2].second.push_back(std::make_pair((u16) 7, (u8) 13));

			std::string dump = FMetaData.ToString();
			void* locRawMetaData = FMetaData.Serialize();
			psp::engine::net::TNetworkPacketMetaData locMetaData = psp::engine::net::TNetworkPacketMetaData::Deserialize(locRawMetaData);
			assert(locMetaData.FMeshResourcesDiff.size() == FMetaData.FMeshResourcesDiff.size());
			u16 locSize01 = locMetaData.FMeshResourcesDiff.size();
			for(u16 i = 0 ; i < locSize01 ; i++)
			{
				assert(locMetaData.FMeshResourcesDiff[i].first == FMetaData.FMeshResourcesDiff[i].first);
				assert(locMetaData.FMeshResourcesDiff[i].second.size() == FMetaData.FMeshResourcesDiff[i].second.size());
				u16 locSize02 = locMetaData.FMeshResourcesDiff[i].second.size();
				for(u16 j = 0 ; j < locSize02 ; j++)
				{
					assert(locMetaData.FMeshResourcesDiff[i].second[j].first == FMetaData.FMeshResourcesDiff[i].second[j].first);
					assert(locMetaData.FMeshResourcesDiff[i].second[j].second == FMetaData.FMeshResourcesDiff[i].second[j].second);
				}
			}
		};

		[TestMethod]
		void FSMTest01()
		{
			assert(FFSM->GetCurrentState().GetCode() == 0);
			FFSM->Update();
			assert(FFSM->GetCurrentState().GetCode() == 6);
			FFSM->Update();
			assert(FFSM->GetCurrentState().GetCode() == 2);
			FFSM->Update();
			assert(FFSM->GetCurrentState().GetCode() == 3);
			FFSM->Update();
			assert(FFSM->GetCurrentState().GetCode() == 4);
			FFSM->Update();
			assert(FFSM->GetCurrentState().GetCode() == 1);
			FFSM->Update();
			assert(FFSM->GetCurrentState().GetCode() == 0);
		}
	};
}
