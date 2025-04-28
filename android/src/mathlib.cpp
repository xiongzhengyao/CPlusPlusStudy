#include "mathlib.h"
#include <android/log.h>

#define LOG_TAG "MathLib"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

int add(int a, int b) {
    LOGI("Adding %d and %d", a, b);
    return a + b;
}

int subtract(int a, int b) {
    LOGI("Subtracting %d from %d", b, a);
    return a - b;
} 