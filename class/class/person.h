/* Copyright 2017 mozkzki */
#ifndef C__WORKSPACE_SRC_CLASS_CLASS_PERSON_H_
#define C__WORKSPACE_SRC_CLASS_CLASS_PERSON_H_

#include <string>

namespace test {

class Person {
 public:
    Person();
    explicit Person(std::string name);
    virtual ~Person();
    virtual std::string GetName();

 private:
    std::string name_;
};

}  // namespace test

#endif  // C__WORKSPACE_SRC_CLASS_CLASS_PERSON_H_
