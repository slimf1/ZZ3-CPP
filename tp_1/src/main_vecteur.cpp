#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "vecteur.hpp"

int main() {
    Vecteur<double> vector;
    for(int i = 0; i < 12; ++i) {
        vector.push_back(4.1);
    }

    for(auto el : vector) {
        std::cout << el << " ";
    }

    std::cout << "\n";

    vector[6] = 123;

    for(auto el : vector) {
        std::cout << el << " ";
    }

    std::cout << "\n";

    const Vecteur<double> vector2 = vector;

    for(auto el : vector) {
        std::cout << el << " ";
    }

    std::cout << "\n";

    try {
        std::cout << vector[12];
    } catch(std::exception& exc) {
        std::cout << exc.what() << "\n";
    }

    return EXIT_SUCCESS;
}
