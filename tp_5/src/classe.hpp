#ifndef CLASSE_HPP
#define CLASSE_HPP

class Classe {
private:
    double _lowerBound;
    double _upperBound;
    unsigned _quantity = 0u;

public:
    Classe(double lower, double upper)
        : _lowerBound(lower), _upperBound(upper) {}

    double getBorneInf() const;
    void setBorneInf(double lower);
    double getBorneSup() const;
    void setBorneSup(double upper);
    unsigned getQuantite() const;
    void setQuantite(unsigned quantity);
    void ajouter();
};

bool operator<(const Classe& a, const Classe& b);
bool operator>=(const Classe& a, const Classe& b);
bool operator>(const Classe& a, const Classe& b);
bool operator<=(const Classe& a, const Classe& b);

#endif // CLASSE_HPP
