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
        explicit Array() : data(NULL) , d_size(0) {}
        Array(unsigned int n) : data(n ? new T[n] : NULL), d_size(n) {}
        ~Array(){ delete[] this->data;}
        Array(const Array &assign) : data(assign.data ? new T[assign.d_size] : NULL), d_size(assign.d_size) {
            if (this->data)
                for (size_t i = 0; i < d_size; i++)
                    this->data[i] = assign.data[i];
        }

        Array<T>& operator=(const Array &assign){
            if (this != &assign && assign.data){
                delete [] this->data;
                this->data = new T[assign.d_size];
                this->d_size = assign.d_size;
                for (size_t i = 0; i < d_size; i++)
                    data[i] = assign.data[i];
            }
            return *this;
        }
        class ThrowInvalidAccess : public std::exception {
            const char *what() const throw() {return "Empty Array !";};
        };
        class ThrowInvalidIndex : public std::exception {
            const char *what() const throw() {return "Invalid Index !";};
        };
        T& operator[](unsigned int n){
            if (!data) throw ThrowInvalidAccess();
            if (n >= this->d_size) throw ThrowInvalidIndex();
            return data[n];
        }

        unsigned int size() const {return this->d_size;}
        T* get_data() const {return this->data;}
};

template<typename T>
std::ostream& operator<<(std::ostream &os, const Array<T>& arr){
    os <<std::string(20, '#') << "\n";
    for (unsigned int i = 0; i < arr.size(); ++i) {
        os << "Element [" << i << "] = " << arr.get_data()[i] << std::endl;
    }
    os <<std::string(20, '#') << "\n";
    return os;
};

#endif
