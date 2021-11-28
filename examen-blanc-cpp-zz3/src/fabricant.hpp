#pragma once

#include <string>
#include <set>

class Fabricant {
private:
  std::string _name;
  std::set<std::string> _items;

public:
  Fabricant(const std::string& name)
    : _name(name) {}
  
  std::string getNom() const {
    return _name;
  }

  bool hasItemsEnProduction() const {
    return _items.size() > 0;
  }

  void ajouterProduction(const std::string& itemName) {
    _items.insert(itemName);
  }

  Item* produire(const std::string& itemName) {
    if (_items.find(itemName) != _items.end()) { // Contenu
      auto item = new Item('[' + _name + "] " + itemName);
      item->setFabricant(this);
      return item;
    } else {
      return nullptr;
    }
  }


};
