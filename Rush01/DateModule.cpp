#include "DateModule.hpp"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
DateModule::DateModule() {

}

DateModule::~DateModule() {

}

void DateModule::execute() {

    time_t result = time(NULL);
    std::cout << asctime(localtime(&result));
}