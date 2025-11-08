#include <cafe.h>

#include <filedevice/cafe/seadCafeFSAFileDeviceCafe.h>
#include <filedevice/seadFileDevice.h>
#include <filedevice/seadFileDeviceMgr.h>
#include <prim/seadSafeString.h>
#include <dynamic_libs/fs_functions.h>

namespace sead {

RawErrorCode CafeFSAFileDevice::doGetLastRawError_() const {
    return mLastRawError;
}

void CafeFSAFileDevice::doResolvePath_(BufferedSafeString* out, const SafeString& path) const {
    formatPathForFSA_(out, path);
}

void CafeFSAFileDevice::setFSClient(FSClient* client) {
    mFSClient = client;
}

void FileDevice::doTracePath_(const SafeString& path) const {
    FixedSafeString<512> out;
    doResolvePath_(&out, path);
}
} // namespace sead