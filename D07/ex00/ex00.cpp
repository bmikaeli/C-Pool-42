#include <iostream>

template<typename T>
T max(T &lhs, T &rhs) {
    return ((lhs > rhs) ? lhs : rhs);
}

template<typename T>
void swap(T &lhs, T &rhs) {

    T tmp = rhs;
    rhs = lhs;
    lhs = tmp;
}

template<typename T>
T min(T &lhs, T &rhs) {
    return ((lhs > rhs) ? rhs : lhs);
}


int main() {
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
    return 0;
}