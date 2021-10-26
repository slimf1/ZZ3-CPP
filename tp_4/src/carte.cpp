#include "carte.hpp"

Carte::Carte(unsigned value)
    : _value(value) {
}

unsigned Carte::getValeur() const {
    return _value;
}
