#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int flag = 1;

void function(int current,int next)
{
    std::unique_lock<std::mutex> lock(mtx);

    cv.wait(lock,[current]{return flag == current;});

    std::cout << current <<std::endl;

    flag = next;

    cv.notify_all();

}


int main()
{
    std::thread thread1(function,1,2);
    std::thread thread2(function,2,3);
    std::thread thread3(function,3,1);

    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}