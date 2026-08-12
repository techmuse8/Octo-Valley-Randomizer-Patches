#pragma once
#include <cafe.h>
#include <sead/filedevice/cafe/seadCafeFSAFileDeviceCafe.h>
//#include <sead/filedevice/cafe/seadCafeSaveFileDevice.h>

// class sead::CafeSaveFileDevice;

namespace Sys {

class FileDeviceHolder {
  public:
    static FileDeviceHolder* sInstance;

    u8 pad0[0x14];
    sead::CafeContentFileDevice* contentDevice;
    u8 pad1[4];
    void* saveDevice; // todo: add sead::CafeSaveFileDevice*
    u8 pad2[0x14];
};

    static_assert(sizeof(FileDeviceHolder) == 0x34, "Lp::Sys::FileDeviceHolder size mismatch");
} // namespace Sys