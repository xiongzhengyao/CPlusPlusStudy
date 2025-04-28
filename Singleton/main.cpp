#include "AdvancedSingleton.h"
#include <iostream>
#include <thread>
#include <vector>

void threadFunction(int id) {
    auto singleton = AdvancedSingleton::getInstance();
    singleton->configure("线程 " + std::to_string(id) + " 的配置");
    std::cout << "线程 " << id << " 获取配置: " << singleton->getConfig() << std::endl;
}

int main() {
    // 创建多个线程来测试线程安全性
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(threadFunction, i);
    }

    // 等待所有线程完成
    for (auto& thread : threads) {
        thread.join();
    }

    // 主线程获取单例
    auto singleton = AdvancedSingleton::getInstance();
    std::cout << "主线程获取配置: " << singleton->getConfig() << std::endl;

    return 0;
} 