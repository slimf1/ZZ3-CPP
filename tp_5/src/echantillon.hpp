#ifndef ECHANTILLON_HPP
#define ECHANTILLON_HPP

#include <vector>
#include "valeur.hpp"

class Echantillon {
private:
    std::vector<Valeur> _values;

public:
    using value_type = Valeur;

    void ajouter(const Valeur& value);
    void push_back(const Valeur& value) {ajouter(value);}
    size_t getTaille() const;
    const Valeur& getMinimum() const;
    const Valeur& getMaximum() const;
    const Valeur& getValeur(unsigned index) const;
    typename std::vector<Valeur>::iterator begin(); 
    typename std::vector<Valeur>::iterator end(); 
};

#endif // ECHANTILLON_HPP
