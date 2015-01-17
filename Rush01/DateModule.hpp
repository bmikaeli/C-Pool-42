#ifndef Date_MODULE_H
#define Date_MODULE_H

#include "IMonitorModule.hpp"
#include <iostream>

class DateModule : public IMonitorModule {
public:
    DateModule();

    ~DateModule();

    void execute(void);
};

#endif