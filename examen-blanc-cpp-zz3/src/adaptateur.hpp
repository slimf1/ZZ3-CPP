#pragma once

#include "arme.hpp"
#include <iostream>

template <typename T>
class Adaptateur {
private:
    T& _object;
public:
    Adaptateur(T& object)
        : _object(object) {

    }

    void activer() {
        _object.utiliser();
    };
};
