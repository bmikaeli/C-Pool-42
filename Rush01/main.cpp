#include "HostnameModule.hpp"
#include "OsInfoModule.hpp"
#include "DateModule.hpp"
#include "CliMonitor.hpp"

int main() {
    HostnameModule test;
    OsInfoModule test2;
    DateModule test3;
    CliMonitor cli;

    test.execute();
    test2.execute();
    test3.execute();
    return 0;
}