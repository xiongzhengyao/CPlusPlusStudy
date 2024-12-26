
#include <iostream>
#include <thread>
#include <chrono>

// 工作线程函数 - 模拟一些耗时操作
void worker(int id) {
    // 打印线程开始的消息
    std::cout << "线程 " << id << " 开始执行..." << std::endl;
    
    // 模拟工作负载，让线程休眠2秒
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    // 打印线程结束的消息
    std::cout << "线程 " << id << " 执行完成." << std::endl;
}

int main() {
    // 定义要创建的线程数量
    const int NUM_THREADS = 3;
    
    // 创建线程数组
    std::thread threads[NUM_THREADS];

    std::cout << "主线程开始创建子线程..." << std::endl;

    // 创建多个线程
    // std::thread 构造函数接收一个函数指针和参数
    for (int i = 0; i < NUM_THREADS; i++) {
        threads[i] = std::thread(worker, i);  // 每个线程执行worker函数，传入不同的id
    }

    std::cout << "等待所有子线程完成..." << std::endl;

    // 等待所有线程完成
    // join()会阻塞主线程，直到对应的子线程执行完成
    for (int i = 0; i < NUM_THREADS; i++) {
        threads[i].join();
    }

    // 所有线程执行完成后，主线程继续执行
    std::cout << "所有子线程已完成执行！" << std::endl;
    
    return 0;
}

/*
代码说明：
1. 使用 std::thread 创建线程，它是C++11引入的线程类
2. worker函数是线程要执行的任务函数
3. sleep_for用于模拟耗时操作
4. join()用于等待线程完成
5. 程序会创建3个线程并行执行
6. 每个线程都有唯一的ID，可以看到它们的执行是并行的
7. 主线程会等待所有子线程完成后才结束程序

运行结果可能如下：
主线程开始创建子线程...
等待所有子线程完成...
线程 0 开始执行...
线程 2 开始执行...
线程 1 开始执行...
线程 1 执行完成.
线程 0 执行完成.
线程 2 执行完成.
所有子线程已完成执行！
*/

