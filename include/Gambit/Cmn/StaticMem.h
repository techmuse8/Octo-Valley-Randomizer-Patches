#pragma once
#include <sead/gfx/seadColor.h>
#include <sead/heap/seadDisposer.h>
#include <sead/prim/seadSafeString.h>

namespace Cmn {

class StaticMem 
{
   SEAD_SINGLETON_DISPOSER(StaticMem);
public:

    u8 unk_0[0x1C - 0x10];
    sead::FixedSafeString<256> mMapFileName1;
    sead::FixedSafeString<256> mMapFileName2;
    char unk_234[64];
    char _274[60];
    char _2B0[48];
    sead::Color4f mTeamAlphaColor;
    sead::Color4f mTeamBravoColor;
    sead::Color4f mNeutralColor;
    char _310[0x310 - 0x300];
    sead::FixedSafeString<256> mSomeMapFileName3;
    char _32C[36]; // fix this offset
};

static_assert(sizeof(StaticMem) == 0x450, "Cmn::StaticMem size mismatch");

} // namespace Cmn
