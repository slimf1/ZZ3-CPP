#ifndef CLASSE_HPP
#define CLASSE_HPP

class Classe {
private:
    double _lowerBound;
    double _upperBound;
    unsigned _quantity = 0u;

public:
    Classe(double lower, double upper)
        : _lowerBound(lower), _upperBound(upper) {}

    double getBorneInf() const;
    void setBorneInf(double lower);
    double getBorneSup() const;
    void setBorneSup(double upper);
    unsigned getQuantite() const;
    void setQuantite(unsigned quantity);
    void ajouter();
};

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
#endif // CLASSE_HPP
