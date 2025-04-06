#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data {
    int value;
};

class Serializer {
    private:
        int     x;
        Serializer();
        ~Serializer();
        Serializer(const Serializer &assign);
        Serializer& operator=(const Serializer &assign);
    public:
        int     getX() const;
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw); 
};

#endif
