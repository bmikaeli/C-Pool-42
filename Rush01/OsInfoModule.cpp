#include "OsInfoModule.hpp"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/utsname.h>


OsInfoModule::OsInfoModule() {

}

OsInfoModule::~OsInfoModule() {

}

void OsInfoModule::execute() {

    struct utsname unameData;

    uname(&unameData);

    std::cout << unameData.sysname << std::endl;
}