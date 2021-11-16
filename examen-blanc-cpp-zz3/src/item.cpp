#include "item.hpp"

Item::Item(const std::string& name, double price)
    : _name(name), _price(price) {

}

bool Item::estVendable() const {
    return _price > 0;
}

std::string Item::getNom() const {
    return _name;
}

double Item::getPrix() const {
    return _price;
}
