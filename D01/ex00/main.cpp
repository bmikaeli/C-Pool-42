#include "Pony.hpp"


void ponyOnTheStack() {

    Pony stackPony;
    stackPony.setColor("blue");
    stackPony.setName("PinkePie");
    stackPony.speak();
    return;
}


void ponyOnTheHeap() {
    Pony *heapPony;
    heapPony = new Pony();
    heapPony->setColor("red");
    heapPony->setName("rainbowDash");
    heapPony->speak();
    delete heapPony;
    return;
}

int main(void) {
    ponyOnTheStack();
    ponyOnTheHeap();
    return 0;
}