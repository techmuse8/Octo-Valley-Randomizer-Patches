#include <cafe.h>
#include <mod/gunc.h>
#include <sead/gfx/seadTextWriter.h>
#include <sead/filedevice/seadFileDevice.h>
#include <sead/filedevice/seadFileDeviceMgr.h>
#include <Lp/Sys/FileDeviceHolder.h>
#include <Gambit/Cmn/Def/Mode.h>

static char seedBuffer[64];

bool getRandoSeed() {
    sead::FileHandle fileHandle;
    LOG("Loading seed file\n");

    sead::FileDevice* seedFile;

    seedFile = sead::FileDeviceMgr::instance()->tryOpen(&fileHandle, "main://Rando/seed.txt", sead::FileDevice::cFileOpenFlag_ReadOnly,
                                                        0); // main = content folder root

    uint8_t* work = (uint8_t*)MEMAllocFromDefaultHeapEx(fileHandle.getFileSize(), -sead::FileDevice::cBufferMinAlignment);
    if (!work)
        return 0;

    if (seedFile) {
        u32 bytesRead = 0;
        u32 fileSize = fileHandle.getFileSize();
        LOG("Filesize: %d bytes\n", fileSize);
        if (fileHandle.tryRead(&bytesRead, work, fileHandle.getFileSize())) {
            LOG("Read %d bytes\n", bytesRead);
            LOG("Seed: %s\n", reinterpret_cast<const char*>(work));
            strncpy(seedBuffer, reinterpret_cast<const char*>(work), sizeof(seedBuffer) - 1);
            seedBuffer[sizeof(seedBuffer) - 1] = '\0';

        } else {
            LOG("Read failed.\n");
            MEMFreeToDefaultHeap(work);
            return 0;
        }
    }
    else 
        return 0;

    MEMFreeToDefaultHeap(work);
    return 1;
}

void drawCustomDebugText(int* gameSceneMemDisp, sead::Viewport* viewport) {

    Cmn::Def::Mode curMode = Cmn::Def::getCurMode();
    static bool triedToLoad = false;
    static bool loadedSeed = false;

    sead::TextWriter writer(viewport);

    if (!triedToLoad) {
        bool ok = getRandoSeed();
        triedToLoad = true;
        loadedSeed = ok;
    }

    writer.mPos.set(-600.0f, 320.0f);
    writer.mScale.set(2.0f, 2.0f);

    if (!loadedSeed && curMode == Cmn::Def::cPlaza) {
        writer.mColor = sead::Color4f::cRed;
        writer.printf("Failed to load the seed!\n");
    } 
    else if (curMode == Cmn::Def::cPlaza) {
        writer.printf("Current seed: %s\n", seedBuffer);
    }
}
