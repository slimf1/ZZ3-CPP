#ifndef POLAIRE_HPP
#define POLAIRE_HPP

#include "point.hpp"
#include <cmath>

class Polaire : public Point {
private:
    double _angle;
    double _distance;
public:
    Polaire(double a = 0., double d = 0.)
        : _angle(a), _distance(d) {}
    Polaire(const Cartesien& point);

    //Polaire() 
    //    : Polaire(0., 0.) {}

    double getAngle() const;
    double getDistance() const;
    void setAngle(double angle);
    void setDistance(double distance);
    void afficher(std::ostream& stream) const override;

    void convertir(Cartesien& point) const override;
    void convertir(Polaire& point) const override;
};

#endif
