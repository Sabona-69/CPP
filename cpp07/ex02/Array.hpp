#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>


template<typename T>

class Array {
    private:
    T   *data;
    unsigned int  d_size;
    public:
    Array();
    Array(unsigned int n);
    ~Array();
    Array(const Array &assign);
    Array<T>& operator=(const Array &assign);
    class ThrowInvalidAccess : public std::exception {
        const char *what() const throw() ;
    };
    
    class ThrowInvalidIndex : public std::exception {
        const char *what() const throw() ;
    };
    
    const T& operator[](unsigned int n) const;
    T& operator[](unsigned int n);
    
    unsigned int size() const ;
    T* get_data() const ;
};

template<typename T>
Array<T>::Array() : data(new T[0]) , d_size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : data(new T[n]), d_size(n) {}


template<typename T>
Array<T>::~Array(){ delete[] this->data;}

template<typename T>
Array<T>::Array(const Array &assign) : data(new T[assign.d_size]), d_size(assign.d_size) {
    for (size_t i = 0; i < d_size; i++)
        this->data[i] = assign.data[i];
}


template<typename T>
Array<T>& Array<T>::operator=(const Array &assign){
    if (this != &assign){
        delete [] this->data;
        this->data = new T[assign.d_size];
        this->d_size = assign.d_size;
        for (size_t i = 0; i < d_size; i++)
            data[i] = assign.data[i];
    }
    return *this;
}

template<typename T>
const char* Array<T>::ThrowInvalidAccess::what() const throw() { return "Empty Array !"; }
        
template<typename T>
const char* Array<T>::ThrowInvalidIndex::what() const throw() { return "Invalid Index !"; }

template<typename T>
T& Array<T>::operator[](unsigned int n) {
    if (!this->d_size) throw ThrowInvalidAccess();
    if (n >= this->d_size) throw ThrowInvalidIndex();
    return data[n];
}

template<typename T>
const T& Array<T>::operator[](unsigned int n) const {
    if (!data) throw ThrowInvalidAccess();
    if (n >= this->d_size) throw ThrowInvalidIndex();
    return data[n];
}

template<typename T>
unsigned int Array<T>::size() const {return this->d_size;}

template<typename T>
T* Array<T>::get_data() const {return this->data;}

template<typename T>
std::ostream& operator<<(std::ostream &os, const Array<T>& arr){
    os <<std::string(20, '#') << "\n";
    for (unsigned int i = 0; i < arr.size(); ++i) {
        os << "Element [" << i << "] = " << arr.get_data()[i] << std::endl;
    }
    os <<std::string(20, '#') << "\n";
    return os;
}

#endif
