#include "cartesien.hpp"
#include "polaire.hpp"


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

std::ostream& operator<<(std::ostream& stream, const Point& point) {
    point.afficher(stream);
    return stream;
}

void Cartesien::convertir(Polaire& point) const {
    point.setAngle(atan2(_y, _x) * 180.0 / M_PI);
    point.setDistance(sqrt(_x*_x + _y*_y));
} 

void Cartesien::convertir(Cartesien& point) const {
    
} 