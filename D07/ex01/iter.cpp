#include <iostream>

template<typename arrayType>
void iter(arrayType *arr, unsigned int size, void(*fct)(arrayType)) {
    for (int i = 0; i < size; i++) {
        fct(&arr[0][i]);
    }
}

template<typename T>
void print(T *lhs) {
    std::cout << *lhs << std::endl;
}

int main() {
    int array[3];

    array[0] = 21;
    array[1] = 42;
    array[2] = 84;

    std::string arrayString[3];
    arrayString[0] = "salut";
    arrayString[1] = "coucou";
    arrayString[2] = "hello";

    ::iter(&array, 3, print);
    ::iter(&arrayString, 3, print);
    return 0;
}