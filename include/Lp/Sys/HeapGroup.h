#pragma once
#include <heap/seadDisposer.h>

namespace sead {
    class Heap;
} // namespace sead

namespace Sys {

class HeapGroup {
    SEAD_SINGLETON_DISPOSER(HeapGroup);

    public:
    int _0;
    int *vtable;
    //char unk_8[16];
    sead::Heap *mHeaps[12];

    void createHeap(sead::Heap* parent);
};

} // namespace Sys