#ifndef ARME_HPP
#define ARME_HPP

#include <exception>
#include <memory>
#include "item.hpp"
#include "enchantement.hpp"

class Arme : public Item {
private:    
    unsigned _durability;
    Enchantement* _enchantement = nullptr;

public:

    struct DestroyedItemException : public std::exception {
        const char* what() const noexcept {
            return "Item broke :(";
        }
    };

    Arme(const std::string& name, double price = 0, unsigned durability = 0);
    Arme& operator=(const Arme& weapon);
    Arme(const Arme& weapon);
    Arme(Arme&& weapon);
    ~Arme();

    void utiliser();
    std::string getNom() const override;
    Enchantement* getEnchantement();
    void enchanter(Enchantement* enchantement);
};

#endif // ARME_HPP
