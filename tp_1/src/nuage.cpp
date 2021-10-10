#include <numeric>
#include "nuage.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"

void Nuage::ajouter(Point& point) {
    _points.push_back(&point);
}

size_t Nuage::size() const {
    return _points.size();
}

Nuage::const_iterator Nuage::begin() {
    return _points.begin();
}

Nuage::const_iterator Nuage::end() {
    return _points.end();
}

Cartesien barycentre(Nuage& nuage) {
    Cartesien center(0., 0.);
    Cartesien current;

    for(auto point : nuage) {
        point->convertir(current);
        center += current;
    }
    center /= static_cast<double>(nuage.size());
    return center;
}

Cartesien BarycentreCartesien::operator()(Nuage& nuage) {
    return barycentre(nuage);
}

Polaire BarycentrePolaire::operator()(Nuage& nuage) {
    return Polaire(barycentre(nuage));
}
