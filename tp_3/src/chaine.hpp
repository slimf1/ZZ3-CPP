#ifndef CHAINE_HPP
#define CHAINE_HPP

// #include <stdexcept>
#include <exception>
#include <string_view>
#include <string>
#include <sstream>
#include <array>

class ExceptionChaine : public std::exception {
private:
    std::string _message;

public:
    ExceptionChaine() {}
    ExceptionChaine(std::string_view message) 
        : _message(message) {}

    const char* what() const throw () override {
        return _message.c_str();
    }
};

template <typename T>
std::string chaine(T element) {
    throw ExceptionChaine(
        "Conversion en chaine impossible pour '" 
        + demangle(typeid(T).name()) 
        + "'"
    );
}

template <>
std::string chaine<std::string>(std::string element) {
    return element;
}

template <>
std::string chaine<int>(int element) {
    return std::to_string(element);
}

template <>
std::string chaine<double>(double element) {
    return std::to_string(element);
}

/*
template <typename T, typename ...Types>
std::string chaine(const T& el, const Types& ...others) {
    std::stringstream ss;

    ss << el << " " << chaine(others...);

    return ss.str();
}*/

template <typename ...Types>
std::string chaine(Types&&... args) {
    return ((chaine(args) + " ") + ...);
}

#endif // CHAINE_HPP
