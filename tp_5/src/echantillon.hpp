#ifndef ECHANTILLON_HPP
#define ECHANTILLON_HPP

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

#endif // ECHANTILLON_HPP
