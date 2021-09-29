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

    for(auto it = nuage.begin(); it != nuage.end(); ++it) {
        (*it)->convertir(current);
        // center.setX(center.getX() + current.getX());
        // center.setY(center.getY() + current.getY());
        center = center + current;
    }

    // center.setX(center.getX() / (double)nuage.size());
    // center.setY(center.getY() / (double)nuage.size());
    center = center / (double)nuage.size();
    return center;
}

Cartesien BarycentreCartesien::operator()(Nuage& nuage) {
    return barycentre(nuage);
}

Polaire BarycentrePolaire::operator()(Nuage& nuage) {
    Polaire point;
    auto cartPoint = barycentre(nuage);
    cartPoint.convertir(point);
    return point;
}
