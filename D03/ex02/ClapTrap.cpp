#include "ClapTrap.hpp"

ClapTrap::ClapTrap(ClapTrap const &src) {
    std::cout << "Copy ClapTrap Constructor Called" << std::endl;
    *this = src;
}

ClapTrap::ClapTrap(){
    std::cout << "Default ClapTrap Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(const std::string str) : name(str){
    std::cout << "String ClapTrap Constructor Called" << std::endl;
    this->HitPoint = 100;
    this->MaxEnergyPoint = 100;
    this->EnergyPoint = 50;
    this->MaxEnergyPoint = 100;
    this->level = 1;
    this->meleeAttackDamage = 20;
    this->rangedAttackDamage = 15;
    this->ArmorAttackReduction = 3;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor ClapTrap Called" << std::endl;

}

void ClapTrap::rangedAttack(const std::string &target) {
    std::cout << "FR4G-TP <" << this->getName() << "> attacks <" << target << "> at range, causing <" << this->getRangedAttackDamage() << "> points of damage" << std::endl;
}

void ClapTrap::meleeAttack(const std::string &target) {
    std::cout << "FR4G-TP <" << this->getName() << "> attacks <" << target << "> at melee, causing <" << this->getMeleeAttackDamage() << "> points of damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->getHitPoint() >= this->getMaxHitPoint()) {
        std::cout << "The unit is already at Max Hit Point" << std::endl;
    }
    else {
        if (this->getHitPoint() == 0) {
            std::cout << "FR4G-TP <" << this->getName() << "> has been resurected" << std::endl;
        }
        std::cout << "FR4G-TP <" << this->getName() << "> is heal by " << amount << "> Hit points" << std::endl;
        if ((this->getHitPoint() + (int)amount) > this->getMaxHitPoint()) {
            this->HitPoint = this->getMaxHitPoint();
        }
        else {
            this->HitPoint += amount;
        }

    }
}
void ClapTrap::takeDamage(unsigned int amount) {
    amount -= this->getArmorAttackReduction();
    if (this->getHitPoint() <= 0)
        std::cout << "this unit is already dead" << std::endl;
    else {
        if ((this->getHitPoint() < (int)amount)) {
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

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
    this->HitPoint = rhs.getHitPoint();
    this->EnergyPoint = rhs.getEnergyPoint();
    this->level = rhs.getLevel();
    this->name = rhs.getName();
    this->meleeAttackDamage = rhs.getMeleeAttackDamage();
    this->rangedAttackDamage = rhs.getRangedAttackDamage();
    this->ArmorAttackReduction = rhs.getArmorAttackReduction();
    return *this;
}

int ClapTrap::getHitPoint() const {
    return HitPoint;
}

int ClapTrap::getMaxHitPoint() const {
    return MaxHitPoint;
}

int ClapTrap::getEnergyPoint() const {
    return EnergyPoint;
}

int ClapTrap::getMaxEnergyPoint() const {
    return MaxEnergyPoint;
}

int ClapTrap::getLevel() const {
    return level;
}

std::string ClapTrap::getName() const {
    return name;
}

int ClapTrap::getMeleeAttackDamage() const {
    return meleeAttackDamage;
}

int ClapTrap::getRangedAttackDamage() const {
    return rangedAttackDamage;
}

int ClapTrap::getArmorAttackReduction() const {
    return ArmorAttackReduction;
}
