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

    std::generate_n(std::back_inserter<Echantillon>(sample), 25, [&normDist, &rng]() {
        return normDist(rng);
    });

    defaultHist.ajouter(sample);
    quantityHist.ajouter(sample);
    
    std::cout << defaultHist << "\n";
    std::cout << quantityHist << "\n";

    return EXIT_SUCCESS;
}
