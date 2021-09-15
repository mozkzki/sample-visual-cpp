/* Copyright 2017 mozkzki */
#include <iostream>
#include "class_a.h"

// 参考:https://ota42y.com/blog/2014/09/22/cpp-include/

int main() {
    ClassA* foo = new ClassA();
    foo->Execute(7);
    int result = foo->GetNumber();
    std::cout << "result=" << result << std::endl;
    delete foo;
}
