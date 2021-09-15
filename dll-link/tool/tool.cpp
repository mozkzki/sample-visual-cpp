/* Copyright 2017 mozkzki */
#include "tool/tool.h"
#include <windows.h>
#include <iostream>

BOOL WINAPI DllMain(HINSTANCE hDLL, DWORD dwReason, LPVOID lpReserved) {
    return TRUE;
}

namespace sample {

Tool::Tool() : number_(0) {
}

Tool::~Tool() {
}

void Tool::Run() {
    std::cout << "Run method called." << std::endl;
}

void Tool::Execute() {
    std::cout << "Execute method called." << std::endl;
}

}  // namespace sample
