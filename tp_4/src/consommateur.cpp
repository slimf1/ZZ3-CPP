#include "consommateur.hpp"

Consommateur::Consommateur(int quantity, std::shared_ptr<Ressource> ressource) 
    : _quantity(quantity), _ressource(ressource) {
}

void Consommateur::puiser() {
    if (!_ressource) {
        return;
    }
    
    auto currentStock = _ressource->getStock();
    _ressource->consommer(_quantity >= currentStock ? currentStock : _quantity);

    if (_ressource->getStock() <= 0) {
        _ressource = nullptr;
    }
}
