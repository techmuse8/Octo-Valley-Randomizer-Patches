#pragma once
#include <Cmn/SaveData.h>
#include <cafe.h>

class SaveDataMgr {
  public:
    virtual void vfC(); // Deleted
    virtual void vf14(); // Deleted
    virtual void proc();
    virtual void vf24(int a1); // If a1 == 2, call unk_21F8030
    virtual void vf2C();       // Nullsub
    virtual int getSaveDataBufferPointer();
    virtual int getBufferSize();
    virtual int someGetSaveHashWrapper(); // Calls getSaveDataHash with the save
                                          // buffer ptr passed in

    SaveDataMgr();
    void unk_21F8030();
    int makeSaveDataPtr();
    void calcAllHashes();
    int moreCalcHash(int a1, int a2, int a3, int* a4, int a5);
    int save();
    bool unk_21F83C0(); // Called by Game::BootScene::saveStuff (0x027B351C)
    bool unk_21F83D4(); // Sets SaveDataBuffer->_4 to 6, called by above function,
                        // seems to check for valid header
    bool getSaveChecksum();

    void* unk1;
    Cmn::SaveData* mSaveData;
    SaveDataBuffer* mSaveDataBuffer;
    int pad1[15];
    int mSectionHashArray[7];

    
};

static_assert(sizeof(SaveDataMgr) == 0x68, "SaveDataMgr size mismatch");
