#ifndef ECHANTILLON_HPP
#define ECHANTILLON_HPP

#include <algorithm>
#include <exception>
#include <vector>
#include "valeur.hpp"

class Echantillon {
private:
    std::vector<Valeur> _values;

public:
    void ajouter(const Valeur& value);
    size_t getTaille() const;
    Valeur getMinimum() const;
    Valeur getMaximum() const;
    Valeur getValeur(unsigned index) const; 
};

void Echantillon::ajouter(const Valeur& value) {
    _values.push_back(value);
}

size_t Echantillon::getTaille() const {
    return _values.size();
}

Valeur Echantillon::getMinimum() const {
    if (getTaille() == 0u) {
        throw std::domain_error("Array is empty");
    }
    return *std::min_element(_values.begin(), _values.end(), [](const Valeur& a, const Valeur& b){
        return a.getNombre() < b.getNombre();
    });
}

Valeur Echantillon::getMaximum() const {
    if (getTaille() == 0u) {
        throw std::domain_error("Array is empty");
    }
    return *std::max_element(_values.begin(), _values.end(), [](const Valeur& a, const Valeur& b){
        return a.getNombre() < b.getNombre();
    });
}

Valeur Echantillon::getValeur(unsigned index) const {
    if (index >= getTaille()) {
        throw std::out_of_range("Index out of range");
    }
    return _values[index];
}

#endif // ECHANTILLON_HPP
