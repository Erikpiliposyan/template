#include <iostream>


template <int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
    static const int value = 1;
};

template <int N>
constexpr int factorial() {
    return Factorial<N>::value;
}

int main() {
    constexpr int a = 5;
    constexpr int result = factorial<a>();

    
    std::cout << "Factorial of " << a << " is: " << result << std::endl;

    return 0;
}
