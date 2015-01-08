#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include "ClapTrap.hpp"


int main() {
//    FragTrap b("Baptiste");
//    FragTrap a("Anthony");
//    NinjaTrap n("Etienne");
//    ScavTrap c;
//    ClapTrap d;

//    c.challengeNewcomer("Anthony");
//    c.challengeNewcomer("Baptiste");
//    std::cout << "Anthony's Hp : " << a.getHitPoint() << std::endl;
//    b.meleeAttack(a.getName());
//    a.takeDamage(30);
//    b.rangedAttack(a.getName());
//    a.takeDamage(20);
//    b.rangedAttack(a.getName());
//    a.takeDamage(20);
//    b.rangedAttack(a.getName());
//    a.takeDamage(20);
//    b.rangedAttack(a.getName());
//    a.takeDamage(20);
//    b.rangedAttack(a.getName());
//    a.takeDamage(30);
//    b.rangedAttack(a.getName());
//    a.takeDamage(30);
//    std::cout << "Anthony's Hp : " << a.getHitPoint() << std::endl;
//    a.beRepaired(50);
//    std::cout << "Anthony's Hp : " << a.getHitPoint() << std::endl;
//    a.beRepaired(50);
//    std::cout << "Anthony's Hp : " << a.getHitPoint() << std::endl;
//    a.beRepaired(10);
//    std::cout << "Anthony's Hp : " << a.getHitPoint() << std::endl;
//
//    a.vaulthunter_dot_exe(b.getName());
//    b.vaulthunter_dot_exe(a.getName());

//    n.ninjaShoebox(a);
//    n.ninjaShoebox(c);
//    n.ninjaShoebox(n);
//    n.ninjaShoebox(d);

    SuperTrap supertrap("Super Ninja of the dead");
    std::cout << "Name : " << supertrap.getName() << std::endl;
    std::cout << "HitPoint : " << supertrap.getHitPoint() << std::endl;
    std::cout << "MaxHitPoint : " << supertrap.getMaxHitPoint() << std::endl;
    std::cout << "EnergyPoint : " << supertrap.getEnergyPoint() << std::endl;
    std::cout << "MaxEnergyPoint : " << supertrap.getMaxEnergyPoint() << std::endl;
    std::cout << "Level : " << supertrap.getLevel() << std::endl;
    std::cout << "MeleeAttackDamage : " << supertrap.getMeleeAttackDamage() << std::endl;
    std::cout << "RangedAttackDamage : " << supertrap.getRangedAttackDamage() << std::endl;
    std::cout << "Armor : " << supertrap.getArmorAttackReduction() << std::endl;

    supertrap.takeDamage(50);
    std::cout << "HitPoint : " << supertrap.getHitPoint() << std::endl;
    supertrap.beRepaired(12);
    std::cout << "HitPoint : " << supertrap.getHitPoint() << std::endl;

    return 0;
}