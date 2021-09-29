#include <cstdlib>
#include <vector>
#include <iostream>
#include "point.hpp"
#include "polaire.hpp"
#include "cartesien.hpp"

int main() {
    std::vector<Point*> points;
    points.push_back(new Cartesien(1, -5));
    points.push_back(new Polaire(45, 2.4));

    for(auto& v : points) {
      std::cout << *v << "\n";
    }

    return EXIT_SUCCESS;
}
