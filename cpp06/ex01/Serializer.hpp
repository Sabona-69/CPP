#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include "Data.hpp"
#include <stdint.h>

class Serializer {
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer &assign);
        Serializer& operator=(const Serializer &assign);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw); 
};

#endif
