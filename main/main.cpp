#include <iostream>

class Person {
public:
    Person() : age(0), name("") {
        this->age = 0;
        this->name = "";
        std::cout << "Person constructor" << std::endl;
    } // Define the constructor to initialize age and name

    void print() {
        std::cout << "Person age: " << age << std::endl;
    }

    void changeinfo(int age, std::string name) { // Correct parameter name to match member variable
        this->age = age;
        this->name = name;
    }

    void getinfo(int &age, std::string &name) {
        age = this->age;
        name = this->name;
    }

private:
    int age;
    std::string name;
};  

int main() {
    Person ps;
    ps.print();
    ps.changeinfo(30, "zhangsan");
    ps.print();
    return 0;
}
