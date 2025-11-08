#pragma once

#include <types.h>

namespace Cmn {
namespace Def {

    enum Mode {
        cVSGame         = 0x0,
        cMission        = 0x1,
        cPlaza          = 0x2,
        cWorld          = 0x3,
        cTutForShow     = 0x4,
        cTutorial       = 0x5,
        cDuel           = 0x6,
        cDuelSetting    = 0x7,
        cShootingRange  = 0x8,
        cWalkThrough    = 0x9,
        cStaffRoll      = 0xA,
        cLobby          = 0xB,
        cShop           = 0xC,
        cCustomize      = 0xD,
        cFreeTest       = 0xE,
        cDbgSetting     = 0xF,
        cBoot           = 0x10,
    };

    extern void getCurMode(int * retMode);

    inline Cmn::Def::Mode getCurMode() { // custom helper function to the mode ID's line up with what's defined above
    int rawMode = 0;
    Cmn::Def::getCurMode(&rawMode);
    return static_cast<Cmn::Def::Mode>(rawMode);
    }

} // namespace Def
} // namespace Cmn