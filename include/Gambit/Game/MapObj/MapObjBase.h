#include <cafe.h>
#include "../GambitActor.h"
#include <sead/math/seadVector.h>

namespace Game {

class MapObjBase : public GambitActor {

    struct SomeHealthRelatedObj {
        int unk1;
        float mHp;
    };

public:
    virtual ~MapObjBase() {} // stub until I feel like listing all of the vfuncs

    
    int dword_50;
    s32 dword_54;
    u8 gap_58[44];
    u8 byte_84;
    u8 gap_85[47];
    u8 byte_b4;
    u8 gap_B5[47];
    float float_e4;
    float float_e8;
    float float_ec;
    float float_f0;
    sead::Vector3f _F4;
    float float_100;
    u8 gap_104[8];
    float float_10c;
    u8 gap_110[20];
    sead::Vector3f _124;
    int dword_130;
    int dword_134;
    int dword_138;
    int dword_13c;
    s8 byte_140;
    u8 gap_141[3];
    int dword_144;
    int dword_148;
    int dword_14c;
    int dword_150;
    int dword_154;
    int dword_158;
    u8 byte_15c;
    u8 gap_15D[3];
    int dword_160;
    int dword_164;
    int dword_168;
    u8 byte_16c;
    u8 byte_16d;
    u8 byte_16e;
    u8 gap_16F;
    float float_170;
    u8 byte_174;
    u8 byte_175;
    u8 gap_176[2];
    float float_178;
    float float_17c;
    u8 gap_180[8];
    float float_188;
    u8 gap_18C[8];
    u8 byte_194;
    u8 byte_195;
    u8 gap_196[2];
    s16 word_198;
    s16 word_19a;
    s32 dword_19c;
    s32 dword_1a0;
    SomeHealthRelatedObj *mHealthRelatedObj;
    int dword_1a8;
    u8 byte_1ac;
    u8 gap_1AD[3];
    int dword_1b0;
    int dword_1b4;
    u8 byte_1b8;
    u8 pad[3];

   //TODO: List all of the (virtual) methods
};

 class MapObjBaseKCol : public MapObjBase {

        // same size as parent, just too lazy to list methods
        public:
            virtual ~MapObjBaseKCol(){}
    };

    static_assert(sizeof(MapObjBase) == 0x1BC, "Game::MapObjBase size mismatch");
    static_assert(sizeof(MapObjBaseKCol) == 0x1BC, "Game::MapObjBaseKCol size mismatch");
} // namespace Game