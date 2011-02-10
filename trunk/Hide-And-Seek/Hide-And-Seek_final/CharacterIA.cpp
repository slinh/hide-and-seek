#include "CharacterIA.h"
#include "LoggerTypes.h"
#include "vector3d.h"
#include "Character.h"
#include "Graph.h"
#include "BoundingBox2D.h"
#include "ObjectManager.h"
#include "Game.h"

#include "FSMMachine.h"
#include "FSMState.h"

#include <math.h>

namespace psp { 

namespace ia
{
	bool TFSMInSpotCondition::operator()()
	{
		return false;
	}

	bool TFSMOutSpotCondition::operator()()
	{
		return false;
	}

	bool TFSMInAttackCondition::operator()()
	{
		return false;
	}

	bool TFSMOutAttackCondition::operator()()
	{
		return false;
	}
}
	
namespace game {

	
TCharacterIA::TCharacterIA() :
	FObjectToGo(NULL),
	FNodeObjectToGo(0),
	FNodeToGo(0),
	FCurrentNode(0),
	FFSM(NULL)
{
	FCount = 0;
	//FPosition = engine::core::vector3df(1.236f, 0.f, -1.617f);
	FPosition = engine::core::vector3df(4.3f, 0.f, 4.87f); // GOOD ONE
	
	FDirection = engine::core::vector3df(0.f, 0.f, 0.f);
	FSpeed = CP_SPEED_HUNTER;
	FRole = CR_HUNTER;

	/*
	bool locLocMD2 = FMD2->Load( ICharacter::MD2_HUNTER.c_str() );

	if( locLocMD2 )
	{
		// Mesh buffer pour recuperer la bbox du perso 
		FBBox = FMD2->GetMeshBuffer(0).GetBBox2D();
	}
	*/

	
	// TEMPORAIRE
	FBBox = engine::core::TBoundingBox2D<float>();
	FBBox.AddPoint(0,0);
	FBBox.AddPoint(0,1);
	FBBox.AddPoint(1,0);
	FBBox.AddPoint(1,1);
	
	InitFSM();
}


TCharacterIA::TCharacterIA(engine::core::vector3df parPosition, engine::core::vector3df parDirection, float parSpeed) :
	FObjectToGo(NULL),
	FNodeObjectToGo(0),
	FNodeToGo(0),
	FCurrentNode(0),
	FFSM(NULL)
{
	//FPtr = TTaskIA::Make<TCharacterIA, &TCharacterIA::Print >(this);
	FCount = 0;
	FPosition = parPosition;
	FDirection = parDirection;
	FSpeed = parSpeed;
	FRole = CR_HUNTER;
	
	/*
	bool locLocMD2 = FMD2->Load( ICharacter::MD2_HUNTER.c_str() );

	if( locLocMD2 )
	{
		// Mesh buffer pour recuperer la bbox du perso 
		FBBox = FMD2->GetMeshBuffer(0).GetBBox2D();
	}
	*/
	
	
	// TEMPORAIRE
	FBBox = engine::core::TBoundingBox2D<float>();
	FBBox.AddPoint(0,0);
	FBBox.AddPoint(0,1);
	FBBox.AddPoint(1,0);
	FBBox.AddPoint(1,1);

	InitFSM();
}


TCharacterIA::~TCharacterIA(void)
{
	delete FFSM;
}

void TCharacterIA::InitFSM()
{
	//> Build FSM
/*
	Etat 0 : Standard
	Le poursuivant se rapproche lentement de la pièce ou se trouve le joueur.
		=> 1, détection du joueur
	Etat 1 : Poursuite
	Le poursuivant se dirige directement vers le joueur (vitesse normale)
		=> 0, perte de la position du joueur
		=> 2, attaque possible
	Etat 2 : Attaque vers le joueur
		=> 1, Attaque échouée et attaque non possible
*/
	FFSM = NEW_IN_DOMAIN(Game) ::psp::ia::TFSMMachine();
	::psp::ia::TFSMState* locState0 = new ::psp::ia::TFSMState(0);
	::psp::ia::TFSMState* locState1 = new ::psp::ia::TFSMState(1);
	::psp::ia::TFSMState* locState2 = new ::psp::ia::TFSMState(2);
	locState0->LinkTo(new ::psp::ia::TFSMInSpotCondition(locState0), locState1);

	locState1->LinkTo(new ::psp::ia::TFSMOutSpotCondition(locState1), locState0);
	locState1->LinkTo(new ::psp::ia::TFSMInAttackCondition(locState1), locState2);

	locState2->LinkTo(new ::psp::ia::TFSMOutAttackCondition(locState2), locState1);

	FFSM->AddState(locState0);
	FFSM->AddState(locState1);
	FFSM->AddState(locState2);

	FFSM->SetCurrentState(locState0);
}

void TCharacterIA::Act(void)
{
	LOGC_IA("START CharacterIA ACT");

	//> Choose destination
	/*switch(FFSM->GetCurrentState().GetCode())
	{
	case 0:
	case 1:
	case 2:
		FObjectToGo = ::psp::engine::object::TObjectManager::Instance().GetNearestObject(TGame::Instance().GetCharacterList()[0].GetPosition());
		break;
	default:
		LAssert(false);
		break;
	}*/
	//<

	//> Compute nest node to reach and update FDirectionToGo
	//ComputeNextNode();
	//<
	//[DASH]
	vector3df locToChar = TGame::Instance().GetCharacterList()[0].GetPosition() - FPosition;
	f32 length = locToChar.getLength();
	
	/* COMMENT AURORE
	if(length > 0.5f && (FLastPop == 0 || ::psp::game::TGame::Instance().GetTimeInteger32() - FLastPop > 1000))
	{
		bb2Df locBbox = ::psp::game::TGame::Instance().GetCharacterList()[0].GetBBox();
		locBbox.Translate(::psp::game::TGame::Instance().GetCharacterList()[0].GetPosition());
		locBbox.SetTop() = locBbox.GetY() + (locBbox.GetTop() - locBbox.GetY()) * 2.f;
		locBbox.SetBottom() = locBbox.GetY() + (locBbox.GetBottom() - locBbox.GetY()) * 2.f;
		locBbox.SetRight() = locBbox.GetX() + (locBbox.GetRight() - locBbox.GetX()) * 2.f;
		locBbox.SetLeft() = locBbox.GetX() + (locBbox.GetLeft() - locBbox.GetX()) * 2.f;
		vector3df locNewPosition;
		locNewPosition.X = locBbox.GetWidth() * (std::sin(::psp::game::TGame::Instance().GetTimeInteger32()) + 1) * 0.5f + locBbox.GetLeft();
		locNewPosition.Z = locBbox.GetHeight() * (std::cos(::psp::game::TGame::Instance().GetTimeInteger32()) + 1) * 0.5f + locBbox.GetBottom();

		FPosition = locNewPosition;
		FLastPop = ::psp::game::TGame::Instance().GetTimeInteger32();
	}
	*/

	FDirectionToGo = locToChar / length;
	if(length < 0.2f)
			AddOrder(CO_DASH);
	if(length < 0.8f)
		FDirectionToGo *= 0.80f;
	else
		FDirectionToGo *= 0.71f;

	AddOrder(CO_RUN);

	//> Update FSM
	//u32 locLastState = FFSM->GetCurrentState().GetCode();
	//FFSM->Update();
	//bool locHasChanged = locLastState != FFSM->GetCurrentState().GetCode();
	//<

	//> Update Speed
	/*switch(FFSM->GetCurrentState().GetCode())
	{
	case 0:
		FDirectionToGo * 0.8f;
		FOrder = CO_WALK;
		break;
	case 1:
		FOrder = CO_RUN;
		break;
	case 2:
		FOrder = CO_DASH;
		break;
	default:
		LAssert(false);
		break;
	}*/
	//<
	LOGC_IA("END CharacterIA ACT");
}

void TCharacterIA::ComputeNewDirection()
{
	FDirectionToGo = (TGame::Instance().GetCharacterList()[0].GetPosition() - FPosition).normalize();

	SetOrderWalk();
}

void TCharacterIA::ComputeNextNode()
{
	FCurrentNode = engine::core::TGridGraph::Instance().GetNearestNode(FPosition);

	if(FObjectToGo == NULL)
	{
		FObjectToGo = engine::object::TObjectManager::Instance().GetNearestObject(FPosition);
		FNodeObjectToGo = engine::core::TGridGraph::Instance().GetNearestNode(FObjectToGo->GetPosition());
		FNodeToGo = engine::core::TGridGraph::Instance().GetNextNodeToGo(FCurrentNode, FNodeObjectToGo);
	}

	if(FCurrentNode == FNodeToGo)
	{
		if(FNodeToGo == FNodeObjectToGo)
		{
			// on est arrivé devant l'objet
			LOGC_IA("ObjectToGo atteint");
		}
		else 
		{
			// on calcule le prochain noeud intermédiaire où aller
			FNodeToGo = engine::core::TGridGraph::Instance().GetNextNodeToGo(FCurrentNode, FNodeObjectToGo);
		}
	}
	else 
	{
		// on dirige le perso vers le noeud intermédiaire où aller
		engine::core::vector3df nodeToGoPosition(0.0f, 0.0f, 0.0f);
		engine::core::TGridGraph::Instance().GetNodePosition(FNodeToGo, nodeToGoPosition);
		FDirectionToGo = nodeToGoPosition - FPosition;
		FDirectionToGo.normalize();

		SetOrderWalk();
	}
}

} // namespace game
} // namespace psp

