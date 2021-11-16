#include <algorithm>
#include <stdexcept>
#include "echantillon.hpp"

void Echantillon::ajouter(const Valeur& value) {
    _values.push_back(value);
}

void Echantillon::push_back(const Valeur& value) {
    ajouter(value);
}

size_t Echantillon::getTaille() const {
    return _values.size();
}

const Valeur& Echantillon::getMinimum() const {
    if (getTaille() == 0u) {
        throw std::domain_error("Array is empty");
    }
    return *std::min_element(_values.begin(), _values.end(), [](const Valeur& a, const Valeur& b){
        return a.getNombre() < b.getNombre();
    });
}

const Valeur& Echantillon::getMaximum() const {
    if (getTaille() == 0u) {
        throw std::domain_error("Array is empty");
    }
    return *std::max_element(_values.begin(), _values.end(), [](const Valeur& a, const Valeur& b){
        return a.getNombre() < b.getNombre();
    });
}

const Valeur& Echantillon::getValeur(unsigned index) const {
    if (index >= getTaille()) {
        throw std::out_of_range("Index out of range");
    }
    return _values[index];
}

typename std::vector<Valeur>::iterator Echantillon::begin() {
    return _values.begin();
}

typename std::vector<Valeur>::iterator Echantillon::end() {
    return _values.end();
}
