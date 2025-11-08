#pragma once

#include <sead/filedevice/seadFileDevice.h>
#include <sead/filedevice/seadFileDeviceMgr.h>
#include <sead/filedevice/cafe/seadCafeFSAFileDeviceCafe.h>
#include "prim/seadSafeString.h"
#include <cafe.h>

namespace sead {

FileDevice* FileDeviceMgr::tryOpen(FileHandle* handle, const SafeString& filename, FileDevice::FileOpenFlag flag, u32 div_num) {
    FixedSafeString<cNoDrivePathBufferSize> no_drive_path;
    FileDevice* device = findDeviceFromPath(filename, &no_drive_path);

    if (device == nullptr) {
        return nullptr;
    }

    return device->tryOpen(handle, no_drive_path, flag, div_num);
}

} // namespace sead