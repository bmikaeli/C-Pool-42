#include "Squad.hpp"

//Squad::Squad() : container(new ISpaceMarine[0]), Count(0) {
//}
Squad::Squad() : container() {

}


Squad::~Squad() {
    for (int i = 0; i < this->getCount(); ++i) {
        ISpaceMarine *cur = this->getUnit(i);
        delete cur;
    }
}

int Squad::getCount() const {
    return this->Count;
}

ISpaceMarine *Squad::getUnit(int i) {
//    return this->container[i];
}


int Squad::push(ISpaceMarine *src) {

//    ISpaceMarine newUnit = ISpaceMarine[this->getCount() + 1];
//    for (int i = 0; i < this->getCount(); ++i) {
//        newUnit[i] = this->container[i];
//    }
//    newUnit[i] = src;
//    delete[] this->container;
//    this->container = newUnit;
//    this->Count++;
}
