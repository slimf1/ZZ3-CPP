#ifndef HISTOGRAMME_HPP
#define HISTOGRAMME_HPP

#include <algorithm>
#include <vector>
#include "classe.hpp"
#include "echantillon.hpp"

class Histogramme {
private:
    std::vector<Classe> _classes;

    void populateClasses(double lower, double upper, unsigned classes);

public:
    Histogramme(double lower, double upper, unsigned classes);

    std::vector<Classe>& getClasses();
    void ajouter(const Valeur& value);
    void ajouter(const Echantillon& sample);
};

Histogramme::Histogramme(double lower, double upper, unsigned classes) {
    populateClasses(lower, upper, classes);
}

void Histogramme::populateClasses(double lower, double upper, unsigned classes) {
    double currentBound = lower;
    double classSize = (upper - lower) / classes;
    double currentUpperBound;

    for(auto i = 0u; i < classes; ++i) {
        currentUpperBound = currentBound + classSize;
        Classe statClass{currentBound, currentUpperBound};
        _classes.push_back(statClass);
        currentBound = currentUpperBound;
    }
}

std::vector<Classe>& Histogramme::getClasses() {
    return _classes;
}

void Histogramme::ajouter(const Valeur& value) {
    auto correctClass = std::find_if(_classes.begin(), _classes.end(), [&](const Classe& statClass) {
        return value.getNombre() >= statClass.getBorneInf() && value.getNombre() < statClass.getBorneSup();
    });
    (*correctClass).ajouter();
}

void Histogramme::ajouter(const Echantillon& sample) {
    for(auto i = 0u; i < sample.getTaille(); ++i) {
        ajouter(sample.getValeur(i));
    }
}

#endif // HISTOGRAMME_HPP