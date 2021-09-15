/* Copyright 2017 mozkzki */
#include <iostream>
#include "tool/tool.h"

// 参考:
// http://www2s.biglobe.ne.jp/~ragnarok/program/win32/class_of_cpp_in_dll.htm
// https://qiita.com/Chironian/items/462a3bdf271d5f0b00b6

#pragma comment(lib, "tool.lib")

int main() {
    sample::Tool tool;
    std::cout << "sizeof(tool):" << sizeof(tool) << std::endl;
    std::cout << "sizeof(sample::Tool):" << sizeof(sample::Tool) << std::endl;
    tool.Execute();
}
