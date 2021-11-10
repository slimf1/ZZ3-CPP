#ifndef HISTOGRAMME_HPP
#define HISTOGRAMME_HPP

#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <iostream>
#include <iterator>
#include <utility>
#include "classe.hpp"
#include "echantillon.hpp"

#include <ostream>

template <typename Compare = std::less<Classe>>
class Histogramme {
private:
    std::set<Classe, Compare> _classes;
    std::multimap<Classe, Valeur> _values;

    void populateClasses(double lower, double upper, unsigned classes);

public:
    template <typename CompareOther>
    Histogramme(const Histogramme<CompareOther>& other);
    Histogramme(double lower, double upper, unsigned classes);

    std::set<Classe, Compare> getClasses() const;
    std::multimap<Classe, Valeur> getValeurs() const;
    auto getValeurs(const Classe& statClass) const;
    void ajouter(const Valeur& value);
    void ajouter(const Echantillon& sample);
};

template <typename Compare>
std::ostream& operator<<(std::ostream& stream, const Histogramme<Compare>& histogram) {
    // On pourrait utiliser un for_each 
    // mais quel intérêt quand les for( : ) existent ?
    for(const Classe& statClass : histogram.getClasses()) {
        auto interval = histogram.getValeurs(statClass);
        stream << '[' << statClass.getBorneInf() 
               << ';' << statClass.getBorneSup() 
               << "] = " << statClass.getQuantite() << ' ';

        // BidirectionalIterator
        while (interval.first != interval.second) {
            stream << (interval.first)->second << ' ';
            ++(interval.first);
        }
        stream << '\n';
    }
    return stream;
}

template <typename Compare>
void Histogramme<Compare>::populateClasses(double lower, double upper, unsigned classes) {
    double classSize = (upper - lower) / classes;
    for(auto i = 0u; i < classes; ++i) {
        _classes.insert(Classe(lower + classSize * i, lower + classSize * (i + 1)));
    }
}

template <typename Compare>
template <typename CompareOther> // wtf?
Histogramme<Compare>::Histogramme(const Histogramme<CompareOther>& other) {
    for(const auto& el : other.getClasses()) {
        _classes.insert(el);
    }
}

template <typename Compare>
Histogramme<Compare>::Histogramme(double lower, double upper, unsigned classes) {
    populateClasses(lower, upper, classes);
}

template <typename Compare>
std::set<Classe, Compare> Histogramme<Compare>::getClasses() const {
    return _classes;
}

template <typename Compare>
std::multimap<Classe, Valeur> Histogramme<Compare>::getValeurs() const {
    return _values;
}

template <typename Compare>
auto Histogramme<Compare>::getValeurs(const Classe& statClass) const {
    return _values.equal_range(statClass);
}

template <typename Compare>
void Histogramme<Compare>::ajouter(const Valeur& value) {
    auto correctClass = std::find_if(_classes.begin(), _classes.end(), [&value](const Classe& statClass) {
        return value.getNombre() >= statClass.getBorneInf() && value.getNombre() < statClass.getBorneSup();
    });
    if (correctClass == _classes.end()) return;

    Classe copyClass = *correctClass;
    _classes.erase(correctClass); // erase w/ iterator
    copyClass.ajouter();
    _classes.insert(copyClass);
    _values.insert(std::make_pair(copyClass, value));
}

template <typename Compare>
void Histogramme<Compare>::ajouter(const Echantillon& sample) {
    for(auto i = 0u; i < sample.getTaille(); ++i) {
        ajouter(sample.getValeur(i));
    }
}

#endif // HISTOGRAMME_HPP
