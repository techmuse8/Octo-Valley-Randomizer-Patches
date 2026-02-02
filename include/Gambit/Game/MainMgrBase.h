#include <types.h>
#include <sead/heap/seadDisposer.h>
#include "ActorMgr.h"

namespace Game {

class PlayerMgr;
class EnemyMgr;
class SeqMgrMission;


class MainMgrBase : public ActorMgr, sead::IDisposer {

  public:
    virtual ~MainMgrBase() {} // stub to replace later

    static MainMgrBase* sInstance;
    
    int _248;
    int _24C;
    int *_250;
    u8 unk_254[20];
    PlayerMgr *mPlayerMgr;
    EnemyMgr *mEnemyMgr;
    u8 unk_270[52];
    SeqMgrMission *mSeqMgrMission;
    u8 unk_2A8[44];

    MainMgrBase();
};
static_assert(sizeof(MainMgrBase) == 0x2D4, "Game::MainMgrBase size mismatch");
} // namespace Game