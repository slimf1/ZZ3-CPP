#include "point.hpp"
#include "polaire.hpp"
#include "cartesien.hpp"

std::ostream& operator<<(std::ostream& stream, const Point& point) {
    point.afficher(stream);
    return stream;
}
