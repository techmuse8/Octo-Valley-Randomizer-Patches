#include <cafe.h>

namespace Cmn {

class SaveDataCmnData;

class SaveDataCmn {
  public:
    class Body;

    virtual ~SaveDataCmn();
    virtual int getSaveData();

    int unk1;
   // void* vtable;
    Body* mSaveDataCmn;

    SaveDataCmn();

    //TODO: List all of the methods
};

struct SaveDataCmnData {
    u8 _0[4];
    int _4;
    u16 _8;
    u16 _A;
    u8 _C[4];
    u8 _10[4];
    int mSomeBitFlags;
    u8 pad[344];
};

class SaveDataCmn::Body : public SaveDataCmn {

    ~Body() override;
    int getSaveData() override;

    int unk1;
    SaveDataCmnData mSaveDataCmn;

    //TODO: List all of the methods

};
static_assert(sizeof(SaveDataCmn) == 0xC, "Cmn::SaveDataCmnData size mismatch");
static_assert(sizeof(SaveDataCmnData) == 0x170, "Cmn::SaveDataCmnData size mismatch");
static_assert(sizeof(SaveDataCmn::Body) == 0x180, "Cmn::SaveDataCmn::Body size mismatch");
} // namespace Cmn
