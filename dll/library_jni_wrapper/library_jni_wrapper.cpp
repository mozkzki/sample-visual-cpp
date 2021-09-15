/* Copyright 2017 mozkzki */
#include "library_java/LibraryJava.h"
#include "library/library.h"

JNIEXPORT jint JNICALL Java_LibraryJava_execute
  (JNIEnv *, jobject) {
    Execute();
    return 0;
}
