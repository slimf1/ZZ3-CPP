#pragma once

#include <map>
#include <set>
#include <iostream>
#include <numeric>
#include "item.hpp"

template <typename Compare = TrieurAlphabetique>
class Inventaire {
public:
    enum class Categorie : char {
        ARME = 'A',
        CONSOMMABLE = 'C',
        NORMAL = 'N',
        RARE = 'R'
    };
    using list_t = std::set<Item*, Compare>;

private:
    std::map<Inventaire::Categorie, list_t> _items;

public:
    Inventaire();

    void ajouter(Item* item, Categorie category = Categorie::NORMAL);
    const list_t& getItemsParCategorie(Categorie category);
    size_t getTaille() const;
};

template <typename Compare>
Inventaire<Compare>::Inventaire() {
    _items.insert(std::make_pair(Categorie::ARME, list_t()));
    _items.insert(std::make_pair(Categorie::CONSOMMABLE, list_t()));
    _items.insert(std::make_pair(Categorie::NORMAL, list_t()));
    _items.insert(std::make_pair(Categorie::RARE, list_t()));
}

template <typename Compare>
void Inventaire<Compare>::ajouter(Item* item, Categorie category) {
    if (typeid(*item) == typeid(Arme)) {
        category = Categorie::ARME;
    }
    _items[category].insert(item);
}

template <typename Compare>
const typename Inventaire<Compare>::list_t& Inventaire<Compare>::getItemsParCategorie(Categorie category) {
    return _items[category];
}

template <typename Compare>
size_t Inventaire<Compare>::getTaille() const {
    return std::accumulate(_items.cbegin(), _items.cend(), 0u, [](size_t currentSize, const auto& element) {
        return currentSize + element.second.size();
    });
}
