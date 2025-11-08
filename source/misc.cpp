#include <dynamic_libs/os_functions.h>

extern "C" {

void* memset(void* pointer, int value, size_t count) {
    return OSBlockSet(pointer, value, count);
}

void* memcpy(void* dst, const void* src, size_t len) {
    return OSBlockMove(dst, src, len, 0);
}

void* malloc(size_t size) {
    return MEMAllocFromDefaultHeap(size);
}

void free(void* ptr) {
    MEMFreeToDefaultHeap(ptr);
}

}