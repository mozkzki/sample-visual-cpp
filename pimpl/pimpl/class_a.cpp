/* Copyright 2017 mozkzki */
#include "pimpl/class_a.h"
#include "pimpl/inner_class.h"

class ClassA::ClassAImpl {
 public:
    ClassAImpl() : age_(0), number_(0) {
        this->inner_class_ = new InnerClass();
    }

    ~ClassAImpl() {
        delete this->inner_class_;
    }

    int GetVolume() {
        return this->age_ * this->number_;
    }

    InnerClass* inner_class_;

 private:
    int age_;
    int number_;
};

ClassA::ClassA() {
    this->class_a_impl_ = new ClassAImpl();
}

ClassA::~ClassA() {
    delete this->class_a_impl_;
}

int ClassA::GetNumber() {
    return this->class_a_impl_->inner_class_->GetNumber();
}

int ClassA::Execute(int index) {
    return this->class_a_impl_->GetVolume() * index;
}
