#include "enchantement.hpp"

Enchantement::Enchantement(float power)
    : _power(power) {
    
}

float Enchantement::getPuissance() const {
    return _power;
}
