# C++ 教程

## 1. 基础语法

### 1.1 变量

```c++
int a = 10;
```
// vector的基本使用
#include <vector>


// 创建vector
vector<int> vec;                    // 空vector
vector<int> vec2(5);               // 包含5个元素的vector
vector<int> vec3(5, 2);            // 包含5个值为2的元素

// 添加和删除元素
vec.push_back(1);                  // 在末尾添加元素
vec.pop_back();                    // 删除末尾元素
vec.insert(vec.begin(), 2);        // 在指定位置插入元素
vec.erase(vec.begin());            // 删除指定位置的元素

// 访问元素
int first = vec[0];                // 使用下标访问
int last = vec.back();             // 访问最后一个元素
int first2 = vec.front();          // 访问第一个元素

// 获取大小和容量
size_t size = vec.size();          // 获取元素个数
bool isEmpty = vec.empty();        // 检查是否为空
size_t capacity = vec.capacity();  // 获取容量

// 遍历vector
for(int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
}

// 使用迭代器遍历
for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    cout << *it << " ";
}

// 使用范围for循环(C++11)
for(const auto& element : vec) {
    cout << element << " ";
}
