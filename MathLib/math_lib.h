#ifndef MATH_LIB_H
#define MATH_LIB_H

#ifdef _WIN32
    #ifdef MATH_LIB_EXPORTS
        #define MATH_LIB_API __declspec(dllexport)
    #else
        #define MATH_LIB_API __declspec(dllimport)
    #endif
#else
    #define MATH_LIB_API
#endif

class MATH_LIB_API MathLib {
public:
    // 加法
    static int add(int a, int b);
    
    // 减法
    static int subtract(int a, int b);
    
    // 乘法
    static int multiply(int a, int b);
    
    // 除法
    static double divide(int a, int b);
};

#endif // MATH_LIB_H 