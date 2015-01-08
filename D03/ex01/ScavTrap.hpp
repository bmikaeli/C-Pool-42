#ifndef SCAV_TRAP_H
#define SCAV_TRAP_H

#include <iostream>
#include <cstdlib>

class ScavTrap {
public:

    ScavTrap(ScavTrap const &);

    ScavTrap();

    ScavTrap(std::string const name);

    ~ScavTrap(void);

    ScavTrap &operator=(ScavTrap const &rhs);

    void rangedAttack(std::string const &target);

    void meleeAttack(std::string const &target);

    void takeDamage(unsigned int amount);

    void beRepaired(unsigned int amount);

    int getArmorAttackReduction() const;;

    int getRangedAttackDamage() const;

    int getMeleeAttackDamage() const;

    std::string getName() const;

    int getLevel() const;

    int getMaxEnergyPoint() const;

    int getEnergyPoint() const;

    int getMaxHitPoint() const;

    int getHitPoint() const;

    void challengeNewcomer(std::string const &target) const;


private:
    int HitPoint;
    int MaxHitPoint;
    int EnergyPoint;
    int MaxEnergyPoint;
    int level;
    std::string name;
    int meleeAttackDamage;
    int rangedAttackDamage;
    int ArmorAttackReduction;
};

#endif