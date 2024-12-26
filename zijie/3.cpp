// #include <iostream>
// #include <queue>
// #include <thread>
// #include <mutex>
// #include <condition_variable>
// #include <vector>
// #include <algorithm>

// using namespace std;

// // 定义共享资源和同步原语
// queue<int> dataQueue;             // 共享队列,用于生产者和消费者之间传递数据
// vector<int> sharedSpace;          // 共享向量空间,存储所有消费的数据
// mutex mtx;                        // 互斥锁,保护共享资源的访问
// condition_variable not_full;      // 条件变量,当队列不满时通知生产者
// condition_variable not_empty;     // 条件变量,当队列不空时通知消费者
// const int QUEUE_MAX_SIZE = 10;    // 队列最大容量
// const int TOTAL_ITEMS = 30;       // 生产者总共要生产的数据量
// bool producerFinished = false;    // 标记生产者是否完成生产

// // 生产者函数: 负责生产数据并放入队列
// void producer() {
//     for (int i = 0; i < TOTAL_ITEMS; i++) {
//         unique_lock<mutex> lock(mtx);    // 获取互斥锁
//         // 当队列满时等待,直到队列有空间
//         not_full.wait(lock, []{ return dataQueue.size() < QUEUE_MAX_SIZE; });
        
//         dataQueue.push(i);              // 将数据放入队列
//         cout << "Producer produced: " << i << endl;
        
//         lock.unlock();                  // 解锁
//         not_empty.notify_one();         // 通知一个等待的消费者
//     }
    
//     unique_lock<mutex> lock(mtx);       // 生产结束,设置标志
//     producerFinished = true;
//     lock.unlock();
//     not_empty.notify_all();             // 通知所有消费者生产已结束
// }

// // 消费者函数: 从队列中获取数据并处理
// // 参数id: 消费者的唯一标识符
// void consumer(int id) {
//     while (true) {
//         unique_lock<mutex> lock(mtx);    // 获取互斥锁
//         // 当队列空时等待,除非生产者已完成生产
//         not_empty.wait(lock, []{ 
//             return !dataQueue.empty() || producerFinished; 
//         });
        
//         // 如果队列为空且生产者已完成,则退出循环
//         if (dataQueue.empty() && producerFinished) {
//             lock.unlock();
//             break;
//         }
        
//         // 从队列中获取并移除一个数据
//         int value = dataQueue.front();
//         dataQueue.pop();
//         cout << "Consumer " << id << " consumed: " << value << endl;
        
//         // 将消费的数据添加到共享空间并排序
//         sharedSpace.push_back(value);
//         sort(sharedSpace.begin(), sharedSpace.end());
        
//         lock.unlock();                   // 解锁
//         not_full.notify_one();          // 通知生产者队列有空间
//     }
// }

// int main() {
//     // 创建生产者线程
//     thread producerThread(producer);
    
//     // 创建三个消费者线程
//     vector<thread> consumers;
//     for (int i = 0; i < 3; i++) {
//         consumers.push_back(thread(consumer, i));
//     }
    
//     // 等待所有线程完成执行
//     producerThread.join();
//     for (auto& t : consumers) {
//         t.join();
//     }
    
//     // 打印最终排序后的共享空间内容
//     cout << "\nFinal shared space contents (sorted):\n";
//     for (int value : sharedSpace) {
//         cout << value << " ";
//     }
//     cout << endl;
    
//     return 0;
// }


// 设计一个生产者-消费者模型，一个生产者，三个消费者，生产者往队列里填数据，消费者从队列拿数据，所有消费者把数据填充到一个共享空间里，并排序

#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <algorithm>
#include <mutex>
#include <condition_variable>

using namespace std;

queue<int> dataQueue;                // 数据队列
vector<int> sharedSpace;             // 共享空间
mutex mtx;                           // 互斥锁
condition_variable not_empty;        // 条件变量，表示队列非空
condition_variable not_full;         // 条件变量，表示队列未满
bool producerFinished = false;       // 生产者是否完成标志

void producer() {
    for (int i = 0; i < 100; ++i) {
        unique_lock<mutex> lock(mtx);
        dataQueue.push(i);
        cout << "Producer produced: " << i << endl;
        not_empty.notify_one();      // 通知消费者队列非空
    }
    unique_lock<mutex> lock(mtx);
    producerFinished = true;
    not_empty.notify_all();          // 通知所有消费者生产者已完成
}

void consumer(int id) {
    while (true) {
        unique_lock<mutex> lock(mtx);
        // 等待队列非空或生产者完成
        not_empty.wait(lock, [] { return !dataQueue.empty() || producerFinished; });
        
        // 如果队列为空且生产者已完成,则退出循环
        if (dataQueue.empty() && producerFinished) {
            lock.unlock();
            break;
        }
        
        // 从队列中获取并移除一个数据
        int value = dataQueue.front();
        dataQueue.pop();
        cout << "Consumer " << id << " consumed: " << value << endl;
        
        // 将消费的数据添加到共享空间并排序
        sharedSpace.push_back(value);
        sort(sharedSpace.begin(), sharedSpace.end());
        
        lock.unlock();                   // 解锁
        not_full.notify_one();          // 通知生产者队列有空间
    }
}

int main() {
    // 创建生产者线程
    thread producerThread(producer);
    
    // 创建三个消费者线程
    vector<thread> consumers;
    for (int i = 0; i < 3; i++) {
        consumers.push_back(thread(consumer, i));
    }
    
    // 等待所有线程完成执行
    producerThread.join();
    for (auto& t : consumers) {
        t.join();
    }
    
    // 打印最终排序后的共享空间内容
    cout << "\nFinal shared space contents (sorted):\n";
    for (int value : sharedSpace) {
        cout << value << " ";
    }
    cout << endl;
    
    return 0;
}


