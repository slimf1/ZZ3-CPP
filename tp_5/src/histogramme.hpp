#ifndef HISTOGRAMME_HPP
#define HISTOGRAMME_HPP

#include <algorithm>
#include <functional>
#include <set>
#include "classe.hpp"
#include "echantillon.hpp"

template <typename Compare = std::less<Classe> >
class Histogramme {
private:
    std::set<Classe, Compare> _classes;

    void populateClasses(double lower, double upper, unsigned classes) {
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

public:
    Histogramme(double lower, double upper, unsigned classes) {
        populateClasses(lower, upper, classes);
    }

    std::set<Classe, Compare>& getClasses() {
        return _classes;
    }

    void ajouter(const Valeur& value) {
        auto correctClass = std::find_if(_classes.begin(), _classes.end(), [&](const Classe& statClass) {
            return value.getNombre() >= statClass.getBorneInf() && value.getNombre() < statClass.getBorneSup();
        });
        Classe copyClass = *correctClass;
        _classes.erase(correctClass);
        copyClass.ajouter();
        _classes.insert(copyClass);
    }

    void ajouter(const Echantillon& sample) {
        for(auto i = 0u; i < sample.getTaille(); ++i) {
            ajouter(sample.getValeur(i));
        }
    }
};

#endif // HISTOGRAMME_HPP
