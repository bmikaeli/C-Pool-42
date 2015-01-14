#include <iostream>

template<typename T>
class Array {
public:
    Array() : content(NULL), size(0) {
        return;
    }

    Array(unsigned int n) : content(new T[n]), size(n) {
    }

    Array(Array const &src) {
        *this = src;
    }

    Array &operator=(const Array<T> &rhs) {
        this->content = rhs.content;
        for (int i = 0; i < rhs.getSize(); i++) {
            content[i] = rhs.content[i];
        }
        return *this;
    }

    T &operator[](unsigned int n) {
        if (n >= size) {
            throw std::exception();
        }
        else {
            return this->content[n];
        }
    }

    ~Array() {
    }

    unsigned int getSize() const {
        return this->size;
    }

    T *content;
    unsigned size;
};