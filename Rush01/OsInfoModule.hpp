#ifndef OS_INFO_H
#define OS_INFO_H

#include "IMonitorModule.hpp"
#include <iostream>

class OsInfoModule : public IMonitorModule {
public:
    OsInfoModule();

    ~OsInfoModule();

    void execute(void);
};

#endif