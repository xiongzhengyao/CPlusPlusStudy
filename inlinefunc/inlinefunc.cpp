#include <iostream>

// 内联函数示例 - 计算两个数的最大值
inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int x = 10;
    int y = 20;
    
    // 调用内联函数
    std::cout << "Max value is: " << max(x, y) << std::endl;
    
    return 0;
}
