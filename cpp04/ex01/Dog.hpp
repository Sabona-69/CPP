#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class   Dog : public Animal {
    private:
        Brain *brain;
    public:
        Dog ();
        ~Dog();
        Dog(const Dog &assign);
        Dog&   operator=(const Dog &assign);
        void   makeSound() const;

};

#endif