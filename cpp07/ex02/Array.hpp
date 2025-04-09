#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

class Array {
    private:
        
    public:
        Array();
        ~Array();
        Array(const Array &assign);
        Array& operator=(const Array &assign);
};

#endif
