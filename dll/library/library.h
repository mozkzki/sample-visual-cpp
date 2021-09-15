/* Copyright 2017 mozkzki */
#pragma once

#ifdef DLL_EXPORTS
#ifdef __cplusplus
extern "C" {
#endif
int __declspec(dllexport) __stdcall  Execute();
#ifdef __cplusplus
}
#endif
#else
#ifdef __cplusplus
extern "C" {
#endif
int __declspec(dllimport) __stdcall  Execute();
#ifdef __cplusplus
}
#endif
#endif
