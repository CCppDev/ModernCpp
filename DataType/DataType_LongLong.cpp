#include <iostream>

enum longlong_enum : long long {
    x1,
    x2
};

struct longlong_struct1 {
    long long x1 : 8;
    long long x2 : 16;
    long long x3 : 41;
};

struct longlong_struct2 {
    long long x1;
    long long x2;
    long long x3;
};

int main() {
    long l = 100l;

    long long ll = 1000ll;
    long long int lli = 100LL;

    unsigned long long ull = 10000ull;
    unsigned long long int ulli = 10000ULL;

    std::cout << "sizeof(long): " << sizeof(long) << "\n";
    std::cout << "sizeof(long long): " << sizeof(long long) << "\n";
    std::cout << "sizeof(longlong_enum): " << sizeof(longlong_enum) << "\n";
    std::cout << "sizeof(longlong_struct1): " << sizeof(longlong_struct1) << "\n";
    std::cout << "sizeof(longlong_struct2): " << sizeof(longlong_struct2) << "\n";

    std::printf("%lld\n", ll);
    std::printf("%llu\n", ulli);

    return 0;
}