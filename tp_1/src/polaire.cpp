#include <iostream>
#include "polaire.hpp"
#include "cartesien.hpp"

Polaire::Polaire(const Cartesien& point) {
    point.convertir(*this);
}

double Polaire::getAngle() const {
    return _angle;
}

double Polaire::getDistance() const {
    return _distance;
}

void Polaire::setAngle(double angle) {
    _angle = angle;
}

void Polaire::setDistance(double distance) {
    _distance = distance;
}

void Polaire::afficher(std::ostream& stream) const {
    stream << "(a=" << _angle << ";d=" << _distance << ")";
}

void Polaire::convertir(Cartesien& point) const {
    point.setX(_distance * cos(_angle * M_PI / 180.0));
    point.setY(_distance * sin(_angle * M_PI / 180.0));
} 

void Polaire::convertir(Polaire& point) const {
    point.setAngle(_angle);
    point.setDistance(_distance);
}
