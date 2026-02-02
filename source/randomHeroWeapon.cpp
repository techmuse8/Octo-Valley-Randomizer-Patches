#include <cafe.h>
#include <mod/rando.h>
#include <Gambit/Cmn/Mush/MushWeaponInfo.h>
#include <sead/random/seadGlobalRandom.h>
#include <sead/filedevice/seadFileDevice.h>
#include <sead/filedevice/seadFileDeviceMgr.h>

extern "C" u32 randomizeHeroWeapon(Cmn::MushWeaponInfo* this_, int* param_2, int heroShotLvl) {
    LOG("Hero Shot level: %d\n", heroShotLvl);
    bool isWeaponRandoOn = rando::gSettings.isWeaponRandoOn;

    if (isWeaponRandoOn) {
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
