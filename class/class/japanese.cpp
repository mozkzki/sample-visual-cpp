/* Copyright 2017 mozkzki */

#include "class/japanese.h"

#include <string>
#include <iostream>

#include "class/person.h"

namespace test {

Japanese::Japanese() : Person("mozkzki") {
    std::cout << "私は日本人の" << Person::GetName() << "です。構築されます。"
        << std::endl;
}

Japanese::Japanese(std::string name) : Person(name) {
    std::cout << "私は日本人の" << Person::GetName() << "です。構築されます。"
        << std::endl;
}

Japanese::~Japanese() {
    std::cout << "私は日本人の" << Person::GetName() << "です。破棄されます。"
        << std::endl;
}

std::string Japanese::GetName() {
    std::string name = Person::GetName();
    std::cout << "私は日本人の" << name << "です。" << std::endl;
    return name;
}

}  // namespace test
