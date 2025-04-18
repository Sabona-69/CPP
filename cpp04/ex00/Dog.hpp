#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class   Dog : public Animal {
    public:
        Dog ();
        ~Dog();
        Dog(const Dog &assign);
        Dog&   operator=(const Dog &assign);
        void   makeSound() const;

};

#endif