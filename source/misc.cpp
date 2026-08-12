#include <cctype>
#include <dynamic_libs/os_functions.h>
#define TK_IMPL_MEMCMP
#define TK_IMPL_STRCHR
#define TK_IMPL_STRNCPY
#define TK_IMPL_STRTOL
#define TK_IMPL_TOUPPER
#define TK_IMPL_ISALPHA
#define TK_IMPL_ISDIGIT
#define TK_IMPL_ISLOWER
#define TK_IMPL_ISSPACE
#define TK_IMPL_ISUPPER
#include <telkin/Runtime.h>

extern "C" {

void* aligned_alloc(size_t alignment, size_t size) {
    return MEMAllocFromDefaultHeapEx(size, alignment);
}

void* memset(void* pointer, int value, size_t count) {
    return OSBlockSet(pointer, value, count);
}

void* memcpy(void* dst, const void* src, size_t len) {
    return OSBlockMove(dst, src, len, 0);
}

void* malloc(size_t size) {
    return MEMAllocFromDefaultHeap(size);
}

// From https://github.com/gcc-mirror/gcc/blob/6bf6dad534766300376dec6d093d49b89a452ea1/libiberty/strrchr.c#L18
char* strrchr (const char *s, int c) {
  char *rtnval = 0;

    do {
        if (*s == c)
        rtnval = (char*) s;
    } while (*s++);
    return (rtnval);
}

void free(void* ptr) {
    MEMFreeToDefaultHeap(ptr);
}

}