#include <mod/rando.h>
#include <Cmn/Mush/MushWeaponInfo.h>
#include <sead/random/seadGlobalRandom.h>

#define TELKIN_REGISTERS
#include <telkin/Assembly.h>
#include <telkin/Hooks.h>
#include <telkin/Print.h>

u32 randomizeHeroWeapon(Cmn::MushWeaponInfo* this_, int* param_2, int heroShotLvl) {
    tk::print("Hero Shot level: %d\n", heroShotLvl);
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

using namespace tk::ppc;
#include <telkin/UndefineRegisters.h>

tBranch(0x021a9b24, randomizeHeroWeapon, tk::BranchType::bl); 
tPatch32u(0x021a9b2c, mr(R::r5, R::r3)); // Moves the returned randomized weapon in r3 to r5
tPatch32u(0x0222D750, li(R::r3, 1)); // Makes the Hero Roller's bullets load in Octo Valley, credits to Pirlo for this one