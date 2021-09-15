/* Copyright 2017 mozkzki */
#include "tool2/tool2.h"

#include <windows.h>

#include <iostream>

#include "common/common.h"

BOOL WINAPI DllMain(HINSTANCE hDLL, DWORD dwReason, LPVOID lpReserved) {
    return TRUE;
}

int Tool2Create(int buffer_size) {
    std::cout << "tool2.dll / Tool2Create method called." << std::endl;
    int *n = new int[buffer_size];
    delete n;

    return 0;
}
