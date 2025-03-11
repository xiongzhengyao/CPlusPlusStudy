# C++三大特性

## 1. 封装
封装是面向对象编程的一个重要特性,它将数据和操作数据的方法捆绑在一起,对外部隐藏对象的内部细节。

示例代码:

```cpp
class Person {
public:
    void setName(const std::string& name) {
        this->name = name;
    }
private:
    std::string name;
};
```

### 1.1 C++类初始化成员变量
- 非静态成员变量
  - 在构造函数中初始化成员变量
  - 使用初始化列表初始化成员变量

示例代码:

```cpp
class Person {
public:
    Person() : age(0), name("") {} // 使用初始化列表
    Person(int age, std::string name) : age(age), name(name) {} // 使用构造函数
    void print() {
        std::cout << "Person age: " << age << std::endl;
        std::cout << "Person name: " << name << std::endl;
    }
private:
    int age;
    std::string name;
};
```
- 静态成员变量
  - 在类定义中初始化静态成员变量
  - 使用静态成员函数访问静态成员变量

示例代码:

```cpp
class Person {
public:
    static int count; // 在类定义中声明静态成员变量
    static void printCount() {
        std::cout << "Person count: " << count << std::endl;
    }
};
int Person::count = 0; // 在类外部初始化静态成员变量
```

## 2. 继承
继承是面向对象编程的一个重要特性，它允许子类继承父类的属性和方法，并可以覆盖父类的方法。

示例代码:

```cpp
class Animal {
public:
    void eat() {
        std::cout << "Animal is eating." << std::endl;
    }
};

class Dog : public Animal {
public:
    void eat() override {
        std::cout << "Dog is eating." << std::endl;
    }
};
```

## 3. 多态
多态是面向对象编程的一个重要特性，它允许不同的对象对同一消息做出不同的响应。

- C++中有两种多态: 编译时多态和运行时多态
  - 编译时多态: 通过函数重载和运算符重载实现
  - 运行时多态: 通过虚函数实现

- 虚函数: 在基类中声明为virtual的函数，在派生类中可以被重写

示例代码:

```cpp
class Animal {
public:
    virtual void eat() {
        std::cout << "Animal is eating." << std::endl;
    }
};

class Dog : public Animal {
public:
    void eat() override {
        std::cout << "Dog is eating." << std::endl;
    }
};
```

- 纯虚函数: 在基类中声明为virtual的函数，在派生类中必须被重写的函数
  - 使用 = 0 声明纯虚函数
  - 包含纯虚函数的类称为抽象类
  - 抽象类不能被实例化
  - 派生类必须实现所有纯虚函数，否则也会成为抽象类
  - 纯虚函数通常用于定义接口，强制派生类实现特定的行为

示例代码:

```cpp
class Animal {
public:
    virtual void eat() = 0;
};
```


## 4. unordered_map
unordered_map是C++标准库中的一个容器,它实现了哈希表的数据结构。

主要特点:
- 以键值对(key-value)形式存储数据
- 通过哈希函数实现O(1)的平均查找、插入和删除时间复杂度
- 键值不排序,元素的存储位置由哈希函数决定
- 键必须是唯一的,但值可以重复
- 键类型必须支持相等比较运算符(==)和哈希函数

常用操作示例:

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
int main() {
    // 创建一个unordered_map
    unordered_map<string, int> scores;

    // 插入元素的几种方式
    scores["Alice"] = 95;                     // 使用[]运算符
    scores.insert({"Bob", 89});               // 使用insert方法
    scores.insert(make_pair("Charlie", 92));  // 使用make_pair

    // 访问元素
    cout << "Alice's score: " << scores["Alice"] << endl;     // 使用[]
    cout << "Bob's score: " << scores.at("Bob") << endl;      // 使用at()

    
    // 检查键是否存在
    if (scores.find("David") == scores.end()) {
        cout << "David's score not found" << endl;
    }

    // 删除元素
    scores.erase("Bob");

    // 获取大小
    cout << "Map size: " << scores.size() << endl;

    // 遍历所有元素
    for (const auto& pair : scores) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // 清空map
    scores.clear();

    // 检查是否为空
    cout << "Is map empty? " << (scores.empty() ? "Yes" : "No") << endl;

    return 0;
}

``` 

unordered_map和map的区别:
- unordered_map: 使用哈希表实现,查找、插入和删除操作的平均时间复杂度为O(1)
- map: 使用红黑树实现,查找、插入和删除操作的时间复杂度为O(logn)
- 因此,如果需要频繁进行查找操作,使用unordered_map会更快

vector<vector<int>> 初始化:

```cpp
vector<vector<int>> prefixSum(n + 1, vector<int>(m + 1, 0)); // 初始化值是0
```