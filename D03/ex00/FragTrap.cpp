#include "FragTrap.hpp"

FragTrap::FragTrap(FragTrap const &src) : MaxEnergyPoint(100), MaxHitPoint(100) {
    std::cout << "Copy Constructor Called" << std::endl;

    *this = src;
}

FragTrap::FragTrap() : MaxEnergyPoint(100), MaxHitPoint(100) {
    std::cout << "Default Constructor Called" << std::endl;
}


FragTrap::FragTrap(const std::string str) : name(str), MaxEnergyPoint(100), MaxHitPoint(100) {
    std::cout << "String Constructor Called" << std::endl;
    this->HitPoint = 100;
    this->EnergyPoint = 100;
    this->level = 1;
    this->meleeAttackDamage = 30;
    this->rangedAttackDamage = 20;
    this->ArmorAttackReduction = 5;
}

FragTrap::~FragTrap() {
    std::cout << "Destructor Called" << std::endl;

}

void FragTrap::rangedAttack(const std::string &target) {
    std::cout << "FR4G-TP <" << this->getName() << "> attacks <" << target << "> at range, causing <" << this->getRangedAttackDamage() << "> points of damage" << std::endl;
}

void FragTrap::meleeAttack(const std::string &target) {
    std::cout << "FR4G-TP <" << this->getName() << "> attacks <" << target << "> at melee, causing <" << this->getMeleeAttackDamage() << "> points of damage" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
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

void FragTrap::vaulthunter_dot_exe(const std::string &target) {

    if ((this->getEnergyPoint() - 25) > -0) {
        std::string randomAttack[5];
        randomAttack[0] = "Knife";
        randomAttack[1] = "MachineGun";
        randomAttack[2] = "FireBall";
        randomAttack[3] = "Two Handed Axe";
        randomAttack[4] = "Sword";

        srand(time(NULL));

        this->EnergyPoint -= 25;
        std::cout << "FR4G-TP <" << this->getName() << "> is attacking <" << target << "> with " << randomAttack[std::rand() % 5] << std::endl;
    }
    else {
        std::cout << "FR4G-TP <" << this->getName() << "> Not enough Energy Points to attack" << std::endl;

    }

}

void FragTrap::takeDamage(unsigned int amount) {
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

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
    this->HitPoint = rhs.getHitPoint();
    this->EnergyPoint = rhs.getEnergyPoint();
    this->level = rhs.getLevel();
    this->name = rhs.getName();
    this->meleeAttackDamage = rhs.getMeleeAttackDamage();
    this->rangedAttackDamage = rhs.getRangedAttackDamage();
    this->ArmorAttackReduction = rhs.getArmorAttackReduction();
    return *this;
}

int FragTrap::getHitPoint() const {
    return HitPoint;
}

int const FragTrap::getMaxHitPoint() const {
    return MaxHitPoint;
}

int FragTrap::getEnergyPoint() const {
    return EnergyPoint;
}

int const FragTrap::getMaxEnergyPoint() const {
    return MaxEnergyPoint;
}

int FragTrap::getLevel() const {
    return level;
}

std::string FragTrap::getName() const {
    return name;
}

int FragTrap::getMeleeAttackDamage() const {
    return meleeAttackDamage;
}

int FragTrap::getRangedAttackDamage() const {
    return rangedAttackDamage;
}

int FragTrap::getArmorAttackReduction() const {
    return ArmorAttackReduction;
}
