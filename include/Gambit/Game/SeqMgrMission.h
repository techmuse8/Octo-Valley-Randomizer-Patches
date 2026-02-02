#include <Lp/Utl/TextureHolder.h>
#include "SeqMgrBase.h"
#include "StateMachine.h"

namespace Game {

class SeqMgrMission : public SeqMgr {
  public:
    u8 _248;
    u8 unk_249[3];
    int _24C;
    int _250;
    int _254;
    u8 _258;
    bool mIsLastCheckpoint;
    u8 unk_25A[2];
    int _25C;
    int _260;
    int _264;
    u8 mIsAncientDocumentCollected;
    u8 unk_269[3];
    int _26C;
    u8 _270;
    u8 _271;
    u8 unk_272[2];
    StateMachine mStateMachine;
    u8 _2AC;
    u8 _2AD;
    u8 unk_2AE[2];
    int _2B0;
    int _2B4;
    int _2B8;
    int mLifeCount;
    float _2C0;
    int _2C4;
    u8 _2C8;
    u8 unk_2C9[3];
    int _2CC;
    Lp::Utl::TextureHolder mTextureHolder;
    int _63C;
    u8 _640;
    u8 _641;

    void checkpointStuff(bool isLastCheck, bool unk);
    void startActorManageDemo();

    // custom helper
    static SeqMgrMission* getInstance() {
        static SeqMgrMission* instance = nullptr;
        if (!instance)
            instance = MainMgrBase::sInstance->mSeqMgrMission;
        return instance;
    }
};

static_assert(sizeof(SeqMgrMission) == 0x644, "Game::SeqMgrMission size mismatch");
} // namespace Game