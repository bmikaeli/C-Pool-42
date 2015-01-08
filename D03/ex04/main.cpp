#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"


int main() {
    FragTrap b("Baptiste");
    FragTrap a("Anthony");
    NinjaTrap n("Etienne");
    ScavTrap c;
    ClapTrap d;

    c.challengeNewcomer("Anthony");
    c.challengeNewcomer("Baptiste");
    std::cout << "Anthony's Hp : " << a.getHitPoint() << std::endl;
    b.meleeAttack(a.getName());
    a.takeDamage(30);
    b.rangedAttack(a.getName());
    a.takeDamage(20);
    b.rangedAttack(a.getName());
    a.takeDamage(20);
    b.rangedAttack(a.getName());
    a.takeDamage(20);
    b.rangedAttack(a.getName());
    a.takeDamage(20);
    b.rangedAttack(a.getName());
    a.takeDamage(30);
    b.rangedAttack(a.getName());
    a.takeDamage(30);
    std::cout << "Anthony's Hp : " << a.getHitPoint() << std::endl;
    a.beRepaired(50);
    std::cout << "Anthony's Hp : " << a.getHitPoint() << std::endl;
    a.beRepaired(50);
    std::cout << "Anthony's Hp : " << a.getHitPoint() << std::endl;
    a.beRepaired(10);
    std::cout << "Anthony's Hp : " << a.getHitPoint() << std::endl;

    a.vaulthunter_dot_exe(b.getName());
    b.vaulthunter_dot_exe(a.getName());

    n.ninjaShoebox(a);
    n.ninjaShoebox(c);
    n.ninjaShoebox(n);
    n.ninjaShoebox(d);

    return 0;
}