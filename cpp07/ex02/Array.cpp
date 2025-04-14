#include "Array.hpp"

template<typename T>
Array<T>::Array() : data(NULL) , d_size(0) {
    std::cout << "Default Array Constructor called !" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n) : data(new T[n]), d_size(n) {
    
}

template<typename T>
Array<T>::~Array(){
    delete[] this->data;
    std::cout << "Default Array Destructor called !" << std::endl;
}

template<typename T>
const char* Array<T>::ThrowInvalidIndex::what() const throw() {return "Invalid Index !";}

// const char* Array::ThrowInvalidIndex::what() 

template<typename T>
Array<T>::Array(const Array &assign) : data(new T[assign.d_size]), d_size(assign.d_size) {
    for (size_t i = 0; i < d_size; i++)
        data[i] = assign->data[i];
    std::cout << "Array Copy Constructor called !" << std::endl;
}

template<typename T>
T& Array<T>::operator=(const Array &assign){
    if (this != &assign){
        delete [] this->data;
        this->data = new T[assign.size];
        this->size = assign.size;
        for (size_t i = 0; i < size; i++)
            data[i] = assign.data[i];
    }
        return *this;
}
        
        
template<typename T>
T& Array<T>::operator[](unsigned int n){
    if (n >= this->d_size)
    throw ThrowInvalidIndex();    
    return data[n];
}

template<typename T>
unsigned int Array<T>::size() {return this->d_size;}
