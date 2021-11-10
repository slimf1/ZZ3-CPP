#include "valeur.hpp"

double Valeur::getNombre() const {
    return _value;
}

void Valeur::setNombre(double value) {
    _value = value;
}

const std::string& Valeur::getEtudiant() const {
    return _name;
}

void Valeur::setEtudiant(const std::string& name) {
    _name = name;
}

double Valeur::getNote() const {
    return getNombre();
}

void Valeur::setNote(double value) {
    setNombre(value);
}

std::ostream& operator<<(std::ostream& stream, const Valeur& value) {
  stream << "(" << value.getEtudiant() << ";" << value.getNote() << ")";
  return stream;
}