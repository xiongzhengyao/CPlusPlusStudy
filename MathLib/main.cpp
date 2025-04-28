#include "math_lib.h"
#include <iostream>

int main() {
    // 使用静态库
    std::cout << "使用静态库：" << std::endl;
    std::cout << "5 + 3 = " << MathLib::add(5, 3) << std::endl;
    std::cout << "5 - 3 = " << MathLib::subtract(5, 3) << std::endl;
    std::cout << "5 * 3 = " << MathLib::multiply(5, 3) << std::endl;
    
    try {
        std::cout << "5 / 3 = " << MathLib::divide(5, 3) << std::endl;
        std::cout << "5 / 0 = " << MathLib::divide(5, 0) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "错误: " << e.what() << std::endl;
    }

    return 0;
} 