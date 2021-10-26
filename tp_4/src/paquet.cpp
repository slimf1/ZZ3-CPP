#include "paquet.hpp"

void Paquet::remplir(UsineCarte& usine) {
    Carte* card = nullptr;

    while ((card = usine.getCarte()) != nullptr) {
        _cards.push_back(card);    
    }
}

Carte* Paquet::operator[](unsigned index) {
    return _cards[index];
}
