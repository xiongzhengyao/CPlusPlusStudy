# C++ 多线程编程指南

## 1. 多线程基础概念

### 1.1 什么是线程
线程是程序执行的最小单位，一个进程可以包含多个线程。每个线程都有自己的程序计数器、寄存器和栈空间，但共享进程的代码段、数据段和其他资源。

### 1.2 为什么使用多线程
- 提高程序的并发性能
- 充分利用多核处理器
- 提高程序的响应性
- 资源共享

## 2. C++11 线程库

### 2.1 基本线程操作

#### 2.1.1 创建和管理线程

C++11引入了`std::thread`类来创建和管理线程。以下是基本用法：

1. **创建线程**
   ```cpp
   #include <thread>
   
   // 使用函数指针
   void threadFunction() {
       // 线程要执行的代码
   }
   std::thread t1(threadFunction);
   
   // 使用lambda表达式
   std::thread t2([]() {
       // 线程要执行的代码
   });
   ```

2. **等待线程结束**
   ```cpp
   t1.join();  // 主线程等待t1完成
   t2.join();  // 主线程等待t2完成
   ```

3. **分离线程**
   ```cpp
   t1.detach(); // 将线程与主线程分离，允许独立运行
   ```

4. **检查线程状态**
   ```cpp
   bool joinable = t1.joinable(); // 检查线程是否可以join
   ```

5. **获取线程ID**
   ```cpp
   std::thread::id id = t1.get_id(); // 获取线程ID
   ```

注意事项：
- 每个线程必须在销毁前调用join()或detach()
- 不能对同一个线程多次调用join()或detach()
- 分离的线程不能再被join()
- 主线程结束时，如果还有未join的线程，程序会崩溃

#### 2.1.2 线程同步
线程同步是多线程编程中的重要概念，用于协调多个线程对共享资源的访问。C++提供了多种同步机制：

1. **互斥锁 (Mutex)**
   ```cpp
   #include <mutex>
   
   std::mutex mtx;  // 创建互斥锁
   
   // 基本用法
   mtx.lock();    // 获取锁
   // 临界区代码
   mtx.unlock();  // 释放锁
   
   // 使用RAII方式（推荐）
   std::lock_guard<std::mutex> lock(mtx);  // 自动加锁和解锁
   // 临界区代码
   ```
    unique_lock<mutex> lock(mtx); 和 lock_guard<mutex> lock(mtx); 的区别：
    unique_lock<mutex> lock(mtx); 可以手动解锁，而 lock_guard<mutex> lock(mtx); 不能手动解锁。

2. **条件变量**
   ```cpp
   #include <condition_variable>
   
   std::mutex mtx;
   std::condition_variable cv;
   
   // 等待条件
   std::unique_lock<std::mutex> lock(mtx);
   cv.wait(lock, []{ return condition; });

   // wait的三种使用方法:
   
   // 1. 无条件等待 - 线程会一直等待直到被通知
   cv.wait(lock);  // 可能会有虚假唤醒,建议使用带条件的重载形式
   
   // 2. 带条件的等待 - 提供lambda表达式作为条件判断
   cv.wait(lock, []{ return condition; });  // 只有当condition为true时才继续执行
   
   // 3. 带超时的等待 - 等待指定时间后返回
   // 使用wait_for等待一段时间
   cv.wait_for(lock, std::chrono::seconds(1));  
   
   // 使用wait_until等待到指定时间点
   auto timeout = std::chrono::system_clock::now() + std::chrono::seconds(1);
   cv.wait_until(lock, timeout);
   
   // wait的工作机制:
   // 1. 调用wait时会自动释放锁
   // 2. 被唤醒时会自动重新获取锁
   // 3. 带条件的wait会在被唤醒后检查条件:
   //    - 如果条件为true,继续执行
   //    - 如果条件为false,继续等待
   
   // 通知等待的线程
   cv.notify_one();  // 通知一个等待的线程
   cv.notify_all();  // 通知所有等待的线程
   ```

3. **原子操作**
   ```cpp
   #include <atomic>
   
   std::atomic<int> counter(0);  // 原子计数器
   counter++;  // 原子递增
   counter--;  // 原子递减
   ```

4. **读写锁**
   ```cpp
   #include <shared_mutex>
   
   std::shared_mutex rwMutex;
   
   // 写操作（独占锁）
   std::unique_lock<std::shared_mutex> writeLock(rwMutex);
   
   // 读操作（共享锁）
   std::shared_lock<std::shared_mutex> readLock(rwMutex);
   ```

注意事项：
- 避免死锁：按固定顺序获取多个锁
- 尽量减小临界区范围
- 优先使用高级同步工具（如std::lock_guard）而不是直接使用mutex
- 条件变量可能存在虚假唤醒，需要在循环中检查条件
- 使用原子操作代替简单的互斥锁可以提高性能

常见的同步问题：
1. **死锁**：多个线程互相等待对方持有的资源
2. **竞态条件**：多个线程同时访问共享资源导致的不确定性
3. **优先级反转**：低优先级线程持有高优先级线程需要的资源
4. **饥饿**：线程长时间无法获取所需资源

最佳实践：
- 使用RAII管理资源和锁
- 设计时最小化共享数据
- 优先使用消息传递而不是共享内存
- 仔细考虑同步策略，避免过度同步

