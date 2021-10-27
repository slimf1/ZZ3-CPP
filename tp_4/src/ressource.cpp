#include "ressource.hpp"

Ressource::Ressource(int stock)
    : _stock(stock) {
}

int Ressource::getStock() const {
    return _stock;
}

void Ressource::consommer(int qty) {
    _stock -= qty;
}

std::ostream& operator<<(std::ostream& stream, ressources_t& ressources) {
    for (auto& ressource : ressources) {
        if (ressource.expired()) {
            stream << "- ";
        }
        else {
            std::shared_ptr<Ressource> copy = ressource.lock();
            stream << copy->getStock() << ' ';
        }
    }
    return stream;
}
