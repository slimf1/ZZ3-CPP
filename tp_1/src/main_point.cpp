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

    Cartesien p1(3.2, 5.5);
    Cartesien p2(1.0, 1.0);

    p1 += p2;
    p2 /= 2.0;

    std::cout << p1 << "\n";
    std::cout << p2 << "\n";

    for(auto point : points) {
      delete point;
    }

    return EXIT_SUCCESS;
}
