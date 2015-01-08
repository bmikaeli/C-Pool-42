#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

#include <iostream>
#include <cstdlib>

class ClapTrap {
public:

    ClapTrap(ClapTrap const &);

    ClapTrap();

    ClapTrap(std::string const name);

    ~ClapTrap(void);

    ClapTrap &operator=(ClapTrap const &rhs);

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

protected:
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