#include <iostream>
#include <memory>

// 定义回调操作结构体
typedef struct {
    void (*on_connect)();
    void (*on_disconnect)();
    void (*on_error)(const char* error);
    void (*on_data_received)(const char* data);
} chi_hal_callback_ops_t;

// 定义回调函数
void OnConnect() {
    std::cout << "Connected successfully!" << std::endl;
}

void OnDisconnect() {
    std::cout << "Disconnected." << std::endl;
}

void OnError(const char* error) {
    std::cout << "Error occurred: " << error << std::endl;
}

void OnDataReceived(const char* data) {
    std::cout << "Data received: " << data << std::endl;
}

// 定义HAL模块类
class HAL3Module {
private:
    static std::shared_ptr<HAL3Module> instance_;
    chi_hal_callback_ops_t callback_ops_;

public:
    static std::shared_ptr<HAL3Module> GetInstance() {
        if (!instance_) {
            instance_ = std::shared_ptr<HAL3Module>(new HAL3Module());
        }
        return instance_;
    }

    chi_hal_callback_ops_t* GetCHIAppCallbacks() {
        return &callback_ops_;
    }

    HAL3Module() {
        // 初始化回调函数
        callback_ops_.on_connect = OnConnect;
        callback_ops_.on_disconnect = OnDisconnect;
        callback_ops_.on_error = OnError;
        callback_ops_.on_data_received = OnDataReceived;
    }

    ~HAL3Module() {}
};

// 初始化静态成员变量
std::shared_ptr<HAL3Module> HAL3Module::instance_ = nullptr;

// 使用GetCHIAppCallbacks函数
static inline chi_hal_callback_ops_t* GetCHIAppCallbacks() {
    return HAL3Module::GetInstance()->GetCHIAppCallbacks();
}

int main() {
    // 获取回调操作
    chi_hal_callback_ops_t* callbacks = GetCHIAppCallbacks();

    // 调用回调函数进行测试
    std::cout << "Testing callbacks:" << std::endl;
    callbacks->on_connect();
    callbacks->on_disconnect();
    callbacks->on_error("Connection timeout");
    callbacks->on_data_received("Hello, World!");

    return 0;
}