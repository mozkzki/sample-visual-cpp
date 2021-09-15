/* Copyright 2017 mozkzki */
#pragma once

#ifdef DLL_EXPORTS
#define DLL_EXPORT  __declspec(dllexport)
#else
#define DLL_EXPORT  __declspec(dllimport)
#endif

namespace sample {

class DLL_EXPORT Tool {
 public:
     Tool();
     virtual ~Tool();
     void Run();  // add at ver2.0
     void Execute();
 private:
     int number_;
     long age0_;  // add at ver2.0
     long age1_;  // add at ver2.0
     long age2_;  // add at ver2.0
     long age3_;  // add at ver2.0
     long age4_;  // add at ver2.0
     long age5_;  // add at ver2.0
     long age6_;  // add at ver2.0

};

}  // namespace sample
