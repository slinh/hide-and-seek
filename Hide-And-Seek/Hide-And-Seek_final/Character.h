#ifndef CHARACTER_H
#define CHARACTER_H

#include "config.h"
#include "vector3d.h"
#include "BoundingBox2D.h"
#include "AnimatedMeshMD2.h"
#include "NetworkData.h"

namespace psp { namespace game {

#define CP_SPEED_VICTIM 1
#define CP_SPEED_HUNTER 0.75

#define CO_WALK 1
#define CO_RUN 2
#define CO_DASH 4
#define CO_ACTIVATE 8
#define CO_NOTHING 16

#define WALKING_SENSIBILITY 0.15f
#define DIRECTION_SENSIBILITY 0.15f

#define FRAME_PER_UNIT 0.012f

typedef enum characterRole {
	CR_VICTIM = 1, //poursuivi (gentil)
	CR_HUNTER = 2 // poursuivant (méchant)
}CharacterRole;


class ICharacter
{
public:
	ICharacter();

	GETTER(engine::core::vector3df, Position)
	GETTER(engine::core::vector3df, Direction)
	GETTER_SETTER(engine::core::vector3df, DirectionToGo)

	GETTER_SETTER(float, Speed)
	GETTER_SETTER(float, DashSpeed)
	GETTER_SETTER(s32, Order)

	void SetBBox(const ::psp::engine::core::TBoundingBox2D<float>& parValue) { LAssert(parValue.IsInit()) ; FBBox = parValue; }
	const ::psp::engine::core::TBoundingBox2D<float>& GetBBox() const { return FBBox; }

	GETTER_SETTER(CharacterRole, Role)
	GETTER_SETTER(s32, CurrentState)

	GETTER(psp::engine::object::TAnimatedMeshMD2, MD2)

	void SetDirectionToGo(const engine::core::vector3df& parNewDirection) {FDirectionToGo = parNewDirection;}
	void AddOrder(const u32& parOrder);
	void RemoveOrder(const u32& parOrder);

	virtual void Update();

	void SetPositionTo(float parX, float parY);
	
	void SetOrderWalk();
    void SetOrderRun();
    void SetOrderDash();
    void SetOrderActivate();
    void SetOrderNothing();

	virtual ~ICharacter(void){};

protected:
	engine::core::vector3df FPosition;
	engine::core::vector3df FDirection;
	engine::core::vector3df FDirectionToGo;
	f32 FSpeed;
	f32 FDashSpeed;

	engine::core::TBoundingBox2D<float> FBBox;

	s32 FOrder;
	s32 FCurrentState;
	u32 FLastDashStart;
	u32 FLastDashEnd;

	CharacterRole FRole;

	psp::engine::object::TAnimatedMeshMD2 FMD2;

	friend void* ::psp::engine::net::NetworkPacketMaker::Serialize(const TNetworkPacketMetaData& parDiff);
	friend void ::psp::engine::net::NetworkPacketMaker::Deserialize(void* parData);
};

} //namespace game
} // namespace ia

#endif
