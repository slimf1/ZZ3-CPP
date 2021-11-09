#include "carte.hpp"

int Carte::_instanceCounter = 0;

Carte::Carte(unsigned value)
    : _value(value) {
    _instanceCounter++;
}

unsigned Carte::getValeur() const {
    return _value;
}

Carte::~Carte() {
    _instanceCounter--;
}

int Carte::getCompteur() {
    return _instanceCounter;
}
