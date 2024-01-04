#include <iostream>

// C++11
namespace Parent {
    namespace Child1 {
        void foo() {
            std::cout << "Parent::Child1::foo()\n";
        }
    }
    inline namespace Child2 {
        void foo() {
            std::cout << "Parent::foo()\n";
        }
    }
}

// C++17
namespace A::B::C {
    void foo() {

    }
}

// C++20
namespace A::B::
inline D {
void foo() {}

}

int main() {
    Parent::Child1::foo();
    Parent::foo();

    int i = 5;
    auto &&m = i; // auto推导类型为int& （这里涉及引用折叠的概念）
    auto &&j = 5; // auto推导类型为int

    int arr[] = {1, 2};
    std::printf("%#x\n", arr);
    std::printf("%#x\n", arr + 1);
    std::printf("%#x\n", &arr);
    std::printf("%#x\n", &arr + 1);
    return 0;
}
