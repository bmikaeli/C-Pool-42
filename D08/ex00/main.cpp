#include <iostream>
#include <list>
#include <vector>
#include "easyfind.hpp"

int		main( void ) {
    std::list<int>		lst;
    std::vector<int>	vct;

    lst.push_back(3);
    lst.push_back(20);
    lst.push_back(12);
    lst.push_back(16);
    lst.push_back(8);

    vct.push_back(2);
    vct.push_back(20);
    vct.push_back(12);
    vct.push_back(16);
    vct.push_back(8);

    try {
        easyfind(lst, 20);
        std::cout << "found" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        easyfind(vct, 13);
        std::cout << "found" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return (0);
}
