#ifndef PAQUET_HPP
#define PAQUET_HPP

#include <vector>
#include <memory>
#include <ostream>
#include "carte.hpp"
#include "usine.hpp"

using paquet_t = std::vector<std::unique_ptr<Carte>>;

void remplir(paquet_t& paquet, UsineCarte& usine);

std::ostream& operator<<(std::ostream& stream, const paquet_t& paquet);

#endif // PAQUET_HPP
