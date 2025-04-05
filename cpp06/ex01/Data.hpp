#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
    public:
        Data();
        ~Data();
        Data(const Data &assign);
        Data& operator=(const Data &assign);
};

#endif
