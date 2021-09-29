#ifndef NUAGE_HPP
#define NUAGE_HPP

#include <vector>
#include "point.hpp"

class Nuage {
private:
  std::vector<Point*> _points;

public:
    Nuage() = default;

    using const_iterator = std::vector<Point*>::const_iterator;

    void ajouter(Point& point);
    size_t size() const;
    Nuage::const_iterator begin();
    Nuage::const_iterator end();
};

#endif
