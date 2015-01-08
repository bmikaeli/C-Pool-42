#include "SuperTrap.hpp"

SuperTrap::SuperTrap(SuperTrap const &src) : ClapTrap(), FragTrap(), NinjaTrap() {
    std::cout << "Copy Super Constructor Called" << std::endl;
    *this = src;
}

SuperTrap::SuperTrap() : FragTrap(), NinjaTrap() {
    std::cout << "Default Super Constructor Called" << std::endl;
}

SuperTrap::SuperTrap(const std::string str) : FragTrap(), NinjaTrap(str) {
    std::cout << "String Super Constructor Called" << std::endl;
    this->HitPoint = this->FragTrap::HitPoint;
    this->MaxHitPoint = FragTrap::getMaxHitPoint();
    this->EnergyPoint = NinjaTrap::getEnergyPoint();
    this->MaxEnergyPoint = NinjaTrap::getMaxEnergyPoint();
    this->level = 1;
    this->name = str;
    this->meleeAttackDamage = NinjaTrap::getMeleeAttackDamage();
    this->rangedAttackDamage = FragTrap::getRangedAttackDamage();
    this->ArmorAttackReduction = this->FragTrap::getArmorAttackReduction();
}

SuperTrap::~SuperTrap() {
    std::cout << "Super Destructor Called" << std::endl;
}

SuperTrap &SuperTrap::operator=(const SuperTrap &rhs) {
    this->HitPoint = rhs.getHitPoint();
    this->HitPoint = rhs.getMaxHitPoint();
    this->EnergyPoint = rhs.getEnergyPoint();
    this->EnergyPoint = rhs.getMaxEnergyPoint();
    this->level = rhs.getLevel();
    this->name = rhs.getName();
    this->meleeAttackDamage = rhs.getMeleeAttackDamage();
    this->rangedAttackDamage = rhs.getRangedAttackDamage();
    this->ArmorAttackReduction = rhs.getArmorAttackReduction();
    return *this;
}