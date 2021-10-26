#ifndef CARTE_HPP
#define CARTE_HPP

class UsineCarte;

class Carte {
private:
    unsigned _value;

private:
    Carte() = delete;
    Carte& operator=(const Carte&) = delete;
    Carte(const Carte&) = delete;
    Carte(unsigned value);

    friend UsineCarte;

public:
    unsigned getValeur() const;
};

#endif // CARTE_HPP
