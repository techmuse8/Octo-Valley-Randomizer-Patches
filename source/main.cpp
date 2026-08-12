#include <telkin/Telkin.h>

#include <mod/gunc.h>
#include <mod/rando.h>
#include <heap/seadHeapMgr.h>
#include <heap/seadExpHeap.h>
#include <filedevice/cafe/seadCafeFSAFileDeviceCafe.h>
#include <filedevice/seadFileDeviceMgr.h>
//#include <Lp/Sys/FileDeviceHolder.h>

#include <Lp/Sys/HeapGroup.h>

void main() {
    tk::println("Gambit Uncranked initialized!");

}

namespace gunc {

extern "C" sead::Heap* createGuncHeap(u32, u32, sead::Heap* parent) {
    constexpr u32 size = 0x8000;
    sGuncHeap = sead::ExpHeap::tryCreate(size, "GuncHeap", parent, sead::Heap::cHeapDirection_Forward, false);
    tk::println("Created GuncHeap!");
    return sead::ExpHeap::tryCreate(0x0, "sead::MethodTreeMgr", parent, sead::Heap::cHeapDirection_Forward, false);
}

void initialize2() {
    rando::initSettings();
    return;
}

}


tBranch(0x02868C10, gunc::initialize2, tk::BranchType::b);
tBranch(0x028DFF18, gunc::createGuncHeap, tk::BranchType::bl);