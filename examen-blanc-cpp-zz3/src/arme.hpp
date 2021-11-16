#ifndef ARME_HPP
#define ARME_HPP

#include <exception>
#include <memory>
#include "item.hpp"
#include "enchantement.hpp"

class Arme : public Item {
private:    
    unsigned _durability;
    Enchantement* _enchantement; // raw pointers ?

public:

    struct DestroyedItemException : public std::exception {
        const char* what() const noexcept {
            return "Item broke :(";
        }
    };

    Arme(const std::string& name, double price, unsigned durability);
    Arme& operator=(const Arme& weapon);
    ~Arme();

    void utiliser();
    std::string getNom() const override;
    Enchantement* getEnchantement();
    void enchanter(Enchantement* enchantement);
};

#endif // ARME_HPP
