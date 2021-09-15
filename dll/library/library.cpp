/* Copyright 2017 mozkzki */
#include "library/library.h"

#include <windows.h>
#include <tchar.h>

#include <iostream>

#include "tool/tool.h"
#include "tool2/tool2.h"

typedef int (__stdcall *MYFUNCTION)(int buffer_size);
MYFUNCTION tool_create_method, tool2_create_method;

BOOL WINAPI DllMain(HINSTANCE hDLL, DWORD dwReason, LPVOID lpReserved) {
    // メモリリーク検出
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    return TRUE;
}

HINSTANCE GetFunction(
    LPCWSTR module_name,
    LPCSTR function_name,
    MYFUNCTION& function) {
    HINSTANCE hDLL;
    hDLL = LoadLibrary(module_name);
    if (hDLL == nullptr) {
        std::wcerr << L"load failed. dll=" << module_name
            << L".dll" << std::endl;
        return (HINSTANCE)-1;
    }

    function = (MYFUNCTION)GetProcAddress(hDLL, function_name);
    if (!function) {
        std::wcerr << L"GetProcAddress failed." << std::endl;
        FreeLibrary(hDLL);
        return (HINSTANCE)-1;
    }

    return hDLL;
}

int __declspec(dllexport) __stdcall Execute() {
    ToolCreate(5);

    Tool2Create(5);

    HINSTANCE hDLL;
    hDLL = GetFunction(L"tool", "ToolCreate", tool_create_method);
    std::wcout << L"ToolCreate result=" << tool_create_method(5) << std::endl;
    FreeLibrary(hDLL);

    HINSTANCE hDLL2;
    hDLL2 = GetFunction(L"tool2", "Tool2Create", tool2_create_method);
    std::wcout << L"Tool2Create result=" << tool2_create_method(5) << std::endl;
    FreeLibrary(hDLL2);

    return 0;
}
