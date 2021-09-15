/* Copyright 2017 mozkzki */
#pragma once

/*
class InnerClass;

class ClassA {
 public:
  ClassA();
  ~ClassA();
  int GetNumber();
  int Execute(int index);

 private:
  int GetVolume();

  int age_;
  int number_;
  InnerClass* inner_class_;
};
*/

class ClassA {
 public:
  ClassA();
  ~ClassA();
  int GetNumber();
  int Execute(int index);

 private:
  class ClassAImpl;
  ClassAImpl* class_a_impl_;
};
