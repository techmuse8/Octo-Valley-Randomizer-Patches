#include <cafe.h>
#include "GatewayBase.h"
#include "../StateMachine.h"
#include <sead/prim/seadSafeString.h>
namespace Game {

class GatewayNormal : public GatewayBase {

  public:
    virtual ~GatewayNormal() {} // stub until I feel like listing all of the vfuncs

    Game::StateMachine* mStateMachine;
    void* _514;
    u8 _518;
    u8 pad1[6];
    u8 _51F;
    u8 _520;
    u8 _521;
    u8 _522;
    u8 _523;
    u8 _524;
    u8 _525;
    u8 pad2[34];
    u8 _548;
    u8 pad3[3];
    s32 _54C;
    s32 _550;
    s32 _554;
    u8 _558;
    u8 _559;
    u8 _55A;
    u8 _55B;
    sead::Vector3f vec;
    u8 pad4[56];

    //TODO: List all of the (virtual) methods
};

 static_assert(sizeof(GatewayNormal) == 0x5A0, "Game::GatewayNormal size mismatch");
} // namespace Game
