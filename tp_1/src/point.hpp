#ifndef POINT_HPP
#define POINT_HPP

#include <ostream>

class Cartesien;
class Polaire;

class Point {
public:
    Point() {};

    virtual void afficher(std::ostream& stream) const = 0;

    virtual void convertir(Cartesien& point) const = 0;
    virtual void convertir(Polaire& point) const = 0;

    friend std::ostream& operator<<(std::ostream& stream, const Point& point);
};

#endif
