#ifndef HISTOGRAMME_HPP
#define HISTOGRAMME_HPP

#include <algorithm>
#include <functional>
#include <set>
#include "classe.hpp"
#include "echantillon.hpp"

template <typename Compare = std::less<Classe>>
class Histogramme {
private:
    std::set<Classe, Compare> _classes;

    void populateClasses(double lower, double upper, unsigned classes);

public:
    Histogramme(double lower, double upper, unsigned classes);

    std::set<Classe, Compare>& getClasses();

    void ajouter(const Valeur& value);

    void ajouter(const Echantillon& sample);
};

template <typename Compare>
void Histogramme<Compare>::populateClasses(double lower, double upper, unsigned classes) {
    double currentBound = lower;
    double classSize = (upper - lower) / classes;
    double currentUpperBound;

    for(auto i = 0u; i < classes; ++i) {
        currentUpperBound = currentBound + classSize;
        Classe statClass{currentBound, currentUpperBound};
        _classes.insert(statClass);
        currentBound = currentUpperBound;
    }
}

template <typename Compare>
Histogramme<Compare>::Histogramme(double lower, double upper, unsigned classes) {
    populateClasses(lower, upper, classes);
}

template <typename Compare>
std::set<Classe, Compare>& Histogramme<Compare>::getClasses() {
    return _classes;
}

template <typename Compare>
void Histogramme<Compare>::ajouter(const Valeur& value) {
    auto correctClass = std::find_if(_classes.begin(), _classes.end(), [&value](const Classe& statClass) {
        return value.getNombre() >= statClass.getBorneInf() && value.getNombre() < statClass.getBorneSup();
    });
    Classe copyClass = *correctClass;
    _classes.erase(correctClass);
    copyClass.ajouter();
    _classes.insert(copyClass);
}

template <typename Compare>
void Histogramme<Compare>::ajouter(const Echantillon& sample) {
    for(auto i = 0u; i < sample.getTaille(); ++i) {
        ajouter(sample.getValeur(i));
    }
}

#endif // HISTOGRAMME_HPP
