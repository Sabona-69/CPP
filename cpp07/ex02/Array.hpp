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
        Array(unsigned int n);
        Array();
        ~Array();
        Array(const Array &assign);
        T& operator=(const Array &assign);
        T& operator[](unsigned int n);
        class ThrowInvalidIndex : public std::exception {
            const char *what() const throw();
        };
        unsigned int size();
};

#endif
    