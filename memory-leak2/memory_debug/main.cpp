/* Copyright 2017 mozkzki */
#include <crtdbg.h>
#include <tchar.h>

#include "memory_debug/common.h"

int _tmain(int argc, _TCHAR* argv[]) {
    // メモリリーク検出
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    int* leak_ptr = new int[2];

    // leak!!!!!!!!!

    return 0;
}
