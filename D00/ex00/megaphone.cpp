#include <iostream>


int ft_strLen(std::string str) {
    int i;
    i = 0;
    while (str[i] && str[i] != '\0') {
        i++;
    }
    return i;
}

std::string ft_strToUpper(std::string str) {
    int lengh = ft_strLen(str);
    int i = 0;
    while (i < lengh) {
        if (97 <= str[i] && str[i] <= 122)
            str[i] -= 32;
        i++;
    }
    return str;
}

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    else {

        int i;
        i = 1;
        while (argv[i]) {
            std::cout << ft_strToUpper(argv[i]) << " ";
            i++;
        }
    }
    std::cout << std::endl;
    return 0;
}

