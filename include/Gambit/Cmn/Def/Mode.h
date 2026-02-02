#pragma once

#include <types.h>

namespace Cmn {
namespace Def {

    enum Mode {
       cMode_VSGame         = 0x0,
       cMode_Mission        = 0x1,
       cMode_Plaza          = 0x2,
       cMode_World          = 0x3,
       cMode_TutForShow     = 0x4,
       cMode_Tutorial       = 0x5,
       cMode_Duel           = 0x6,
       cMode_DuelSetting    = 0x7,
       cMode_ShootingRange  = 0x8,
       cMode_WalkThrough    = 0x9,
       cMode_StaffRoll      = 0xA,
       cMode_Lobby          = 0xB,
       cMode_Shop           = 0xC,
       cMode_Customize      = 0xD,
       cMode_FreeTest       = 0xE,
       cMode_DbgSetting     = 0xF,
       cMode_Boot           = 0x10,
    };

    extern void getCurMode(int * retMode);

    inline Cmn::Def::Mode getCurMode() { // custom helper function to the mode ID's line up with what's defined above
    int rawMode = 0;
    Cmn::Def::getCurMode(&rawMode);
    return static_cast<Cmn::Def::Mode>(rawMode);
    }

} // namespace Def
} // namespace Cmn