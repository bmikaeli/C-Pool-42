#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(NinjaTrap const &src) : ClapTrap() {
    std::cout << "Copy Ninja Constructor Called" << std::endl;
    *this = src;
}

NinjaTrap::NinjaTrap() : ClapTrap() {
    std::cout << "Default Ninja Constructor Called" << std::endl;
}

NinjaTrap::NinjaTrap(const std::string str) : ClapTrap(str) {
    std::cout << "String Ninja Constructor Called" << std::endl;
    this->HitPoint = 60;
    this->EnergyPoint = 120;
    this->MaxHitPoint = 60;
    this->MaxEnergyPoint = 120;
    this->level = 1;
    this->meleeAttackDamage = 60;
    this->rangedAttackDamage = 5;
    this->ArmorAttackReduction = 0;
}

NinjaTrap::~NinjaTrap() {
    std::cout << "Ninja Destructor Called" << std::endl;
}

void NinjaTrap::ninjaShoebox(const ClapTrap &clap) {
    std::cout << "Hello, i'm a Clap (clap clap clap) !" << std::endl;
    clap.getName();
}

void NinjaTrap::ninjaShoebox(const ScavTrap &ninja) {
    std::cout << "Hello, i'm a Scav !" << std::endl;
    ninja.getName();
}

void NinjaTrap::ninjaShoebox(const FragTrap &frag) {
    std::cout << "Hello, i'm a Frag !" << std::endl;
    frag.getName();
}

void NinjaTrap::ninjaShoebox(const NinjaTrap &scav) {
    std::cout << "Niiiiiiiiinjaaaa !" << std::endl;
    scav.getName();
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &rhs) {
    this->HitPoint = rhs.getHitPoint();
    this->EnergyPoint = rhs.getEnergyPoint();
    this->level = rhs.getLevel();
    this->name = rhs.getName();
    this->meleeAttackDamage = rhs.getMeleeAttackDamage();
    this->rangedAttackDamage = rhs.getRangedAttackDamage();
    this->ArmorAttackReduction = rhs.getArmorAttackReduction();
    return *this;
}