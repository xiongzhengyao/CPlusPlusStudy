#include "AdvancedSingleton.h"
#include <iostream>

// 初始化静态成员变量
std::shared_ptr<AdvancedSingleton> AdvancedSingleton::instance = nullptr;
std::mutex AdvancedSingleton::mutex;

std::shared_ptr<AdvancedSingleton> AdvancedSingleton::getInstance() {
    // 双重检查锁定模式
    if (instance == nullptr) {
        std::lock_guard<std::mutex> lock(mutex);
        if (instance == nullptr) {
            instance = std::shared_ptr<AdvancedSingleton>(new AdvancedSingleton());
        }
    }
    return instance;
}

AdvancedSingleton::AdvancedSingleton() {
    std::cout << "AdvancedSingleton 构造函数被调用" << std::endl;
    config = "默认配置";
}

AdvancedSingleton::~AdvancedSingleton() {
    std::cout << "AdvancedSingleton 析构函数被调用" << std::endl;
}

void AdvancedSingleton::configure(const std::string& config) {
    this->config = config;
}

std::string AdvancedSingleton::getConfig() const {
    return config;
} 