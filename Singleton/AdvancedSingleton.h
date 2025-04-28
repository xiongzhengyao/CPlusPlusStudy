#ifndef ADVANCED_SINGLETON_H
#define ADVANCED_SINGLETON_H

#include <memory>
#include <mutex>
#include <string>

class AdvancedSingleton {
public:
    // 获取单例实例
    static std::shared_ptr<AdvancedSingleton> getInstance();
    
    // 配置单例
    void configure(const std::string& config);
    
    // 获取配置
    std::string getConfig() const;
    
    // 删除拷贝构造函数和赋值运算符
    AdvancedSingleton(const AdvancedSingleton&) = delete;
    AdvancedSingleton& operator=(const AdvancedSingleton&) = delete;

private:
    // 私有构造函数
    AdvancedSingleton();
    
    // 私有析构函数
    ~AdvancedSingleton();
    
    // 静态成员变量
    static std::shared_ptr<AdvancedSingleton> instance;
    static std::mutex mutex;
    
    // 成员变量
    std::string config;
};

#endif // ADVANCED_SINGLETON_H 