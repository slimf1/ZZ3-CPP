#pragma once

#include <map>
#include <set>
#include <iostream>
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

private:
    std::multimap<Inventaire::Categorie, Item*> _items;

public:
    using list_t = std::set<Item*, Compare>; // std::list = chiant à utiliser

    void ajouter(Item* item, Categorie category = Categorie::NORMAL);
    list_t getItemsParCategorie(Categorie category);
    size_t getTaille() const;
};

template <typename Compare>
void Inventaire<Compare>::ajouter(Item* item, Categorie category) {
    if (typeid(*item) == typeid(Arme)) {
        category = Categorie::ARME;
    }
    _items.insert(std::make_pair(category, item));
}

template <typename Compare>
typename Inventaire<Compare>::list_t Inventaire<Compare>::getItemsParCategorie(Categorie category) {
    std::set<Item*, Compare> items;

    auto ret = _items.equal_range(category);
    for (auto it = ret.first; it != ret.second; ++it) {
        items.insert(it->second);
    }

    return items;
}

template <typename Compare>
size_t Inventaire<Compare>::getTaille() const {
    return _items.size();
}
