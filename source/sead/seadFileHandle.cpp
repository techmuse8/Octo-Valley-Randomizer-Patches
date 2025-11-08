#pragma once

#include <sead/filedevice/seadFileDevice.h>
#include <sead/filedevice/seadFileDeviceMgr.h>
#include "prim/seadSafeString.h"
#include <cafe.h>

namespace sead {

bool FileHandle::tryRead(u32* read_size, u8* buf, u32 size)
{
    if (!mDevice)
    {
        return false;
    }
    return mDevice->tryRead(read_size, this, buf, size);
}

}