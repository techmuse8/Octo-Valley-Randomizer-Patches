#include <new>
#include <basis/seadNew.h>

void* operator new(size_t size, std::align_val_t alignment) {
    return ::operator new(size, nullptr, static_cast<s32>(alignment));
}

void* operator new[](size_t size, std::align_val_t alignment) {
    return ::operator new[](size, nullptr, static_cast<s32>(alignment));
}