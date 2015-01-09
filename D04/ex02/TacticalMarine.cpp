#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine() {
}

TacticalMarine::~TacticalMarine() {
    std::cout << "Aaargh ..." << std::endl;
}

void TacticalMarine::battleCry() const {
    std::cout << "For the holy PLOT !" << std::endl;
}

void TacticalMarine::meleeAttack() const {
    std::cout << "* attacks with chainsword *" << std::endl;

}

void TacticalMarine::rangedAttack() const {
    std::cout << "* attacks with bolter *" << std::endl;

}

ISpaceMarine *TacticalMarine::clone() const {
}
