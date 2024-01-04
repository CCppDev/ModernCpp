#include <iostream>

int main() {
    int x1 = 0;
    double x2 = 5.5;
    std::cout << typeid(x1).name() << std::endl;
    std::cout << typeid(x1 + x2).name() << std::endl;
    std::cout << typeid(int).name() << std::endl;

    // auto t1 = typeid(int); // error: use of deleted function 'std::type_info::type_info(const std::type_info&)'
    auto &t2 = typeid(int);
    auto t3 = &typeid(int);
    auto *t4 = &typeid(int);
    return 0;
}