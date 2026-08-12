#include <ext-libs/minGlue-sead.h>
#include <sead/filedevice/seadFileDeviceMgr.h>

static u8 readBuf[256] __attribute__((aligned(0x40)));
static u32 bufPos = 0;
static u32 bufSize = 0;

extern "C" {

inline static sead::FileHandle* getHandle(INI_FILETYPE* file) {
    return static_cast<sead::FileHandle*>(file->handle);
}

inline static sead::FileDevice* getDevice(INI_FILETYPE* file) {
    return static_cast<sead::FileDevice*>(file->device);
}

int seadfile_read(INI_FILETYPE *file, char* outBuffer, int size) {
    sead::FileHandle* handle = getHandle(file);
    int pos = 0;
   // bool isReadBufFilled = false;

    while (pos < size - 1) {
       if (bufPos >= bufSize) {
            u32 toRead = sizeof(readBuf);
            if (!handle->tryRead(&toRead, readBuf, sizeof(readBuf)) || toRead == 0) {
                if (pos == 0)
                    return 0;
                break;
            }
            bufSize = toRead;
            bufPos = 0;
        }

        u8 curByte = readBuf[bufPos++];
        outBuffer[pos++] = curByte;

        if (curByte == '\n')
            break;
    }
    outBuffer[pos] = '\0';
    return 1;

}

int seadfile_open(INI_FILETYPE *file, const char* filename, seadfile_open_flags open_flags) {
    file->handle = new sead::FileHandle;
    sead::FileHandle* castedHandle = static_cast<sead::FileHandle*>(file->handle);

    file->device = sead::FileDeviceMgr::instance()->tryOpen(castedHandle, filename, (sead::FileDevice::FileOpenFlag)open_flags, 0);

    if (!file->device) {
        delete file->handle;
        return 0;
    }

    return 1;

}

int seadfile_close(INI_FILETYPE *file) {
    sead::FileDevice* device = getDevice(file);
    sead::FileHandle* handle = getHandle(file);

    if (!device->tryClose(handle)) return false;
    delete file->handle;
    return true;

}

int seadfile_tell(INI_FILETYPE *file, long* pos) {
    sead::FileDevice* device = getDevice(file);
    sead::FileHandle* handle = getHandle(file);

    *pos = device->getCurrentSeekPos(handle);
    return 1;
}

int seadfile_seek(INI_FILETYPE *file, int pos) {
    sead::FileDevice* device = getDevice(file);
    sead::FileHandle* handle = getHandle(file);

    return device->trySeek(handle, pos, sead::FileDevice::cSeekOrigin_Begin) ? 1 : 0;
}
}