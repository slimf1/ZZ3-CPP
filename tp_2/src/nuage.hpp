#ifndef NUAGE_HPP
#define NUAGE_HPP

#include <vector>
#include <iostream>
#include "cartesien.hpp"
#include "polaire.hpp"
#include "point.hpp"

template <typename T>
class Nuage {
private:
    std::vector<T> _points;
public:
    
    using iterator = typename std::vector<T>::iterator;
    using const_iterator = typename std::vector<T>::const_iterator;
    using value_type = T;
    
    Nuage();
    Nuage(const Nuage<T>&);
    ~Nuage();
    Nuage& operator=(const Nuage<T>&);

    iterator begin();
    iterator end();
    const_iterator begin() const; 
    const_iterator end() const;
    size_t size() const;
    void ajouter(T element);
};

/* On utilise une surcharge pour gérer les deux comportements
   particuliers. On pourrait spécialiser les templates. */

Cartesien barycentre_v1(const Nuage<Cartesien>& nuage) {
    Cartesien mean(0, 0);

    if (nuage.size() == 0u){
        return mean;
    }

    for(Cartesien point : nuage) {
        mean += point;
    }

    return mean / static_cast<double>(nuage.size());
}

Polaire barycentre_v1(const Nuage<Polaire>& nuage) {
    double averageDistance = 0.0;
    double averageAngle = 0.0;

    if (nuage.size() == 0u){
        return Polaire(0, 0);
    }

    for(Polaire point : nuage) {
        averageAngle += point.getAngle();
        averageDistance += point.getDistance();
    }

    return Polaire(averageAngle / nuage.size(), 
                   averageDistance / nuage.size());
}

template <typename C>
typename C::value_type barycentre_v2(const C& nuage) {
    Cartesien mean(0, 0);
    Cartesien temp;

    if (nuage.size() == 0u){
        return mean;
    }

    for(typename C::value_type point : nuage) {
        point.convertir(temp);
        mean += temp;
    }

    return mean / static_cast<double>(nuage.size());
}

template <typename T>
Nuage<T>::Nuage() { 

}

template <typename T>
Nuage<T>::Nuage(const Nuage<T>& nuage) {
    if (&nuage != this) {
        _points = nuage._points;
    }
}

template <typename T>
Nuage<T>::~Nuage() {

}

template <typename T>
Nuage<T>& Nuage<T>::operator=(const Nuage<T>& nuage) {
    return Nuage(nuage);
}

template <typename T>
typename Nuage<T>::const_iterator Nuage<T>::begin() const {
    return _points.begin();
}

template <typename T>
typename Nuage<T>::const_iterator Nuage<T>::end() const {
    return _points.end();
}

template <typename T>
typename Nuage<T>::iterator Nuage<T>::begin() {
    return _points.begin();
}

template <typename T>
typename Nuage<T>::iterator Nuage<T>::end() {
    return _points.end();
}

template <typename T>
size_t Nuage<T>::size() const {
    return _points.size();
}

template <typename T>
void Nuage<T>::ajouter(T element) {
    _points.push_back(element);
} 

#endif
