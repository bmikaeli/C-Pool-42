#include <iostream>
#include <cstdlib>
#include <cstring>

int compute_float(char *src) {

    int i = static_cast<int>(atoi(src));
    char c = static_cast<char>(atoi(src));
    double d = static_cast<double>(atof(src));
    float f = static_cast<float>(strtof(src, NULL));


    if (atoi(src) >= 128 || atoi(src) < 32) {
        std::cout << "char: " << "impossible" << std::endl;
    }
    else {
        std::cout << "char: " << c << std::endl;
    }
    if (atol(src) > 2147483647 || atol(src) < -2147483647) {
        std::cout << "int: " << "impossible" << std::endl;
    }
    else {
        std::cout << "int: " << i << std::endl;
    }
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
    return 1;
}

int compute_char(char *src) {

    int i = static_cast<int>(src[0]);
    char c = static_cast<char>(src[0]);
    double d = static_cast<double>(src[0]);
    float f = static_cast<float>(src[0]);


    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
    return 1;

}

int compute_int(char *src) {

    int i = static_cast<int>(atoi(src));
    char c = static_cast<char>(atoi(src));
    double d = static_cast<double>(atof(src));
    float f = static_cast<float>(strtof(src, NULL));

    if (atoi(src) >= 128 || atoi(src) < 0) {
        std::cout << "char: " << "impossible" << std::endl;
    }
    else {
        std::cout << "char: " << c << std::endl;
    }
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
    return 1;

}

int compute_double(char *src) {

    int i = static_cast<int>(atoi(src));
    char c = static_cast<char>(atoi(src));
    double d = static_cast<double>(atof(src));
    float f = static_cast<float>(strtof(src, NULL));

    if (atoi(src) >= 128 || atoi(src) < 0) {
        std::cout << "char: " << "impossible" << std::endl;
    }
    else {
        std::cout << "char: " << c << std::endl;
    }
    if (atol(src) > 2147483647 || atol(src) < -2147483647) {
        std::cout << "int: " << "impossible" << std::endl;

    }
    else {
        std::cout << "int: " << i << std::endl;

    }
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
    return 1;

}

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cerr << "no argv[1]" << std::endl;
        return 0;
    }
    if (std::strlen(argv[1]) == 1) {
        if (!isalpha(argv[1][0])) {
            return compute_int(argv[1]);
        }
        else {
            return compute_char(argv[1]);
        }
    }
    else {
        for (unsigned int i = 0; i <= std::strlen(argv[1]); i++) {
            if (i > 0 && (argv[1][i] >= '9')) {
                std::cout << "Invalid input" << std::endl;
                return 0;
            }
            if (argv[1][std::strlen(argv[1]) - 1] == 'f') {
                return compute_float(argv[1]);
            }
            if (argv[1][i] == '.') {
                if (argv[1][std::strlen(argv[1]) - 1] == 'f') {
                    return compute_float(argv[1]);
                }
                else {
                    return compute_double(argv[1]);
                }
            }
        }
    }
    if (atol(argv[1]) > 2147483647 || atol(argv[1]) < -2147483647) {
        return compute_double(argv[1]);
    }
    else {
        return compute_int(argv[1]);
    }

};