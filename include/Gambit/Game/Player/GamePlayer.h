#include <Game/GambitActor.h>
#include <Game/StateMachine.h>
#include <sead/gfx/seadColor.h>
#include <sead/math/seadVector.h>
#include <sead/prim/seadSafeString.h>

namespace Game {

class Player : public GambitActor {

  public:
    virtual ~Player() {} // stub until I feel like listing all of the vfuncs cause there's alot

    int _50;
    int _54;
    int _58;
    int _5C;
    sead::FixedSafeString<128>* _60;
    int _64;
    sead::Color4f _68;
    int mWeaponId;
    char _7C[32];
    int _9C;
    char _A0[4]; ///< padding?
    int _A4;
    int _A8;
    char _AC[8];
    char _B4[84];
    char _108[8];
    char _110[8];
    char _118[4]; ///< padding?
    char _11C[12];
    char _128[36]; ///< some kind of struct
    char _14C[24];
    Game::StateMachine mStateMachine;
    char _19C[172];
    sead::Vector3f mPosition;
    char _254[304];
    sead::Vector3f _384;
    sead::Vector3f _390;
    sead::Vector3f _39C;
    sead::Vector3f _3A8;
    u8 _3B4[1758];

    // TODO: List all of the (virtual) methods
};
static_assert(sizeof(Player) == 0xA94, "Game::Player size mismatch");
} // namespace Game