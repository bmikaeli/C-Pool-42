#include "ScavTrap.hpp"

ScavTrap::ScavTrap(ScavTrap const &src) : MaxEnergyPoint(100), MaxHitPoint(100) {
    std::cout << "Copy Constructor Called" << std::endl;
    *this = src;
}

ScavTrap::ScavTrap() : MaxEnergyPoint(100), MaxHitPoint(100) {
    std::cout << "Default Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(const std::string str) : name(str), MaxEnergyPoint(100), MaxHitPoint(100) {
    std::cout << "String Constructor Called" << std::endl;
    this->HitPoint = 100;
    this->EnergyPoint = 50;
    this->level = 1;
    this->meleeAttackDamage = 20;
    this->rangedAttackDamage = 15;
    this->ArmorAttackReduction = 3;
}

ScavTrap::~ScavTrap() {
    std::cout << "Destructor Called" << std::endl;

}

void ScavTrap::rangedAttack(const std::string &target) {
    std::cout << "FR4G-TP <" << this->getName() << "> attacks <" << target << "> at range, causing <" << this->getRangedAttackDamage() << "> points of damage" << std::endl;
}

void ScavTrap::meleeAttack(const std::string &target) {
    std::cout << "FR4G-TP <" << this->getName() << "> attacks <" << target << "> at melee, causing <" << this->getMeleeAttackDamage() << "> points of damage" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
    if (this->getHitPoint() >= this->getMaxHitPoint()) {
        std::cout << "The unit is already at Max Hit Point" << std::endl;
    }
    else {
        if (this->getHitPoint() == 0) {
            std::cout << "FR4G-TP <" << this->getName() << "> has been resurected" << std::endl;
        }
        std::cout << "FR4G-TP <" << this->getName() << "> is heal by " << amount << "> Hit points" << std::endl;
        if ((this->getHitPoint() + amount) > this->getMaxHitPoint()) {
            this->HitPoint = this->getMaxHitPoint();
        }
        else {
            this->HitPoint += amount;
        }

    }
}

void ScavTrap::challengeNewcomer(const std::string  &target) const
{
    std::string randomChallenge[7];
    srand(time(NULL));

    randomChallenge[0] = "I am the best robot. Yeah, yeah, yeah, I am the best robot. Ooh, ooh, here we go!\"";
    randomChallenge[1] = "Wanna hear a new dubstep song I wrote? Wub! Wub";
    randomChallenge[2] = "Good as new, I think. Am I leaking?";
    randomChallenge[3] = "Please open the box";
    randomChallenge[4] = "I can see through time...";
    randomChallenge[5] = "Please don't shoot me, please don't shoot me, please don't shoot me!";
    randomChallenge[6] = "Turning off the optics... they can't see me...";

    std::cout << "<ScavTrap> " << randomChallenge[std::rand() % 6] << std::endl;

}

void ScavTrap::takeDamage(unsigned int amount) {
    amount -= this->getArmorAttackReduction();
    if (this->getHitPoint() <= 0)
        std::cout << "this unit is already dead" << std::endl;
    else {
        if ((this->getHitPoint() < amount)) {
            this->HitPoint = 0;
            std::cout << "FR4G-TP <" << this->getName() << "> is hit by <" << amount + this->getArmorAttackReduction() << "> Hit points " << "(reduced to " << amount << ")" << std::endl;
            std::cout << "FR4G-TP <" << this->getName() << "> This unit is now dead" << std::endl;
        }
        else {
            this->HitPoint -= amount;
            std::cout << "FR4G-TP <" << this->getName() << "> is hit by <" << amount + this->getArmorAttackReduction() << "> Hit points " << "(reduced to " << amount << ")" << std::endl;
        }
    }

}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
    this->HitPoint = rhs.getHitPoint();
    this->EnergyPoint = rhs.getEnergyPoint();
    this->level = rhs.getLevel();
    this->name = rhs.getName();
    this->meleeAttackDamage = rhs.getMeleeAttackDamage();
    this->rangedAttackDamage = rhs.getRangedAttackDamage();
    this->ArmorAttackReduction = rhs.getArmorAttackReduction();
    return *this;
}

int ScavTrap::getHitPoint() const {
    return HitPoint;
}

int const ScavTrap::getMaxHitPoint() const {
    return MaxHitPoint;
}

int ScavTrap::getEnergyPoint() const {
    return EnergyPoint;
}

int const ScavTrap::getMaxEnergyPoint() const {
    return MaxEnergyPoint;
}

int ScavTrap::getLevel() const {
    return level;
}

std::string ScavTrap::getName() const {
    return name;
}

int ScavTrap::getMeleeAttackDamage() const {
    return meleeAttackDamage;
}

int ScavTrap::getRangedAttackDamage() const {
    return rangedAttackDamage;
}

int ScavTrap::getArmorAttackReduction() const {
    return ArmorAttackReduction;
}
