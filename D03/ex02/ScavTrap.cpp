#include "ScavTrap.hpp"

ScavTrap::ScavTrap(ScavTrap const &src) :ClapTrap(){
    std::cout << "Copy Scav Constructor Called" << std::endl;
    *this = src;
}

ScavTrap::ScavTrap() : ClapTrap(){
    std::cout << "Default Scav Constructor Called" << std::endl;
}
//
ScavTrap::ScavTrap(const std::string str) : ClapTrap(str){
    std::cout << "String Scav Constructor Called" << std::endl;
    this->HitPoint = 100;
    this->EnergyPoint = 50;
    this->level = 1;
    this->meleeAttackDamage = 20;
    this->rangedAttackDamage = 15;
    this->ArmorAttackReduction = 3;
}

ScavTrap::~ScavTrap() {
    std::cout << "Scav Destructor Called" << std::endl;
}

void ScavTrap::challengeNewcomer(const std::string  &target) const
{
    std::string randomChallenge[7];
    srand(time(NULL));

    randomChallenge[0] = "I am the best robot. Yeah, yeah, yeah, I am the best robot. Ooh, ooh, here we go!";
    randomChallenge[1] = "Wanna hear a new dubstep song I wrote? Wub! Wub";
    randomChallenge[2] = "Good as new, I think. Am I leaking?";
    randomChallenge[3] = "Please open the box";
    randomChallenge[4] = "I can see through time...";
    randomChallenge[5] = "Please don't shoot me, please don't shoot me, please don't shoot me!";
    randomChallenge[6] = "Turning off the optics... they can't see me...";

    std::cout << "<ScavTrap> Hey <" << target << ">" << randomChallenge[std::rand() % 6] << std::endl;


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