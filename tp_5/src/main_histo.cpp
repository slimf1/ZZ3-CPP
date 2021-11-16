#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <random>
#include "comparateur.hpp"
#include "echantillon.hpp"
#include "histogramme.hpp"

int main() {
    std::mt19937 rng;
    std::normal_distribution<double> normDist(10., 5.);
    Echantillon sample;
    Histogramme<> defaultHist(0., 20., 10);
    Histogramme<ComparateurQuantite<Classe>> quantityHist(0., 20., 10);

    for(auto i = 0u; i < 25u; ++i) {
        sample.ajouter(normDist(rng));
    }

    defaultHist.ajouter(sample);
    quantityHist.ajouter(sample);
    
    std::cout << defaultHist << "\n";
    std::cout << quantityHist << "\n";

    return EXIT_SUCCESS;
}
