// 设计一个生产者-消费者模型，一个生产者，三个消费者，生产者往队列里填数据，消费者从队列拿数据，所有消费者把数据填充到一个共享空间里，并排序
#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

