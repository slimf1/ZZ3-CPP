#include "classe.hpp"

double Classe::getBorneInf() const {
    return _lowerBound;
}

void Classe::setBorneInf(double lower) {
    _lowerBound = lower;
}

double Classe::getBorneSup() const {
    return _upperBound;
}

void Classe::setBorneSup(double upper) {
    _upperBound = upper;
}

unsigned Classe::getQuantite() const {
    return _quantity;
}

void Classe::setQuantite(unsigned quantity)  {
    _quantity = quantity;
}

void Classe::ajouter() {
    _quantity++;
}

bool operator<(const Classe& a, const Classe& b) {
    return a.getBorneInf() < b.getBorneInf();
}

bool operator>=(const Classe& a, const Classe& b) {
    return !(a < b);
}

bool operator>(const Classe& a, const Classe& b) {
    return a.getBorneInf() > b.getBorneInf();
}

bool operator<=(const Classe& a, const Classe& b) {
    return !(a > b);
}
