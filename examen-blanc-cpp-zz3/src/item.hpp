#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Fabricant;

class Item {
private:
    std::string _name;
    double _price;
    Fabricant* _factory = nullptr;

public:
    Item(const std::string& name, double price = 0.0);

    virtual std::string getNom() const;
    double getPrix() const;
    bool estVendable() const;
    void setFabricant(Fabricant* factory);
    Fabricant* getFabricant() const;
    virtual ~Item() = default;
};

struct TrieurAlphabetique {
    bool operator()(Item* a, Item* b) const {
        return (*a).getNom() < (*b).getNom();
    }
};

struct TrieurPrix {
    bool operator()(Item* a, Item* b) const {
        return (*a).getPrix() < (*b).getPrix();
    }
};

#endif // ITEM_HPP
