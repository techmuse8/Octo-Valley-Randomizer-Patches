#include <cafe.h>

#include <filedevice/cafe/seadCafeFSAFileDeviceCafe.h>
#include <filedevice/seadFileDevice.h>
#include <filedevice/seadFileDeviceMgr.h>
#include <prim/seadSafeString.h>
#include <dynamic_libs/fs_functions.h>

#include <telkin/Print.h>

struct FSMountSource {
    char unk[0x300];
};

namespace sead {

CafeSDFileDevice::CafeSDFileDevice() : CafeFSAFileDevice("sd", "/vol/external01") {
}

// const char* FileDeviceMgr::getFSSDMountPath() const {
//     return mFSSDMountPath;
// }

RawErrorCode FileDeviceMgr::mountSDCard() {
    FSStatus result;
    FSCmdBlock cmd;
    FSMountSource source;

    if (mFSSDMountCount == 0) {

        FSInitCmdBlock(&cmd);

        result = FSGetMountSource(&mFSClient, &cmd, 0, &source, FS_RET_ALL_ERROR);
        if (result < 0) {
            tk::print("FSGetMountSource failed: %d\n", result);
            FSDelClient(&mFSClient);
            return result;
        }

        result = FSMount(&mFSClient, &cmd, &source, mFSSDMountPath, FS_MAX_MOUNTPATH_SIZE, FS_RET_ALL_ERROR);
        if (result < 0) {
            tk::print("FSMount failed: %d\n", result);
            FSDelClient(&mFSClient);
            return result;
        }

        tk::print("SD mounted at: %s\n", mFSSDMountPath);
    }

    mFSSDMountCount++;
    return FS_STATUS_OK;
}

} // namespace sead