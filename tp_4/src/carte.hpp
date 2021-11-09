#ifndef CARTE_HPP
#define CARTE_HPP

class UsineCarte;

class Carte {
private:
    static int _instanceCounter;
    unsigned _value;

private:
    Carte() = delete;
    Carte& operator=(const Carte&) = delete;
    Carte(const Carte&) = delete;
    Carte(unsigned value);

    friend UsineCarte;

public:
    virtual ~Carte();
    static int getCompteur();
    unsigned getValeur() const;
};

#endif // CARTE_HPP
