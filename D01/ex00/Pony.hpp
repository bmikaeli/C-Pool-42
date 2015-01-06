#ifndef PONY_H
# define PONY_H

#include <iostream>

class Pony{

public:
    Pony(void);
    ~Pony(void);
    void speak(void);
    void setColor(std::string);
    void setName(std::string);

private:
    std::string color;
    std::string name;
};
#endif