#ifndef CHARACTER_PLAYER_H
#define CHARACTER_PLAYER_H

#include "Character.h"
#include "config.h"
#include "vector3d.h"

namespace psp { namespace game {

class TCharacterPlayer : public ICharacter
{
public:
	TCharacterPlayer();
	TCharacterPlayer(CharacterRole parRole);
	TCharacterPlayer(engine::core::vector3df parPosition, engine::core::vector3df parDirection, f32 parSpeed, CharacterRole parRole);
	virtual ~TCharacterPlayer();
};

} // namespace game
} // namespace psp

#endif
