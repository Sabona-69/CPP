#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <exception>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class A;
class B;
class C;


class Base {
    public:
        virtual ~Base();
        Base * generate(void);
        void identify(Base* p);
        void identify(Base& p);
};

#endif
