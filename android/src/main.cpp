#include <stdio.h>
#include "mathlib.h"
#include <android/log.h>

#define LOG_TAG "MathTest"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

int main() {
    int a = 10;
    int b = 5;
    
    int sum = add(a, b);
    int diff = subtract(a, b);
    
    LOGI("Sum: %d + %d = %d", a, b, sum);
    LOGI("Difference: %d - %d = %d", a, b, diff);
    
    return 0;
} 