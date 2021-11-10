#ifndef VALEUR_HPP
#define VALEUR_HPP

#include <string>

class Valeur {
private:
    double _value;
    std::string _name = "inconnu";

public:
    Valeur(double value = 0.0)
        : _value(value) {}
    Valeur(double value, const std::string& name)
        : _value(value), _name(name) {}

    double getNombre() const;
    double getNote() const; // alias de méthode possible ?
    void setNombre(double value);
    void setNote(double value);
    void setEtudiant(const std::string& name);
    const std::string& getEtudiant() const;
};

#endif // VALEUR_HPP
