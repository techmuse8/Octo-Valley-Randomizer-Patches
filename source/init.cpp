#include <cafe.h>
#include <dynamic_libs/os_functions.h>
#include <dynamic_libs/fs_functions.h>
#include <mod/gunc.h>
#include <sead/heap/seadHeapMgr.h>
#include <sead/heap/seadExpHeap.h>
#include "save/system/savemgrsystem.h"
#include <sead/filedevice/cafe/seadCafeSaveFileDevice.h>
#include <sead/filedevice/cafe/seadCafeFSAFileDeviceCafe.h>
#include <sead/filedevice/seadFileDeviceMgr.h>
#include <Lp/Sys/FileDeviceHolder.h>

typedef void (*InitFunc)();
extern "C" InitFunc _ctors[];

extern "C" {

OsSpecifics osSpecifics;
uint32_t Splatoon_OSDynLoad_Acquire;
uint32_t Splatoon_OSDynLoad_FindExport;
}

// https://github.com/aboood40091/NSMBU-Haxx-Rewrite/blob/master/haxx/src/ctors.cpp#L22C1-L37C2
uintptr_t AddrExtractFromInst(const u32* p_instruction) {
    uintptr_t ret = *p_instruction & 0x03FFFFFCu;

    if (!(*p_instruction & 2)) {
        // sign extend offset
        if (ret & 0x02000000u)
            ret |= 0xFE000000u;

        // make relative
        ret += (uintptr_t)p_instruction;
    }

    return ret;
}

extern "C" void call_ctors() {

    static bool initialized = false;
    if (initialized)
        return;

    initialized = true;
    for (s32 i = 0; _ctors[i]; i++)
       (*_ctors[i])();

    OS_SPECIFICS->addr_OSDynLoad_Acquire = AddrExtractFromInst(&Splatoon_OSDynLoad_Acquire);
    OS_SPECIFICS->addr_OSDynLoad_FindExport = AddrExtractFromInst(&Splatoon_OSDynLoad_FindExport);

    InitOSFunctionPointers();
    InitFSFunctionPointers();

    LOG("\n");
    LOG("\n");
    LOG("\n");
    LOG("Gambit Uncranked initialized!\n");
    LOG("\n");
    LOG("\n");
    LOG("\n");
    
}

static sead::CafeSDFileDevice gCafeSDFileDevice;

sead::Heap* gunc::sGuncHeap = nullptr;

extern "C" sead::Heap* createGuncHeap(u32, u32, sead::Heap* parent) {
    const u32 size = 0x20000;
    gunc::sGuncHeap = sead::ExpHeap::tryCreate(size, "GuncHeap", parent, sead::Heap::cHeapDirection_Forward, false);
    LOG("Created GuncHeap!\n")
    return sead::ExpHeap::tryCreate(0x0, "sead::MethodTreeMgr", parent, sead::Heap::cHeapDirection_Forward, false);
}

void initialize2() {

}
    