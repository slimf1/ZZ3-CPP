#include "nuage.hpp"

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
