#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N) {
    std::cout << "ZombieHorde constuctor" << std::endl;
    this->createZombie(N);
}

ZombieHorde::~ZombieHorde() {
    delete[] this->horde;
    std::cout << "ZombieHorde destructor" << std::endl;
}

void ZombieHorde::announce() {

    int i = 0;
    while (i < this->numberOfZombie) {
        this->horde[i].announce();
        i++;
    }
    return;
}

void ZombieHorde::createZombie(int N) {
    Zombie *horde = new Zombie[N];
    this->horde = horde;
    this->numberOfZombie = N;
    int i = 0;
    int random;
    std::string arrayRand[7];
    std::srand(time(NULL));

    arrayRand[0] = "John";
    arrayRand[1] = "Frank";
    arrayRand[2] = "Anthony";
    arrayRand[3] = "Gertrude";
    arrayRand[4] = "Salut";
    arrayRand[5] = "42";
    arrayRand[6] = "84";

    while (i < N) {
        random = std::rand();
        this->horde[i].setName(arrayRand[random % 6]);
        this->horde[i].setType("TypeRandom");
        i++;
    }
    this->announce();
}
