#include <stdexcept>
#include <sstream>
#include <iostream>
#include "arme.hpp"

Arme::Arme(const std::string& name, double price, unsigned durability)
    : Item(name, price), _durability(durability), _enchantement(nullptr) {
}

Arme::~Arme() {
    if (_enchantement != nullptr) {
        delete _enchantement;
    }
}

Arme::Arme(const Arme& weapon)
    : Item(weapon.getNom(), weapon.getPrix()) {
    *this = weapon;
}

Arme::Arme(Arme&& weapon)
    : Item(weapon) {
    if (&weapon != this) {
        _durability = weapon._durability;
        _enchantement = weapon._enchantement;
        weapon._enchantement = nullptr;
    }
}

Arme& Arme::operator=(const Arme& weapon) {
    if (this != &weapon) {
        _enchantement = new Enchantement(*weapon._enchantement);
        _durability = weapon._durability;
    }
    return *this;    
}

void Arme::utiliser() {
    if (_durability <= 0) {
        throw Arme::DestroyedItemException{};
    }
    _durability--;
}

std::string Arme::getNom() const {
    std::stringstream ss;
    ss << Item::getNom() << " [" << _durability << "]";
    return ss.str();
}

Enchantement* Arme::getEnchantement() {
    return _enchantement;
    // return _enchantement.get();
}

void Arme::enchanter(Enchantement* enchantement) {
    _enchantement = enchantement;
    // _enchantement = std::make_shared<Enchantement>(*enchantement);
}

