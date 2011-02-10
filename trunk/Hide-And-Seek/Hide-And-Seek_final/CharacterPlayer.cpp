#include "CharacterPlayer.h"
#include "Character.h"
#include "vector3d.h"
#include "BoundingBox2D.h"
#include "Common.h"

namespace psp { namespace game {

TCharacterPlayer::TCharacterPlayer()
{
	//FPosition = engine::core::vector3df(-0.6f, 0.f, 0.87f);
	FPosition = engine::core::vector3df(0.43f, 0.f, -1.06f);
	FDirection = engine::core::vector3df(0.f, 0.f, -1.f);
	FSpeed = 0.f;
	FOrder = CO_NOTHING;
	FRole = CR_VICTIM;
	
	/*
	bool locLocMD2 = FMD2->Load( ICharacter::MD2_VICTIM.c_str() );

	if( locLocMD2 )
	{
		// Mesh buffer pour recuperer la bbox du perso 
		FBBox = FMD2->GetMeshBuffer(0).GetBBox2D();
	}
	*/

	//*
	// TODO : delete it now if its not necessary
	// TEMPORAIRE
	FBBox.AddPoint(-0.2f, 0.2f);
	FBBox.AddPoint(0.2f, -0.2f);
	
	//*/
}

TCharacterPlayer::TCharacterPlayer(CharacterRole parRole)
{
	FPosition = engine::core::vector3df(0.f, 0.f, 2.f);
	FDirection = engine::core::vector3df(0.f, 0.f, -1.f);
	FSpeed = 0.f;
	FOrder = CO_NOTHING;
	FRole = parRole;

	/*
	bool locLocMD2 = false;

	if( FRole == CR_VICTIM )
		locLocMD2 = FMD2->Load( ICharacter::MD2_VICTIM.c_str() );
	else 
		locLocMD2 = FMD2->Load( ICharacter::MD2_HUNTER.c_str() );

	if( locLocMD2 )
	{
		// Mesh buffer pour recuperer la bbox du perso 
		FBBox = FMD2->GetMeshBuffer(0).GetBBox2D();
	}
	*/

	// TEMPORAIRE
	FBBox.AddPoint(0.f, 0.f);
	FBBox.AddPoint(0.f, 1.f);
	FBBox.AddPoint(1.f, 0.f);
	FBBox.AddPoint(1.f, 1.f);
	
}
TCharacterPlayer::TCharacterPlayer(engine::core::vector3df parPosition, engine::core::vector3df parDirection, f32 parSpeed, CharacterRole parRole)
{
	FPosition = parPosition;
	FDirection = parDirection;
	FSpeed = parSpeed;
	FOrder = CO_NOTHING;
	FRole = parRole;

	/*
	bool locLocMD2 = false;

	if( FRole == CR_VICTIM )
		locLocMD2 = FMD2->Load( ICharacter::MD2_VICTIM.c_str() );
	else 
		locLocMD2 = FMD2->Load( ICharacter::MD2_HUNTER.c_str() );

	if( locLocMD2 )
	{
		// Mesh buffer pour recuperer la bbox du perso 
		FBBox = FMD2->GetMeshBuffer(0).GetBBox2D();
	}
	*/


	
	// TEMPORAIRE
	FBBox = engine::core::TBoundingBox2D<f32>();
	FBBox.AddPoint(0.f, 0.f);
	FBBox.AddPoint(0.f, 1.f);
	FBBox.AddPoint(1.f, 0.f);
	FBBox.AddPoint(1.f, 1.f);
	
}

TCharacterPlayer::~TCharacterPlayer()
{}

} // namespace game
} // namespace psp