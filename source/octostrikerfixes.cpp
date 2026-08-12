#include <cafe.h>
#include <Game/MainMgrBase.h>
#include <Game/SeqMgrMission.h>
#include <Cmn/StaticMem.h>

#define TELKIN_REGISTERS
#include <telkin/Assembly.h>
#include <telkin/Hooks.h>
#include <telkin/Print.h>

namespace Game {
// Don't feel like making a header for this atm
class TakopterTornado;
} // namespace Game

// see above
void TakopterTornado_startPlayerDemoPlace(Game::TakopterTornado* _this);


extern "C" {
const char* normalOctostrikerDieDemoState = "StateTornado::cDieDemo";
const char* hijackedOctostrikerDieDemoState = "StateTornado::cNopDemo";
}

extern "C" bool isInOctostrikerStage() {
    sead::SafeString* currentMapName = &Cmn::StaticMem::instance()->mMapFileName1;

    if (currentMapName->comparen("Fld_Oct", 7) == 0) {
        tk::print("In octostriker stage\n");
        return 1;
    }
    else return 0;
}

void controlDemoPlace(Game::TakopterTornado* _this) {

    if (!isInOctostrikerStage())
        return;

    // This is perfectly fine as there is normally only
    // one Octostriker per UFO level
    return TakopterTornado_startPlayerDemoPlace(_this);
}

void controlLastCheckMusic(Game::SeqMgrMission *_this, bool isLastCheck, bool unk) {
    bool isLastCheckpoint = Game::SeqMgrMission::getInstance()->mIsLastCheckpoint;
   // tk::print("controlLastCheckMusic: isLastCheckpoint: %d\n", isLastCheck);

    // Don't start the final checkpoint variant music if an Octostriker
    // is defeated beforehand
    if (isLastCheckpoint)
        return _this->checkpointStuff(isLastCheck, unk);

    else return;
}

void controlActorManageDemo(Game::SeqMgrMission* _this) {
    if (!isInOctostrikerStage())
        return;

    else return _this->startActorManageDemo();
}

void controlInkSplatter() tAssembly(
// So here's a bit of a hack

// The game determines on whether or not to play the screen ink splatter effect
// that occurs after defeating an Octostriker if its current state name is "StateTornado::cDieDemo",
// as part of the game's XLink system for linking ingame actions to visual and sound effects.
// We only want the effect to play if the player is in a regular Octostriker stage, so we
// hijack to be something else if those conditions aren't met.

    tSaveVolatileRegisters;
    bl isInOctostrikerStage;
    cmpwi r3, 0; // Are we not in an Octostriker stage?
    beq malformDieDemoStateName; // If true, mess up the state name so the effect won't play
    b loadOriginalStateName;

    malformDieDemoStateName:
        tRestoreVolatileRegisters;
        lis r12, hijackedOctostrikerDieDemoState@ha;
        addi r12, r12, hijackedOctostrikerDieDemoState@l;
        stw r12, 0xC(r1);
        blr;

    loadOriginalStateName:
        tRestoreVolatileRegisters;
        lis r12, normalOctostrikerDieDemoState@ha;
        addi r12, r12, normalOctostrikerDieDemoState@l;
        stw r12, 0xC(r1);
        blr;
)

#include <telkin/UndefineRegisters.h>
tBranch(0x023D4AD0, controlDemoPlace, tk::BranchType::bl); // in Game::MainMgrMission::setCurrentCheckpoint
tBranch(0x023D4BC8, controlLastCheckMusic, tk::BranchType::bl);
tBranch(0x023D5C5C, controlInkSplatter, tk::BranchType::bl); // replaces nullsub call
tBranch(0x023D4810, controlActorManageDemo, tk::BranchType::bl);