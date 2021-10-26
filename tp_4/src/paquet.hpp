#ifndef PAQUET_HPP
#define PAQUET_HPP

#include <vector>
#include "carte.hpp"
#include "usine.hpp"

class Paquet {
private:
    std::vector<Carte*> _cards;

public:
    void remplir(UsineCarte& usine);
    Carte* operator[](unsigned index);
};

#endif // PAQUET_HPP
