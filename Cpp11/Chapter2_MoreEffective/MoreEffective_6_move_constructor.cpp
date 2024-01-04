#include <iostream>

using namespace std;

// 本质特定意义（使用场景下的浅拷贝），取名为移动构造，解决的还是效率问题
// 对象中含有堆上的资源 --> 深拷贝

// 抄近路

class HasPtrMem {
public:
    // 默认构造
    HasPtrMem() : _d(new int(100)) {
        cout << "HasPtrMem() " << this << endl;
    }

    // 拷贝构造
    HasPtrMem(const HasPtrMem &another) : _d(new int(*another._d)) {
        cout << "HasPtrMem(const HasPtrMem &another) " << this << " -> " << &another << endl;
    }

    // 移动构造
    HasPtrMem(HasPtrMem &&another) noexcept {
        cout << "HasPtrMem(HasPtrMem &&another) " << this << " -> " << &another << endl;
        this->_d = another._d;
        another._d = nullptr;
    }

    HasPtrMem &operator=(HasPtrMem &&another) noexcept {
        cout << "HasPtrMem& operator=(HasPtrMem &&another) " << this << " -> " << &another << endl;
        if (this != &another) {
            delete _d;
            this->_d = another._d;
            another._d = nullptr;
        }
        return *this;
    }

    ~HasPtrMem() {
        if (nullptr != _d) {
            delete _d;
        }
        cout << "~HasPtrMem() " << this << endl;
    }

    void show() {
        if (this->_d == nullptr) {
            cout << "_d is nullptr" << endl;
        } else {
            cout << "show: " << this->_d << endl;
        }
    }

    int *_d;
};

HasPtrMem move_hasPtrMem(HasPtrMem &&hasPtrMem) {
    cout << "move_hasPtrMem" << endl;
    HasPtrMem h = static_cast<HasPtrMem &&>(hasPtrMem);
    cout << "move_hasPtrMem: " << &h << endl;
    return h;
}

//HasPtrMem getTemp() {
//    return HasPtrMem();
//}

HasPtrMem getTemp() {
    HasPtrMem hasPtrMem;
    return hasPtrMem;
}

HasPtrMem getTemp3(HasPtrMem &&hasPtrMem) {
    return hasPtrMem;
}


int main() {

//    HasPtrMem a;
//    cout << "a's addr: " << &a << endl;
    move_hasPtrMem(getTemp());
//     HasPtrMem b(a);
//    HasPtrMem b = a;
//    HasPtrMem c = static_cast<HasPtrMem &&>(a); // a 失去了自己的数据 a._d == nullptr
//
//    cout << "a's " ;
//    a.show();


    // cout << a._d << endl;
    // cout << b._d << endl;

//    HasPtrMem &&ret = getTemp();
//    cout << "--------" << endl;
//    cout << &ret << endl;
//    cout << "--------" << endl;

    return 0;
}