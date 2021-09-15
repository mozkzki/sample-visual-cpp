/* Copyright 2017 mozkzki */
#include <iostream>
#include "class/person.h"
#include "class/japanese.h"

int main() {
    test::Person p1;
    std::cout << "------------" << std::endl;

    test::Person p2("foo");
    std::cout << "------------" << std::endl;

    test::Person* p3 = new test::Person("bar");
    delete p3;
    std::cout << "------------" << std::endl;

    test::Japanese j1;
    std::cout << "------------" << std::endl;

    test::Person* j2 = new test::Japanese("hoge");
    j2->GetName();
    delete j2;
    std::cout << "------------" << std::endl;

    return 0;
}
