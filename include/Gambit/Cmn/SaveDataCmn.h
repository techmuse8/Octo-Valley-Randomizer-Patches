#include <cafe.h>
#include <sead/prim/seadBitFlag.h>

namespace Cmn {

class SaveDataCmnData;

class SaveDataCmn {
  public:
    class Body;

    enum BitFlags {
        cFlags_FinishedTutorial = 0x0,
        cFlags_SeenOctoValleyIntro = 0x4,
    };

    virtual ~SaveDataCmn();
    virtual Body* getSaveData();

    int unk1;
    Body* mSaveDataCmn;

    SaveDataCmn();

    bool isSomeFlagSet(int* bit); // deals with mSomeBitFlags

    // TODO: List all of the methods
};

struct SaveDataCmnData {
    u8 _0[4];
    int _4;
    u16 _8;
    u16 _A;
    int __C;
    sead::BitFlag<u64> mSomeBitFlags; // Is this a u64? Seems so, but idk yet
    u8 pad[340];
};

class SaveDataCmn::Body : public SaveDataCmn {

  public:
    ~Body() override;
    Cmn::SaveDataCmn::Body * getSaveData() override;

    int unk1;
    SaveDataCmnData mSaveDataCmnData;

    Body();

    void setFlags(BitFlags* bit, bool state);
    void flushSave();

    // TODO: List all of the methods
};
static_assert(sizeof(SaveDataCmn) == 0xC, "Cmn::SaveDataCmnData size mismatch");
static_assert(sizeof(SaveDataCmnData) == 0x170, "Cmn::SaveDataCmnData size mismatch");
static_assert(sizeof(SaveDataCmn::Body) == 0x180, "Cmn::SaveDataCmn::Body size mismatch");
} // namespace Cmn
