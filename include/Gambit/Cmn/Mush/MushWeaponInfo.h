#pragma once

#include <types.h>
#include <Gambit/Cmn/Def/WeaponKind.h>
#include <sead/prim/seadSafeString.h>

namespace Cmn {

class WeaponData; // to be defined later

class MushWeaponInfo {
  public:
    u8 pad[0x30];

    int searchIdByMsnShotLv(int* a1, int shotLevel);
    Cmn::WeaponData* searchByName(sead::SafeStringBase<char> const& weaponName) const;
};
} // namespace Cmn