#include <jni.h>
#include <string>
#include "scratch.cpp"

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_phonogrammetry_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_phonogrammetry_MainActivity_test_1import(
        JNIEnv* env,
        jobject) {
    return env->NewStringUTF(test_import_in_scratch().c_str());
}


