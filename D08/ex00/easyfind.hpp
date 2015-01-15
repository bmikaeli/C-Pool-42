#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <string>
#include <algorithm>

template<typename T>
void easyfind(T haystack, int needle) {
    if (std::find(haystack.begin(), haystack.end(), needle) == haystack.end())
        throw std::exception();
}

#endif