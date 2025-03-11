// #include <iostream>
// #include <vector>
// #include <thread>

// void SumThread(int start, int end, int& result) {
//     for (int i = start; i <= end; ++i) {
//         result += i;
//     }
// }

// int main() {
//     int total = 0;
//     int half = 100000000;

//     std::thread t1(SumThread, 1, half, std::ref(total));
//     std::thread t2(SumThread, half + 1, 2 * half, std::ref(total));

//     t1.join();
//     t2.join();
//     std::cout << "总和: " << total << std::endl; // 输出 20000000100000000
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <thread>
// #include <mutex>

// std::mutex mtx; // 定义一个互斥锁

// void SumThread(int start, int end, int& result) {
//     for (int i = start; i <= end; ++i) {
//         std::lock_guard<std::mutex> lock(mtx); // 自动管理锁的获取和释放
//         result += i;
//     }
// }

// int main() {
//     int total = 0;
//     int half = 100000000;

//     std::thread t1(SumThread, 1, half, std::ref(total));
//     std::thread t2(SumThread, half + 1, 2 * half, std::ref(total));

//     t1.join();
//     t2.join();

//     std::cout << "总和: " << total << std::endl; // 输出 20000000100000000
//     return 0;
// }

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex mtx; // 定义一个互斥锁

void SumThread(int start, int end, long long& result) {
    for (int i = start; i <= end; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // 自动管理锁的获取和释放
        result += i;
    }
}

int main() {
    long long total = 0; // 使用long long类型
    int half = 100000000;

    std::thread t1(SumThread, 1, half, std::ref(total));
    std::thread t2(SumThread, half + 1, 2 * half, std::ref(total));

    t1.join();
    t2.join();

    std::cout << "总和: " << total << std::endl; // 输出 20000000100000000
    return 0;
}