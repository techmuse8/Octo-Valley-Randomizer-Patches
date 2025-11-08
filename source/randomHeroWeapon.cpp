#include <cafe.h>
#include <Gambit/Cmn/Mush/MushWeaponInfo.h>
#include <sead/random/seadRandom.h>
#include <sead/random/seadGlobalRandom.h>
#include <sead/filedevice/seadFileDevice.h>
#include <sead/filedevice/seadFileDeviceMgr.h>

extern "C" u32 randomizeHeroWeapon(Cmn::MushWeaponInfo* this_, int* param_2, int heroShotLvl) {

    LOG("Hero shot level %d\n", heroShotLvl);

    sead::FileHandle fileHandle;
    sead::FileDevice* randoSettings;
    // TODO: Replace this with a proper rando config system
    randoSettings =
        sead::FileDeviceMgr::instance()->tryOpen(&fileHandle, "main://Rando/weapon_randomizer_on.bin", sead::FileDevice::cFileOpenFlag_ReadOnly, 0);

    if (randoSettings) {
        switch (sead::GlobalRandom::instance()->getU32(3)) {
            case 0:
                return this_->searchIdByMsnShotLv(param_2, heroShotLvl); // Hero Shot at current level
            case 1:
                return 1200; // Hero Charger
            case 2:
                return 1100; // Hero Roller
            default:
                return this_->searchIdByMsnShotLv(param_2, heroShotLvl);
        }
    }
    else
        return this_->searchIdByMsnShotLv(param_2, heroShotLvl);
}
