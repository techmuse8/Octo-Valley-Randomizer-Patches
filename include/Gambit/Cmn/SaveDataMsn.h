#include <cafe.h>

namespace Cmn {

struct MissionEntry {
    int missionId;
    int zapfishStatus;
    int sunkenScrollStatus;
};

struct __attribute__((aligned(4))) SaveDataMsnData {
    MissionEntry missions[64];
    u8 unk1[40];
    s32 powerEggCount;
    u8 unk2[284];
};

class SaveDataMsn {

  public:
    class Body;

    virtual ~SaveDataMsn();
    virtual int getSaveData();
    virtual void vf14(); // Deleted
    virtual void vf1C(); // Deleted

    SaveDataMsn();

    bool isMapRegistered(int mapNumber);
    void getMap(int mapNumber);
    bool isAncientItemDocumentCollected(int mapNumber, u32* unk);
    int unk_21ACC50(int* unk1, int unk2);
    bool unk_21ACC90(int* unk1, int unk2);
    int unk_21ACD84(); // Loops through every level entry in the save for something
    bool unk_21ACE04(int unk1);
    int unk_21ACEA4();
    int unk_21ACED4();
    int unk_21ACF04();
    int unk_21ACF34(int unk1); // Called by Game::LytWorldHandler::LytWorldHandler (unofficial name) and others, seems related to weapon upgrade levels
    u32 getIkuraNum();         // Ikura = Power Egg
    u32 unk_21ACFD4(int unk1); // called by 0x02776A48
    int unk_21AD46C(int unk1); // same as above
    int unk_21AD4F0();
    int unk_21AD53C();                           // Seems to be related to save corruption? Called by 0x02009B38
    static int unk_21AD56C(SaveDataMsnData* a1); // Related to some kind of save data initialization/verification
    static int unk_21AD5A0(SaveDataMsn::Body);

    // Just a few more methods to list here

    // void *vtable;
    int unk1;
    Body* pSaveDataMsn;
};

class SaveDataMsn::Body : public SaveDataMsn {

  public:
    ~Body() override;
    int getSaveData() override; // Returns a pointer to the SaveDataMsn buffer
    void vf14() override;        // Deleted
    void vf1C() override;        // Deleted

    Body();

    void flushSaveMaybe(); // Called after you are done using the savefile and before the class dtor is called
    void registerMap(int mapNumber);
    void setMap(int mapNumber, int* zapfishStatus);
    void unk_21AD7D4(int mapNumber, s32* unk2,
                     int unk3); // Called by Game::SeqMgrMission::processSave_, first arg is from the return value of Cmn::MushMapInfo::searchByName
    void unk_21AD8DC(int* a1, int a2);
    void unk_21AD9A0(u32 a1); // sets mSaveDataMsn->0x310 (unk) to a1 if a1 < 4, likely some flag
    void unk_21AD9B4(u32 a1); // sets mSaveDataMsn->0x314 (unk) to a1 if a1 < 4, likely some flag
    void unk_21AD9C0(u32 a1); // sets mSaveDataMsn->0x318 (unk) to a1 if a1 < 3, likely some flag
    void unk_21AD9D0(u32 a1); // sets mSaveDataMsn->0x31C
    void setIkuraCount(u32 a1);
    void unk_21ADA08(int a1, int a2); // called by 0x2776C90
    void unk_21ADA4C(int a1);         // called by 0x2776C40

    // Just a few more methods to list here

    int unk1;
    SaveDataMsnData mSaveDataMsn;
};

static_assert(sizeof(SaveDataMsn) == 0xC, "Cmn::SaveDataMsn size mismatch");
static_assert(sizeof(SaveDataMsnData) == 0x448, "Cmn::SaveDataMsnData size mismatch");
static_assert(sizeof(SaveDataMsn::Body) == 0x458, "Cmn::SaveDataMsn::Body size mismatch");
} // namespace Cmn
