#ifndef RESSOURCE_HPP
#define RESSOURCE_HPP

#include <vector>
#include <ostream>
#include <memory>

class Ressource {
private:
    int _stock;

public:
    Ressource(int stock);

    int getStock() const;
    void consommer(int qty);
};

using ressources_t = std::vector<std::weak_ptr<Ressource>>;

std::ostream& operator<<(std::ostream& stream, ressources_t& ressources);

#endif // RESSOURCE_HPP
