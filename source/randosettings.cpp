#include <mod/rando.h>
#include <ext-libs/minIni.h>
#include <Cmn/SaveDataCmn.h>
#include <Game/GameUtl.h>
#include <Lp/Sys/FileDeviceHolder.h>

#include <telkin/Hooks.h>
#include <telkin/Print.h>

namespace rando {

Settings gSettings;

void initSettings() {
    gSettings.isWeaponRandoOn = ini_getbool("RandomizerSettings", "WeaponRandomizer", 0, "main://Rando/config.ini");
    gSettings.skipOctoValleyIntro = ini_getbool("RandomizerSettings", "SkipOctoValleyIntro", 0, "main://Rando/config.ini");
    gSettings.skipNewsIntro = ini_getbool("RandomizerSettings", "SkipFirstNews", 0, "main://Rando/config.ini");
    gSettings.addOctoValleyRestart = ini_getbool("RandomizerSettings", "OctoValleyRestart", 0, "main://Rando/config.ini");

    tk::print("Weapon randomizer state: %d\n", gSettings.isWeaponRandoOn);
    tk::print("Octo Valley intro skip state: %d\n", gSettings.skipOctoValleyIntro);
    tk::print("Skip news intro state: %d\n", gSettings.skipNewsIntro);
    tk::print("Octo Valley restart button state: %d\n", gSettings.addOctoValleyRestart);
}

int controlOctoValleyIntroState(Cmn::SaveDataCmn *this_, int *bitFlag) {
    if (!gSettings.skipOctoValleyIntro)
        return this_->isSomeFlagSet(bitFlag);
    
    Cmn::SaveDataCmnData& save = this_->mSaveDataCmn->mSaveDataCmnData;
    sead::BitFlag<u64>& someCmnSaveBitFlags = save.mSomeBitFlags;

    // This check is done to ensure that the intro seen flag is still set
    // even with the patch disabled
    if (someCmnSaveBitFlags.isOn(Cmn::SaveDataCmn::cFlags_SeenOctoValleyIntro))
        return 1;

    Cmn::SaveDataCmn::Body cmnSaveBody;
    Cmn::SaveDataCmn::BitFlags octoValleyIntroSeenFlag = Cmn::SaveDataCmn::cFlags_SeenOctoValleyIntro;

    cmnSaveBody.setFlags(&octoValleyIntroSeenFlag, 1);
    cmnSaveBody.flushSave();

    
    return 1;
}

bool controlOctoValleyRestartState() {
    return gSettings.addOctoValleyRestart ? 1 : Game::Utl::isAmiiboChallengeMission();
}

void controlFirstNewsIntro() {
    if (!gSettings.skipNewsIntro)
        return;
    Cmn::SaveDataCmn::Body cmnSaveBody;
    Cmn::SaveDataCmn::BitFlags finishedTutorialFlag = Cmn::SaveDataCmn::cFlags_FinishedTutorial;

    cmnSaveBody.setFlags(&finishedTutorialFlag, 1);
    cmnSaveBody.flushSave();
    return;

}

} // namespace rando

tBranch(0x0277707C, rando::controlOctoValleyIntroState, tk::BranchType::bl);
tBranch(0x020A8984, rando::controlOctoValleyRestartState, tk::BranchType::bl); 
tBranch(0x027477A4, rando::controlFirstNewsIntro, tk::BranchType::b);