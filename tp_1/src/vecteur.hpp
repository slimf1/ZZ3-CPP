#ifndef VECTEUR_HPP
#define VECTEUR_HPP

#include <cstring>
#include <stdexcept>

template <typename T>
class Vecteur {
private:
    static constexpr size_t DEFAULT_CAPACITY = 10;

    T* _elements;
    size_t _size;
    size_t _capacity;

public:
    Vecteur();
    Vecteur(const Vecteur<T>&);
    Vecteur& operator=(const Vecteur<T>&);
    ~Vecteur();

    size_t size() const;
    void push_back(T el);
    const T& at(int index) const;
    const T& operator[](int index) const;
    T& at(int index);
    T& operator[](int index);

    class Iterator {
    private:
        T* _current;
    public:
        Iterator()
            : _current(nullptr) {}
        Iterator(T* current)
            : _current(current) {}

        T operator*() {
            return *_current;
        }
        Iterator& operator++() {
            _current++;
            return *this;
        }
        Iterator operator++(int) {
            auto temp = *this;
            ++*_current;
            return temp;
        }
        bool operator==(const Iterator& other) {
            return other._current == _current;
        }
        bool operator!=(const Iterator& other) {
            return other._current != _current;
        }
    };

    using iterator = Iterator;
    using const_iterator = Iterator;

    /**
     * Ou directement utiliser 
     * using iterator = T*; 
     * car les pointeurs redéfinissent 
     * déjà les opérateurs 
     */

    iterator begin() const;
    iterator end() const;
};

template <typename T>
Vecteur<T>::Vecteur() 
    : _elements(new T[DEFAULT_CAPACITY]), 
      _size(0),
      _capacity(DEFAULT_CAPACITY) {

}

template <typename T>
Vecteur<T>::Vecteur(const Vecteur<T>& vector) {
    if (&vector != this) {
        _size = vector._size;
        _capacity = vector._capacity;
        _elements = new T[_capacity];
        std::memcpy(_elements, vector._elements, _size * sizeof(T));
    }
}

template <typename T>
Vecteur<T>& Vecteur<T>::operator=(const Vecteur<T>& vector) {
    return Vecteur<T>(vector);
}

template <typename T>
Vecteur<T>::~Vecteur() {
    delete[] _elements;
} 

template <typename T>
size_t Vecteur<T>::size() const {
    return _size;
}

template <typename T>
void Vecteur<T>::push_back(T element) {
    if (_size == _capacity) {
        T* saved_elements = _elements;
        _capacity *= 2;
        _elements = new T[_capacity];
        std::memcpy(_elements, saved_elements, _size * sizeof(T));
        delete[] saved_elements;
    }
    _elements[_size++] = element;
}

template <typename T>
typename Vecteur<T>::iterator Vecteur<T>::begin() const {
    return Vecteur<T>::iterator(_elements);
}

template <typename T>
typename Vecteur<T>::iterator Vecteur<T>::end() const {
    return Vecteur<T>::iterator(_elements + _size);
}

template <typename T>
const T& Vecteur<T>::at(int index) const {
    if (index >= 0 && static_cast<size_t>(index) <= _size - 1) {
        return _elements[index];
    }
    throw std::out_of_range("index out of bounds");
}

template <typename T>
T& Vecteur<T>::at(int index) {
    if (index >= 0 && static_cast<size_t>(index) <= _size - 1) {
        return _elements[index];
    }
    throw std::out_of_range("index out of bounds");
}

template <typename T>
const T& Vecteur<T>::operator[](int index) const {
    return at(index);
}

template <typename T>
T& Vecteur<T>::operator[](int index) {
    return at(index);
}

#endif 
