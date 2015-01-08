#include "FragTrap.hpp"

FragTrap::FragTrap(FragTrap const &src) : ClapTrap() {
    std::cout << "Copy FragTrap Constructor Called" << std::endl;
    *this = src;
}

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "Default FragTrap Constructor Called" << std::endl;
}

FragTrap::FragTrap(const std::string str) : ClapTrap(str) {
    std::cout << "String FragTrap Constructor Called" << std::endl;
    this->HitPoint = 100;
    this->EnergyPoint = 100;
    this->level = 1;
    this->meleeAttackDamage = 30;
    this->rangedAttackDamage = 20;
    this->ArmorAttackReduction = 5;
}

FragTrap::~FragTrap() {
    std::cout << "Destructor FragTrap Called" << std::endl;

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