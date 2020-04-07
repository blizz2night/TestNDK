#include <jni.h>
#include <string>
#include <stdlib.h>
#include <android/log.h>

using namespace std;
#define LOG_TAG "demo_tag"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
extern "C" JNIEXPORT jstring JNICALL
Java_com_github_blizz2inght_testmake_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jint JNICALL
Java_com_github_blizz2inght_testmake_MainActivity_addAll(JNIEnv *env, jobject thiz, jintArray arr) {
    // TODO: implement addAll()
    jsize length = env->GetArrayLength(arr);
    jboolean isCopy = JNI_TRUE;
    jint *pInt = env->GetIntArrayElements(arr, &isCopy);
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += pInt[i];
    }
    string sumStr = to_string(sum);
    LOGD("sum=%d",sum);
    return sum;
}