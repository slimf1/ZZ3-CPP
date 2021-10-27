#ifndef CONSOMMATEUR_HPP
#define CONSOMMATEUR_HPP

#include <memory>
#include "ressource.hpp"

class Consommateur {
private:
    int _quantity;
    std::shared_ptr<Ressource> _ressource;

public:
    Consommateur(int quantity, std::shared_ptr<Ressource> ressource);

    void puiser();
};

#endif // CONSOMMATEUR_HPP
