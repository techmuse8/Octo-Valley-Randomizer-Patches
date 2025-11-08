#include <cafe.h>

// TODO: Maybe abandon these headers altogether?
#include "SaveDataCmn.h"
#include "SaveDataVss.h"
#include "SaveDataMsn.h"

class SaveDataBuffer // This is what gets written to save.dat
{
  // Save header
  int _0;
  int _4;
  u32 checksum;
  int _C;
  // Save body
  Cmn::SaveDataCmnData mSaveDataCmn;
  Cmn::SaveDataVssData mSaveDataVss;
  Cmn::SaveDataMsnData mSaveDataMsn;
  u8 SaveDataSection3[0x7E0]; // Shop related?
  u8 SaveDataSection4[0x120]; // Minigames? This is just a wild guess
  u8 SaveDataPlazaData[0x1840]; // Placeholders to document later
  u8 SaveDataAmiiboData[0x640]; // ^
};

namespace Cmn {

class SaveData
{
public:
  u8 pad[4];
  void *vtable;
  int unk2;
  int unk3;
  SaveDataCmnData mSaveDataCmn;
  u8 section0Footer[16];
  SaveDataVssData mSaveDataVss;
  u8 section1Footer[16];
  SaveDataMsnData mSaveDataMsn;
  u8 section2Footer[16];
  u8 SaveDataSection3[0x7E0]; // Shop related?
  u8 section3Footer[16];
  u8 SaveDataSection4[0x120]; // Minigames? This is just a wild guess
  u8 section4Footer[16];
  u8 SaveDataPlazaData[0x1840]; // Placeholders to document later
  u8 section5Footer[16];
  u8 SaveDataAmiiboData[0x640]; // Placeholders to document later
  u8 section6Footer[16];
};

static_assert(sizeof(SaveData) == 0xD2F0, "Cmn::SaveData size mismatch");
}

static_assert(sizeof(SaveDataBuffer) == 0xD280, "Cmn::SaveDataBuffer size mismatch");