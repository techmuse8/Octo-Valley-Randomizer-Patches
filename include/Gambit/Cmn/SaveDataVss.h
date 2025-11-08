#include <cafe.h>

namespace Cmn {

class SaveDataVss {

  public:
    class Body;

    virtual ~SaveDataVss();
    virtual int getSaveData();

    int unk1;
   // void* vtable;
    Body* mSaveDataVss;

    SaveDataVss();

    //TODO: List all of the methods
    
};

// Credits to Shadow for docs on this section
struct SaveDataVssData {
    int mSelectedClothesId;
    int mSelectedShoesId;
    int mSelectedHeadId;
    int _0C;
    int mPlayerModel;
    int mPlayerSkinTone;
    int mPlayerEyeColor;
    char pad1[4];
    char pad2[36864]; // Gear flags related to fill out later
    char pad3[5120]; // ^
    s32 mMoney;
    s32 _A424;
    int mRank;
    s32 mUdemaeGrade;
    s32 _A430;
    int mShell;
    s32 _A438;
    char pad4[252];
    
};

class SaveDataVss::Body : public SaveDataVss {

    ~Body() override;
    int getSaveData() override;

    int unk1;
    SaveDataVssData mSaveDataVss;

    //TODO: List all of the methods
};

} // namespace Cmn