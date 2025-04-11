#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T , typename N>

class Array {
    private:
        T arr[N];
    public:
        Array();
        ~Array();
        Array(const Array &assign);
        Array& operator=(const Array &assign);
        Array(N n);
};

#endif
