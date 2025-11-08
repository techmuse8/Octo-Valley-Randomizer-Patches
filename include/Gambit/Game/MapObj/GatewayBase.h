#include <cafe.h>
#include "MapObjBase.h"
#include <sead/prim/seadSafeString.h>
namespace Game {

class GatewayBase : public MapObjBaseKCol {

  public:
    virtual ~GatewayBase() {} // stub until I feel like listing all of the vfuncs

    int field_1BC;
    int field_1C0;
    sead::BufferedSafeStringBase<char> mMapFileName1;
    char mMapFileNameData1[256];
    sead::BufferedSafeStringBase<char> mMapFileName2;
    char mMapFileNameData2[256];
    char field_3DC;
    char field_3DD;
    u8 gap_3DE[2];
    int field_3E0;
    int* field_3E4;
    int mMapNumber;
    int field_3EC;
    int field_3F0;
    u8 gap_3F4[280];
    u8 field_50C;
    u8 field_50D;
    u8 pad[2];

    //TODO: List all of the (virtual) methods
};
static_assert(sizeof(GatewayBase) == 0x510, "Game::GatewayBase size mismatch");
} // namespace Game