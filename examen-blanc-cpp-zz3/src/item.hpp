#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item {
private:
    std::string _name;
    double _price;

public:
    Item(const std::string& name, double price = 0.0);

    virtual std::string getNom() const;
    double getPrix() const;
    bool estVendable() const;
};

#endif // ITEM_HPP
