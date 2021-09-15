/* Copyright 2017 mozkzki */
#include "tool/tool.h"

#include <windows.h>

#include <iostream>

#include "common/common.h"

BOOL WINAPI DllMain(HINSTANCE hDLL, DWORD dwReason, LPVOID lpReserved) {
    return TRUE;
}

int __declspec(dllexport) __stdcall ToolCreate(int buffer_size) {
    std::cout << "tool.dll / ToolCreate method called." << std::endl;
    int *n = new int[buffer_size];
    delete n;

    return 0;
}
