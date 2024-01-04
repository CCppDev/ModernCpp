/*
#include <iostream>

class Base {
public:
    virtual void f() {
        std::cout << "Base::f()" << std::endl;
    };
};

class Derived : public Base {
public:
    virtual void f() override {
        std::cout << "Derived::f()" << std::endl;
    };
};

int main() {
    Base *d = new Derived();
    auto b = *d;
    b.f(); // Base::f()

    auto &b2 = *d;
    b2.f(); // Derived::f()
    return 0;
}
*/

#include <iostream>

template<typename T>
void printValue(T value) {
    std::cout << value << std::endl;
}

//C++17
template<auto V>
void f() {
    std::cout << V << std::endl;
}

auto i = 5; // 推断为int
auto str = "hello auto"; // 推断为const char*
auto sum(int a1, int a2) -> int // 返回类型后置，auto为返回值占位符
{
    return a1 + a2;
}

int main() {


    printValue(5);       // 模板参数为 int 类型
    printValue(3.14);    // 模板参数为 double 类型
    printValue("Hello"); // 模板参数为 const char* 类型

    f<6>();
//    f<6.0>();

    int x1 = 0;
    double x2 = 5.5;
    std::cout << typeid(x1).name() << std::endl;
    std::cout << typeid(x1 + x2).name() << std::endl;
    std::cout << typeid(int).name() << std::endl;
    return 0;
}