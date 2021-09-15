/* Copyright 2017 mozkzki */
#ifndef C__WORKSPACE_SRC_CLASS_CLASS_JAPANESE_H_
#define C__WORKSPACE_SRC_CLASS_CLASS_JAPANESE_H_

#include <string>

#include "class/person.h"

namespace test {

class Japanese : public Person {
 public:
    Japanese();
    explicit Japanese(std::string name);
    virtual ~Japanese();
    std::string GetName();
};

}  // namespace test

#endif  // C__WORKSPACE_SRC_CLASS_CLASS_JAPANESE_H_
