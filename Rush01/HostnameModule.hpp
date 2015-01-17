#ifndef HOSTNAME_MODULE_H
#define HOSTNAME_MODULE_H

#include "IMonitorModule.hpp"
#include <iostream>

class HostnameModule : public IMonitorModule {
public:
    HostnameModule();

    ~HostnameModule();

    void execute(void);
};

#endif