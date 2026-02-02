#include <types.h>
#include <sead/heap/seadDisposer.h>
#include "ActorMgr.h"

namespace Game {

class Player;

class PlayerMgr : public ActorMgr {

  public:
    virtual ~PlayerMgr() {} // stub to replace later

    u8 unk[0x334-0x238];

    PlayerMgr();

    int getCurPlayerIdx();
    Player * getControlledPerformer(int a1);

    // ...

};
static_assert(sizeof(PlayerMgr) == 0x334, "Game::PlayerMgr size mismatch");
} // namespace Game