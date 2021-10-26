#ifndef USINE_HPP
#define USINE_HPP

#include "carte.hpp"

class UsineCarte {
private:
    unsigned _currentCardNb;
    unsigned _maxValue;

public:
    UsineCarte();
    UsineCarte(unsigned maxValue);
    UsineCarte& operator=(const UsineCarte&) = delete;
    UsineCarte(const UsineCarte&) = delete;

    Carte* getCarte();
};

#endif
