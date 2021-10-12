#include "cartesien.hpp"
#include "polaire.hpp"

Cartesien::Cartesien(const Polaire& point) {
    point.convertir(*this);
}

double Cartesien::getX() const {
    return _x;
}

double Cartesien::getY() const {
    return _y;
}

void Cartesien::setX(double x) {
    _x = x;
} 

void Cartesien::setY(double y) {
    _y = y;
}

void Cartesien::afficher(std::ostream& stream) const {
    stream << "(x=" << _x << ";y=" << _y << ")";
}

void Cartesien::convertir(Polaire& point) const {
    point.setAngle(atan2(_y, _x) * 180.0 / M_PI);
    point.setDistance(sqrt(_x*_x + _y*_y));
} 

void Cartesien::convertir(Cartesien& point) const {
    point.setX(_x);
    point.setY(_y);
}

Cartesien operator+(const Cartesien& a, const Cartesien& b) {
    return Cartesien(a.getX() + b.getX(), a.getY() + b.getY());
}

Cartesien operator/(const Cartesien& a, double scal) {
    return Cartesien(a.getX() / scal, a.getY() / scal);
}

Cartesien& Cartesien::operator+=(const Cartesien& other) {
    *this = *this + other;
    return *this;
}

Cartesien& Cartesien::operator/=(double scal) {
    *this = *this / scal;
    return *this;
}
