#include "math_lib.h"
#include <stdexcept>

int MathLib::add(int a, int b) {
    return a + b;
}

int MathLib::subtract(int a, int b) {
    return a - b;
}

int MathLib::multiply(int a, int b) {
    return a * b;
}

double MathLib::divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("除数不能为零");
    }
    return static_cast<double>(a) / b;
} 