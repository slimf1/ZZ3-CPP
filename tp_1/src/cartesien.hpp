#ifndef CARTESIEN_HPP
#define CARTESIEN_HPP

#include "point.hpp"

class Cartesien : public Point {
private:
    double _x;
    double _y;

public:
    Cartesien(double x = 0., double y = 0.)
        : _x(x), _y(y) {}
    Cartesien(const Polaire& point);

    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);
    
    void convertir(Polaire& point) const override;
    void convertir(Cartesien& point) const override;

    void afficher(std::ostream& stream) const override;

};

#endif
