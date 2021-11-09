#ifndef VALEUR_HPP
#define VALEUR_HPP

class Valeur {
private:
    double _value;

public:
    Valeur(double value = 0.0)
        : _value(value) {}

    double getNombre() const;
    void setNombre(double value);
};

double Valeur::getNombre() const {
    return _value;
}

void Valeur::setNombre(double value) {
    _value = value;
}

#endif // VALEUR_HPP
