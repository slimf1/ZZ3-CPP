#include "usine.hpp"

UsineCarte::UsineCarte()
    : UsineCarte(52) {

}

UsineCarte::UsineCarte(unsigned maxValue) 
    : _currentCardNb(0), _maxValue(maxValue) {

}

Carte* UsineCarte::getCarte() {
    if (_currentCardNb >= _maxValue)
        return nullptr;

    return new Carte(_currentCardNb++);
}
