#include "GameRulesApplicator.h"
#include "Game.h"

namespace psp { namespace game {
//--------------------------------------------------------------------------------
//********************************************************************************
//--------------------------------------------------------------------------------
TGameRulesApplicator::TGameRulesApplicator()
{}
//--------------------------------------------------------------------------------
TGameRulesApplicator::~TGameRulesApplicator()
{}
//--------------------------------------------------------------------------------
void TGameRulesApplicator::CharacterAct(ICharacter* parCharacter)
{
	//LOGC("### Character Act ###\n");
	TGame& locGame = TGame::Instance();

	if( parCharacter->GetRole() & CR_VICTIM )
		locGame.FObjectToLook = &(locGame.FLookedInteractiveItem);
	else
		locGame.FObjectToLook = &(locGame.FAllInteractiveItems);

	// si en train de jouer une anim qui empêche autre ordre, on squeez
	//if( animNotEnding )
	//	return;

	// si poursuivi seulement le droit de faire dash :
	if( locGame.FAttackInThisRound )
	{
		if( ( parCharacter->GetRole() & CR_VICTIM ) 
			&& ( !(parCharacter->GetOrder() & CO_DASH) ) )
		{
			// TODO lancer jouer anima mort avant ?
			// TODO use a variable in GamesRUlesApplicator or do it in an other way
			//locGame.FGameState = G_ENDED | G_LOOSE;

			return; // pas d'autre action ok
		}
	}

	// position before update
	engine::core::vector3df locLastPosition = parCharacter->GetPosition();
	//LOGC("Order : %d\n", parCharacter->GetOrder());
	if( parCharacter->GetOrder() & CO_ACTIVATE )
	{
		//LOGC("ORDER ACTIVATE\n");
		parCharacter->SetCurrentState() = CO_ACTIVATE;
		// on parcours la liste des objets
		for(u32 i = 0; i < locGame.FObjectToLook->size(); ++i)
		{
			// si marqueur pas besoin de regarder l'objet :
			if( ! ( (*locGame.FObjectToLook)[i]->GetProperties() & O_PATH_MARKER ) )
			{
				array<TTransform> locTransform = (*(locGame.FObjectToLook))[i]->GetTransform();
				for( u32 j = 0; j <  locTransform.size(); ++j )
				{
					// recup de la bbox
					bb2Df locCurrentBBox = (*(locGame.FObjectToLook))[i]->GetBBox2Df(j);
				
					// on regarde si a proximite
					bool locIsNear = locCurrentBBox.IsNearAtMost( parCharacter->GetBBox(), EPSILON_NEAR );
				
					if( locIsNear )
					{
						// si l'objet est un passage secret
						if( (*(locGame.FObjectToLook))[i]->GetProperties() & O_SECRET_PATH )
						{
							// si poursuivant et actif, alors ca casse
							if( ( parCharacter->GetRole() & CR_HUNTER )
									&& ( (*(locGame.FObjectToLook))[i]->GetGameState()[i] & OS_ACTIVATE ) )
							{
								(*(locGame.FObjectToLook))[i]->SetGameState()[i] = OS_DESACTIVATE;
							}
							// sinon
							else // jouer animation passage secret
							{
								u32 locIdEnd;
								// on cherche l'id du passage d'arrviée
								if(i & 1) // impair
									locIdEnd = i + 1;
								else
									locIdEnd = i - 1;
								
								// on cherche dans quel sens decaler perso à l'arrivée :

								// TODO
								// update pos joueur
								locGame.FFakeEndSecretPath.X = (*(locGame.FObjectToLook))[i]->GetBBox2Df(locIdEnd).GetX();
								locGame.FFakeEndSecretPath.Y = (*(locGame.FObjectToLook))[i]->GetBBox2Df(locIdEnd).GetY();
							}
							
						
							return; // ne pas appliquer a d'autres objets
						} 
					
						// si objet interractif
						if( (*(locGame.FObjectToLook))[i]->GetGameState()[i] & O_INTERACTIVE )
						{
							// switcher etat
							if( (*(locGame.FObjectToLook))[i]->GetGameState()[j] & OS_DESACTIVATE )
								(*(locGame.FObjectToLook))[i]->SetGameState()[j] = OS_ACTIVATE;
							
							else
								(*(locGame.FObjectToLook))[i]->SetGameState()[j] = OS_DESACTIVATE;
							
								
							return; // ne pas appliquer ˆ d'autres objets
						}
					
					}
				}
			}
		}
	}
	else if( ( parCharacter->GetOrder() & CO_DASH ) && ( parCharacter->GetOrder() & CO_RUN ) )
	{
		//LOGC("ORDER DASH \n");
		parCharacter->SetCurrentState() = CO_DASH;
		parCharacter->Update();
	}
	else if( ( parCharacter->GetOrder() & CO_RUN ) && ( parCharacter->GetOrder() & CO_WALK ) )
	{

		//LOGC("ORDER WALK \n");
		parCharacter->SetCurrentState() = CO_WALK;
		parCharacter->Update();
	}
	else if( ( parCharacter->GetOrder() & CO_RUN) )
	{
		// RUN

		//LOGC("ORDER RUN \n");
		parCharacter->SetCurrentState() = CO_RUN;
		parCharacter->Update();

		//LOGC("Position apres : %f, %f, %f \n", parCharacter->GetPosition().X, parCharacter->GetPosition().Y, parCharacter->GetPosition().Z);

		// On regarde si ya pas un / des marquers proche a activer :
		// on parcours la liste des objets
		for(u32 i = 0; i < locGame.FObjectToLook->size(); ++i)
		{
			// si marqueur
			if( (*(locGame.FObjectToLook))[i]->GetProperties() & O_PATH_MARKER )
			{
				array<TTransform> locTransform = (*(locGame.FObjectToLook))[i]->GetTransform();
				for( u32 j = 0; j <  locTransform.size(); ++j )
				{
					bb2Df locCurrentBBox = (*(locGame.FObjectToLook))[i]->GetBBox2Df(j);
					// si a proximite et desactive alors : activer
					if ( locCurrentBBox.IsNearAtMost( parCharacter->GetBBox(), 13*EPSILON_NEAR ) )
					{
						// si type son alors jouer
						(*(locGame.FObjectToLook))[i]->GetIdSoundForPathMarker();
							
						// TODO 
						// play 

						/*
						// si non activate à remettre si objet qui doivent etre activés une seule fois
						if( locIsNear && ( (*FObjectToLook)[i]->GetGameState()[j] & OS_DESACTIVATE ) )
						{
							// si type son alors jouer
							u8 idSound = (*FObjectToLook)[i]->GetIdSoundForPathMarker();
							
							// TODO 
							// play
							(*FObjectToLook)[i]->SetGameState()[j] = OS_ACTIVATE; 
						}*/
#ifdef WITH_SOUNDS
						// jouer son
						if(game::TGame::Instance().GetSoundManager()->IsSoundPlaying(game::TGame::Instance().GetSoundManager()->GetIndexGlass()))
						{
							game::TGame::Instance().GetSoundManager()->PlaySound(game::TGame::Instance().GetSoundManager()->GetIndexGlass());
						}
#endif
					}
				}
			}
		}
			


	}
	else // NOTHING
	{
//		LOGC("ORDER NOTHING \n");
		parCharacter->SetCurrentState() = CO_NOTHING;
	}

	/*
	LOGC("Direction character %f, %f\n", parCharacter->GetDirection().X, parCharacter->GetDirection().Z );
	LOGC("pos character %f, %f\n", parCharacter->GetDirection().X, parCharacter->GetDirection().Z );
	*/

	parCharacter->SetOrderNothing();
	//LOGC("### Character Act End ###\n");
}
//--------------------------------------------------------------------------------
// au final dans parX, par Y la pos pour le character pour eviter collision si il y en a une
void TGameRulesApplicator::CheckCollisonWithObject(ICharacter & parCharacter, psp::engine::core::array< engine::core::TBoundingBox2D<float> >& parBBoxList, TGameLoopData& parGameLoopData)
{
	float locX = 0;
	float locY = 0;

	bb2Df locCharBBox = parGameLoopData.meshMD2->Getbb2Df(parGameLoopData.FMD2Frame);
	locCharBBox.Translate(parCharacter.GetPosition());

	// on parcours la liste des objets
	for( u32 i = 0; i <  parBBoxList.size(); ++i  )
	{
		bb2Df locCurrentBBox = parBBoxList[i];
			
		// on regarde si on a une collision

		psp::engine::core::FACE_SIDE locCollisionSide = locCurrentBBox.Intersect_WithFaceTouch( locCharBBox );
		float locSeparatingDistance = 0;

		switch( locCollisionSide )
		{
			case psp::engine::core::FS_NONE:
				// do nothing
			break;
			
			case psp::engine::core::FS_TOP:

				locSeparatingDistance = ( ( locCurrentBBox.GetHeight() 
											+ locCharBBox.GetHeight() )
											/2. );
				locX = parCharacter.GetPosition().X;
				locY = locCurrentBBox.GetY() + locSeparatingDistance;
				parCharacter.SetPositionTo(locX, locY);

			break;

			case psp::engine::core::FS_BOTTOM:

				locSeparatingDistance = ( ( locCurrentBBox.GetHeight() 
											+ locCharBBox.GetHeight() )
											/2. );
				locX = parCharacter.GetPosition().X;
				locY = locCurrentBBox.GetY() - locSeparatingDistance;

				parCharacter.SetPositionTo(locX, locY);

			break;

			case psp::engine::core::FS_LEFT:

				locSeparatingDistance = ( ( locCurrentBBox.GetWidth() 
											+ locCharBBox.GetWidth() )
											/2. );
				locX = locCurrentBBox.GetX() - locSeparatingDistance;
				locY = parCharacter.GetPosition().Z;

				parCharacter.SetPositionTo(locX, locY);

			break;
				
			case psp::engine::core::FS_RIGHT:

				locSeparatingDistance = ( ( locCurrentBBox.GetWidth() 
											+ locCharBBox.GetWidth() )
										/2. );
				locX = locCurrentBBox.GetX() + locSeparatingDistance;
				locY = parCharacter.GetPosition().Z;

				parCharacter.SetPositionTo(locX, locY);
			break;
			
			case FS_ERROR:
				//LOGC("ERROR In collision detection with face \n");
				break;

		}
	}
}
//--------------------------------------------------------------------------------
void TGameRulesApplicator::Act(TGameLoopData& parGameLoopData)
{
	//LOGC("### Act ###\n");
	TGame& locGame = TGame::Instance();

	if( locGame.FGameConfig.GetNumberOfPlayers() == NP_SOLO ) 
	{
		// We are in SOLO MODE : TO DO delete later
		parGameLoopData.FIsAnimated = locGame.FCharacterList[0].GetOrder() & CO_RUN;
		parGameLoopData.FIsAnimated2 = locGame.FCharacterList[1].GetOrder() & CO_RUN;

		// Applications des ordres des joueurs (si valides)
		for(unsigned int i=0; i<locGame.FCharacterList.size(); i++)
		{
			CharacterAct( &(locGame.FCharacterList[i]) );
		}
	}
	else  // only our character
	{
		CharacterAct( &(locGame.FCharacterList[0])  );
	}

	// CHECK DES REGLES
	u64 locCurrentTime = locGame.GetTimeInteger64();

	// fin du jeu, poursuivi = perdu
	if( locCurrentTime - locGame.GetBeginingTime() >= locGame.GetGameConfig().GetGameDuration() )
	{
		// TODO dont use two variables to do the same thing : delete use of FGameState
		//locGame.FGameState = G_ENDED | G_WIN;
		//LOGC(" ********* Fin du temps de jeu = GAME WIN ******** \n");
		locGame.SetCurrentState() = GS_WIN_GAME;
	}


	vector2df locDistance( (locGame.FCharacterList[0].GetPosition().X - locGame.FCharacterList[1].GetPosition().X), (locGame.FCharacterList[0].GetPosition().Z - locGame.FCharacterList[1].GetPosition().Z) );

	if( locDistance.getLength() < 0.5 ) 
	// si le poursuivi / poursuivant sont trop proches on change de musique
	//if( locGame.GetCharacterList()[0].GetBBox().IsNearAtMost( locGame.GetCharacterList()[1].GetBBox(), EPSILON_NEAR_CHARACTER ) )
	{
		// jouer tension
		if(game::TGame::Instance().GetSoundManager()->IsSoundPlaying(game::TGame::Instance().GetSoundManager()->GetIndexVictim()))
			game::TGame::Instance().GetSoundManager()->StopSound(game::TGame::Instance().GetSoundManager()->GetIndexVictim());

		if(!game::TGame::Instance().GetSoundManager()->IsSoundPlaying( game::TGame::Instance().GetSoundManager()->GetIndexFear() ) )
		{
			game::TGame::Instance().GetSoundManager()->PlaySound( game::TGame::Instance().GetSoundManager()->GetIndexFear() );
		}
	}
	/*else
	{
		// jouer musique normale
		if(game::TGame::Instance().GetSoundManager()->IsSoundPlaying(game::TGame::Instance().GetSoundManager()->GetIndexFear()))
			game::TGame::Instance().GetSoundManager()->StopSound(game::TGame::Instance().GetSoundManager()->GetIndexFear());

		if(!game::TGame::Instance().GetSoundManager()->IsSoundPlaying(game::TGame::Instance().GetSoundManager()->GetIndexVictim()) )
		{
			game::TGame::Instance().GetSoundManager()->PlaySound(game::TGame::Instance().GetSoundManager()->GetIndexVictim());
		}
	}*/

//	FAttackInThisRound = false;
//
//	// check si une attaque a lieu dans la manche :
//	// si collision poursuivant / poursuivi :
//	if( FCharacterList[0].GetBBox().Intersect( FCharacterList[1].GetBBox() ) )
//	{
//		// si en plus poursuivant : dash alors cas d'attaque :
//		if( FCharacterList[1].GetOrder() & CO_DASH )
//		{
//			FAttackInThisRound = true;
//
//			// si pas de dash chez le joueur c mort
//			if( ! ( FCharacterList[0].GetOrder() & CO_DASH ) )
//				FGameState = FGameState | G_LOOSE;
//			//sinon on joue la manche
//		}
//	}
//
////*/
//	/*
//	// si on a une attaque sur le tour courant, verif si le joueur a dashé (en gros collisionne plus ^^)
//	if( FAttackInThisRound )
//	{
//		if( FCharacterList[0].SetBBox().Intersect( FCharacterList[1].GetBBox() ) )
//			FGameState = FGameState | G_LOOSE;
//	}
//	*/
//
//
//
//	/* TEST AURORE BBOX COLLISION */
//	/* DECOMMENTER CES LIGNES POUR AFFICHER LE CONTENU DES LISTES DES OBJETS A PROXIMITE DES PERSOS
//	LOGC("****************************** LISTE BBOX ***************************** \n");
//
//	LOGC("BBoxCharacter size %d \n", FBBoxAroundCharacter.size());
//	for( u8 i = 0; i < FBBoxAroundCharacter.size(); ++i )
//	{
//		LOGC("BBox n : %d, x : %f, y : %f \n", i, FBBoxAroundCharacter[i].GetX(), FBBoxAroundCharacter[i].GetY() ); 
//	}
//	
//	LOGC("BBoxIA size %d \n", FBBoxAroundIA.size());
//	for( u8 i = 0; i < FBBoxAroundIA.size(); ++i )
//	{
//		LOGC("BBox n : %d, x : %f, y : %f \n", i, FBBoxAroundIA[i].GetX(), FBBoxAroundIA[i].GetY() ); 
//	}
//	*/
		// check collision character / charracter
	

	//LOGC("FCharacterList[0].GetBBox() %f, %f, %f, %f  \n ", locGame.FCharacterList[0].GetBBox().GetX(), locGame.FCharacterList[0].GetBBox().GetY(), locGame.FCharacterList[0].GetBBox().GetWidth(), locGame.FCharacterList[0].GetBBox().GetHeight() );
	//LOGC("FCharacterList[1].GetBBox() %f, %f, %f, %f   \n", locGame.FCharacterList[1].GetBBox().GetX(), locGame.FCharacterList[1].GetBBox().GetY(), locGame.FCharacterList[1].GetBBox().GetWidth(), locGame.FCharacterList[1].GetBBox().GetHeight() );
	
	//LOGC("pos (0) %f, %f, %f \n ", locGame.FCharacterList[0].GetPosition().X, locGame.FCharacterList[0].GetPosition().Y, locGame.FCharacterList[0].GetPosition().Z );
	//LOGC("pos (1) %f, %f, %f   \n", locGame.FCharacterList[1].GetPosition().X, locGame.FCharacterList[1].GetPosition().Y, locGame.FCharacterList[1].GetPosition().Z );
	
	
//	vector2df locDistance( (locGame.FCharacterList[0].GetPosition().X - locGame.FCharacterList[1].GetPosition().X), (locGame.FCharacterList[0].GetPosition().Y - locGame.FCharacterList[1].GetPosition().Y) );
    
	//LOGC("norme %f \n", locDistance.getLength());

	if( locDistance.getLength() < 0.015 ) 
	{
		// TODO dont use two variables to do the same thing : delete use of FGameState
		// Or put it in galeRulesApplicator
		//locGame.FGameState = G_ENDED | G_LOOSE;

		//LOGC("********************** T'es mort ************************************** \n ");
		locGame.SetCurrentState() = GS_LOSE_GAME;

	}



	/*
	if( locGame.FCharacterList[0].GetBBox().Intersect( locGame.FCharacterList[1].GetBBox() ) ) {
		//LOGC(" ****** COLLISION VICTIM / HUNTER ********* \n");
		locGame.FGameState = G_ENDED | G_LOOSE;

		LOGC("********************** T'es mort ************************************** \n ");
		locGame.SetCurrentState() = GS_LOSE_GAME;
	}
	*/
	// check if current player not in collision (change position otherwise)
	CheckCollisonWithObject( locGame.FCharacterList[0], locGame.FBBoxAroundCharacter, parGameLoopData);
//
//
//	if( locGame.FGameConfig.GetNumberOfPlayers() == NP_SOLO ) 
//	{
//		// Zone around the IA
//		array<int2> locCornerIA;
//
//		// update list 
//		locCornerIA = locGame.FMap->GetCornersForBoundingBox_WithClamp(locGame.FBBoxZoneIA);
//
//		// ereaselist
//		locGame.FBBoxAroundIA.reset();
//
//		u32 locTmp = 0;
//		for(u32 i=locGame.FMap->GetWidth() - locCornerIA[2].X; i < locGame.FMap->GetWidth() - locCornerIA[0].X; ++i)
//		{
//			for (int j=locCornerIA[0].Y; j < locCornerIA[1].Y; ++j)
//			{
//				//LOGC("LOOKING in FMap->GetBlocksMeshIds()[%d] : \n", i);
//				// Read list of Mesh in this block
//				locTmp = (locGame.FMap->GetBlocksMeshIds())[i*locGame.FMap->GetWidth() + j].size();
//				for(u32 k=0; k < locTmp ; ++k)
//				{
//					// Read the mesh id and transformation id
//					// first : meshId
//					// second : transformation id
//					pair<u32, u32> locBlockInfo = (locGame.FMap->GetBlocksMeshIds())[i*locGame.FMap->GetWidth() + j][k];
//					LAssert(locBlockInfo.first <  locGame.FMap->GetMeshResources().size());
//							
//					//LOGC("\tExamine block %d : info(%d, %d)\n", j, locBlockInfo.first, locBlockInfo.second);
//							
//					engine::object::TMeshResource* locMeshData = locGame.FMap->GetMeshResources()[locBlockInfo.first];
//							
//					if(locMeshData->GetCheckIAState( locBlockInfo.second ) & NOT_CHECKIA)
//					{
//						//LOGC("\t\tDraw Mesh\n");
//						// Set mesh as drawn
//						locMeshData->SetCheckIAState(locBlockInfo.second, CHECKIA);
//								
//						// add the element in the bboxIA list
//						locGame.FBBoxAroundIA.push_back( locMeshData->GetBBox2Df(locBlockInfo.second) );
//					}
//				}
//			}
//
//			// checkCollision IA
//			CheckCollisonWithObject( locGame.FCharacterList[1], locGame.FBBoxAroundIA );
//	
//		}
//	}
	// TODO
	// envoyer dif à l'autre PSP
	//LOGC("### Act End ###\n");
}
//--------------------------------------------------------------------------------
//********************************************************************************
//--------------------------------------------------------------------------------
}
}