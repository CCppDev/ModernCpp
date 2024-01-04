#include <iostream>



struct S1 {
    int x1;
    decltype(x1) x2;
    double x3;
    decltype(x2 + x3) x4;
};

int x1 = 0;

decltype(x1) sum(decltype(x1) a1, decltype(a1) a2) {
    return a1 + a2;
}

auto x2 = sum(5, 10);