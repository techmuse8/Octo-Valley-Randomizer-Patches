#include <Gambit/Game/GambitActor.h>
#include <sead/math/seadVector.h>

namespace Game {

class ItemBase : public GambitActor { // TODO: List all the (virtual) methods
  public:
    struct ItemBaseSubstruct1 {
        u8 ItemBaseSubstruct1Pad[36];
    };

    struct ItemBaseSubstruct2 {
        u32 _unk1;
        u32 _unk2;
        void* vtable;
    };

    u32* _50;
    ItemBaseSubstruct1 substruct1;
    u8 pad1[10];
    sead::Vector3f _84;
    u8 _90;
    u32 _94;
    u32 _98;
    float _9C;
    float _A0;
    float _A4;
    float _A8;
    float _AC;
    u8 pad2[12];
    u32 _BC;
    u32 _C0;
    u32 _C4;
    u8 pad3[16];
    u32 _D8;
    u16 _DC;
    u16 _DE;
    u32 _E0;
    u32 _E4;
    u8 pad4[12];
    sead::Vector3f _F4;
    sead::Vector3f _100;
    sead::Vector3f _10C;
    ItemBaseSubstruct2 _118;
    float _124;
    float _128;
    u16 _12C;
    u8 pad6[24];
    u32 _148;
    u32 _14C;

    int postGotByPlayer(int a2); // unsure if this is the correct name
};

} // namespace Game
