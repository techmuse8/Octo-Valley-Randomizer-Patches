#pragma once
#include <cafe.h>
#include <sead/filedevice/cafe/seadCafeSaveFileDevice.h>

//class sead::CafeSaveFileDevice;

namespace Lp {
    namespace Sys {

    class SaveDataMgr {
    public:
        static SaveDataMgr* sInstance;
        u8 pad0[0x1C];
        sead::CafeSaveFileDevice* saveDevice;
        u8 pad1[0x14];


};

} // namespace Lp
} // namespace Sys