#ifndef COMPARATEUR_HPP
#define COMPARATEUR_HPP

#include "classe.hpp"

template <typename T>
struct ComparateurQuantite {
    bool operator()(const Classe& a, const Classe& b) {
        if (a.getQuantite() == b.getQuantite()) {
            return a < b;
        } else {
            return a.getQuantite() > b.getQuantite();
        }
    }
};

#endif // COMPARATEUR_HPP
