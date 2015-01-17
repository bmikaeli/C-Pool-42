#include "HostnameModule.hpp"
#include <unistd.h>
#include <stdlib.h>

HostnameModule::HostnameModule() {

}

HostnameModule::~HostnameModule() {

}

void HostnameModule::execute() {
    char hostname[20];

    gethostname(hostname, 20);
    std::cout << getenv("LOGNAME") << std::endl;
    std::cout << hostname << std::endl;
}