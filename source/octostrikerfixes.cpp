#include <cafe.h>
#include <Game/MainMgrBase.h>
#include <Game/SeqMgrMission.h>
#include <Cmn/StaticMem.h>

namespace Game {
// Don't feel like making a header for this atm
class TakopterTornado;
} // namespace Game

// see above
void TakopterTornado_startPlayerDemoPlace(Game::TakopterTornado* _this);

extern "C" bool isInOctostrikerStage() {
    sead::SafeString* currentMapName = &Cmn::StaticMem::instance()->mMapFileName1;

    if (currentMapName->comparen("Fld_Oct", 7) == 0) {
        LOG("In octostriker stage\n");
        return 1;
    }
    else return 0;
}

void controlDemoPlace(Game::TakopterTornado* _this) {
    bool isLastCheck = Game::SeqMgrMission::getInstance()->mIsLastCheckpoint;
    LOG("controlDemoPlace: isLastCheckpoint: %d\n", isLastCheck);

    if (!isInOctostrikerStage())
        return;

    if (isLastCheck)
        TakopterTornado_startPlayerDemoPlace(_this);
    else return;
}

void controlLastCheckMusic(Game::SeqMgrMission *_this, bool isLastCheck, bool unk) {
    bool isLastCheckpoint = Game::SeqMgrMission::getInstance()->mIsLastCheckpoint;
    LOG("controlLastCheckMusic: isLastCheckpoint: %d\n", isLastCheck);

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
