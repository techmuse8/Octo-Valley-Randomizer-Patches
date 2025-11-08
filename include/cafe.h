#pragma once

#include <stdint.h>
#include "dynamic_libs/os_functions.h"
#include "dynamic_libs/fs_defs.h"
#include <dynamic_libs/mtxVec_functions.h>

#include <cafe/gx2.h>
#include <cafe/os.h>

#if PLATFORM_IS_EMULATOR
#define LOG(FMT, ARGS...) OSReport(FMT, ##ARGS);
#elif PLATFORM_IS_CONSOLE_CAFELOADER
#define LOG(FMT, ARGS...) ((void (*)(const char* format, ...))(*(unsigned int*)(DATA_ADDR - 4)))(FMT, ##ARGS);
#else
#error "Unsupported platform"
#endif
