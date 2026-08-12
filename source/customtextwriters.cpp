#include <cstdlib>
#include <mod/gunc.h>
#include <sead/gfx/seadTextWriter.h>
#include <sead/filedevice/seadFileDevice.h>
#include <sead/filedevice/seadFileDeviceMgr.h>
#include <Gambit/Cmn/Def/Mode.h>

#define TELKIN_REGISTERS
#include <telkin/Assembly.h>
#include <telkin/Hooks.h>
#include <telkin/Print.h>

static char seedBuffer[64];

bool getRandoSeed() {
    sead::FileHandle fileHandle;
    tk::print("Loading seed file\n");

    sead::FileDevice* seedFile;

    seedFile = sead::FileDeviceMgr::instance()->tryOpen(&fileHandle, "main://Rando/seed.txt", sead::FileDevice::cFileOpenFlag_ReadOnly,
                                                        0); // main = content folder root

    u8* work = (u8*)aligned_alloc(sead::FileDevice::cBufferMinAlignment, fileHandle.getFileSize() + 1);
    if (!work)
        return 0;

    if (seedFile) {
        u32 bytesRead = 0;
        u32 fileSize = fileHandle.getFileSize();
        tk::print("Filesize: %d bytes\n", fileSize);
        if (fileHandle.tryRead(&bytesRead, work, fileHandle.getFileSize())) {
            tk::print("Read %d bytes\n", bytesRead);
            tk::print("Seed: %s\n", reinterpret_cast<const char*>(work));
            strncpy(seedBuffer, reinterpret_cast<const char*>(work), sizeof(seedBuffer) - 1);
            seedBuffer[sizeof(seedBuffer) - 1] = '\0';

        } else {
            tk::print("Read failed.\n");
            free(work);
            return 0;
        }
    }
    else 
        return 0;

    free(work);
    return 1;
}

void drawCustomDebugText(void* gameSceneMemDisp, agl::lyr::RenderInfo* renderInfo) {
    Cmn::Def::Mode curMode = Cmn::Def::getCurMode();
    static bool triedToLoad = false;
    static bool loadedSeed = false;

    sead::TextWriter writer(renderInfo);

    if (!triedToLoad) {
        bool ok = getRandoSeed();
        triedToLoad = true;
        loadedSeed = ok;
    }

    writer.mPos.set(-600.0f, 320.0f);
    writer.mScale.set(2.0f, 2.0f);

    if (!loadedSeed && curMode == Cmn::Def::cMode_Plaza) {
        writer.mColor = sead::Color4f::cRed;
        writer.printf("Failed to load the seed!\n");
    } 
    else if (curMode == Cmn::Def::cMode_Plaza || curMode == Cmn::Def::cMode_Boot) {
        writer.printf("Current seed: %s\n", seedBuffer);
    }
}

void customTextWriterASMSetup() tAssembly(
    // Save LR/volatiles
    mflr    r0;
    stwu    r1, -0x20(r1);
    stw     r0, 0x24(r1);

    bl _Z19drawCustomDebugTextPvPN3agl3lyr10RenderInfoE; // TODO: Add mangled version

    // Restore LR/stack
    lwz     r0, 0x24(r1);
    addi    r1, r1, 0x20;
    mtlr    r0;

    // Original instruction
    lmw     r18, 0x90(r1);
    b loc_0289DF8C; // really hacky
)

#include <telkin/UndefineRegisters.h>
tBranch(0x0289DF88, customTextWriterASMSetup, tk::BranchType::bl); 
tPatchNop(0x028B065C);

