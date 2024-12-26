// #include <iostream>
// #include <thread>
// #include <mutex>
// #include <condition_variable>

// std::mutex mtx;
// std::condition_variable cv;
// int turn = 1;

// void print1() {
//     std::unique_lock<std::mutex> lock(mtx);
//     cv.wait(lock, [] { return turn == 1; });
//     std::cout << "1";
//     turn = 2;
//     cv.notify_all();
// }

// void print2() {
//     std::unique_lock<std::mutex> lock(mtx);
//     cv.wait(lock, [] { return turn == 2; });
//     std::cout << "2";
//     turn = 3;
//     cv.notify_all();
// }

// void print3() {
//     std::unique_lock<std::mutex> lock(mtx);
//     cv.wait(lock, [] { return turn == 3; });
//     std::cout << "3";
//     turn = 1;
//     cv.notify_all();
// }

// int main() {
//     std::thread t1(print1);
//     std::thread t2(print2);
//     std::thread t3(print3);

//     t1.join();
//     t2.join();
//     t3.join();

//     return 0;
// }

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

// 定义全局变量
std::mutex mtx;                    // 互斥锁，用于保护共享资源和同步线程
std::condition_variable cv;        // 条件变量，用于线程间通信和等待/通知机制
int turn = 1;                     // 控制打印顺序的变量，初始为1表示从1开始打印

// 通用的打印数字函数，接收三个参数:
// num: 要打印的数字
// currentTurn: 当前应该轮到哪个数字打印
// nextTurn: 打印完后下一个应该打印的数字
void printNumber(int num, int currentTurn, int nextTurn) {
    std::unique_lock<std::mutex> lock(mtx);    // 创建unique_lock并锁住互斥量
    
    // 等待直到轮到当前数字打印
    // lambda函数作为条件，只有当turn等于currentTurn时才继续执行
    cv.wait(lock, [currentTurn] { return turn == currentTurn; });
    
    std::cout << num;             // 打印数字
    turn = nextTurn;              // 更新turn值，表示下一个应该打印的数字
    cv.notify_all();              // 通知所有等待的线程，让它们检查条件是否满足
}

int main() {
    // 创建三个线程，每个线程打印不同的数字
    // 参数依次为：要打印的数字，等待的turn值，打印后设置的turn值
    std::thread t1(printNumber, 1, 1, 2);  // 打印1，等待turn=1，完成后设置turn=2
    std::thread t2(printNumber, 2, 2, 3);  // 打印2，等待turn=2，完成后设置turn=3
    std::thread t3(printNumber, 3, 3, 1);  // 打印3，等待turn=3，完成后设置turn=1

    // 等待所有线程完成执行
    t1.join();
    t2.join();
    t3.join();

    return 0;
}

// #include <iostream>
// #include <thread>
// #include <mutex>
// #include <condition_variable>

// // 定义全局变量
// std::mutex mtx;                    // 互斥锁，用于线程同步
// std::condition_variable cv;        // 条件变量，用于线程通信
// int turn = 1;                     // 控制打印顺序的变量

// // 打印数字1的函数
// void print1() {
//     std::unique_lock<std::mutex> lock(mtx);    // 获取互斥锁
//     cv.wait(lock, [] { return turn == 1; });   // 等待轮到打印1
//     std::cout << "1";                          // 打印1
//     turn = 2;                                  // 更新turn值，下一个打印2
//     cv.notify_all();                           // 通知其他线程
// }

// // 打印数字2的函数
// void print2() {
//     std::unique_lock<std::mutex> lock(mtx);    // 获取互斥锁
//     cv.wait(lock, [] { return turn == 2; });   // 等待轮到打印2
//     std::cout << "2";                          // 打印2
//     turn = 3;                                  // 更新turn值，下一个打印3
//     cv.notify_all();                           // 通知其他线程
// }

// // 打印数字3的函数
// void print3() {
//     std::unique_lock<std::mutex> lock(mtx);    // 获取互斥锁
//     cv.wait(lock, [] { return turn == 3; });   // 等待轮到打印3
//     std::cout << "3";                          // 打印3
//     turn = 1;                                  // 更新turn值，下一轮从1开始
//     cv.notify_all();                           // 通知其他线程
// }

// int main() {
//     // 创建三个线程分别执行打印函数
//     std::thread t1(print1);
//     std::thread t2(print2);
//     std::thread t3(print3);

//     // 等待所有线程完成
//     t1.join();
//     t2.join();
//     t3.join();

//     return 0;
// }

