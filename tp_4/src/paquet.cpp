#include "paquet.hpp"

void remplir(paquet_t& paquet, UsineCarte& usine) {
	Carte* currentCard;

	while ((currentCard = usine.getCarte()) != nullptr) {
		paquet.push_back(std::unique_ptr<Carte>(currentCard));
	}
}

std::ostream& operator<<(std::ostream& stream, const paquet_t& paquet) {
	for (const auto& card : paquet) {
		stream << card->getValeur() << " ";
	}
	return stream;
}
