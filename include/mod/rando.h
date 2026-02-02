#include "../cafe.h"

namespace rando {

    struct Settings {
        bool skipOctoValleyIntro;
        bool skipNewsIntro;
        bool isWeaponRandoOn;
        bool addOctoValleyRestart;
    };

    extern Settings gSettings;

    void initSettings();
}