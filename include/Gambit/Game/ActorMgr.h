#pragma once

#include <types.h>
#include <sead/container/seadListImpl.h>
#include "../Cmn/Actor.h"

namespace Game {

class ActorMgr : public Cmn::Actor {

    class ActorFactory;
    class SomeActorMetadata; // ctor is at 0x0285CCF4

    struct SomeActorMetadata {
        sead::ListNode head;
        int mPtrs;
        int _C;
    };

  public:
    virtual ~ActorMgr() {} // stub to replace later

    int unk1;
    int _2C;
    ActorFactory** mFactories;
    SomeActorMetadata _34[13];
    u8 mFactoryIndicies[256];
    char _108[52];

    ActorMgr();
};
static_assert(sizeof(ActorMgr) == 0x238, "Game::ActorMgr size mismatch");
} // namespace Game