#include <cstdlib>
#include <iostream>
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

    return EXIT_SUCCESS;
}
