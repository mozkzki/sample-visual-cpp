/* Copyright 2017 mozkzki */
#include "class/person.h"

#include <string>
#include <iostream>

namespace test {

Person::Person() {
    std::cout << "Person constructoerd." << std::endl;
}

Person::Person(std::string name) {
    this->name_ = name;
    std::cout << "Person constructoerd. name=" << this->name_ << std::endl;
}

Person::~Person() {
    std::cout << "Person destructor! name=" << this->name_ << std::endl;
}

std::string Person::GetName() {
    std::cout << "Person GetName called. name=" << this->name_ << std::endl;
    return this->name_;
}

}  // namespace test
