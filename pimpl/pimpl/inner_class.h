/* Copyright 2017 mozkzki */
#pragma once

class InnerClass {
 public:
    InnerClass() : number_(5) {}
    ~InnerClass() {}
    int GetNumber() { return this->number_; }

 private:
    int number_;
};
