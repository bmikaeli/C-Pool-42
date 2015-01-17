#ifndef CLIMONITOR_H
#define CLIMONITOR_H

#include "IMonitorDisplay.hpp"
#include <curses.h>
#include <signal.h>
#include <list>
#include "IMonitorModule.hpp"
#include <iostream>
#include <ctime>
#include <unistd.h>
class CliMonitor : public IMonitorDisplay {

public:
    CliMonitor();

    ~CliMonitor();
    void drawBorders(WINDOW * screen);
    void checkResize(WINDOW * screen);
    void launch(void);
    void addModule(IMonitorModule * src);
private:
    int width;
    int height;
    std::list<WINDOW *> windows;
    std::list<IMonitorModule *> modules;
};

#endif