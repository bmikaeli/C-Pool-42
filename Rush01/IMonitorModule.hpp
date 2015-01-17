#ifndef IMonitorModule_H
#define IMonitorModule_H

class IMonitorModule {
public:
    IMonitorModule();

    virtual ~IMonitorModule();

    virtual void execute(void) = 0;
};

#endif