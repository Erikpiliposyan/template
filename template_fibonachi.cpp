#include <iostream>

template <int N>
struct Fibonacci {
    static const int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};


template <>
struct Fibonacci<0> {
    static const int value = 0;
};

template <>
struct Fibonacci<1> {
    static const int value = 1;
};

template <int N>
constexpr int fibonacci() {
    return Fibonacci<N>::value;
}

int main() {
    constexpr int n = 10;

    std::cout << "Fibonacci sequence up to " << n << " elements:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << fibonacci<i>() << " ";
    }
    std::cout << std::endl;

    return 0;
}
