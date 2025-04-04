#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class   Cat : public Animal{
    public:
        Cat ();
        ~Cat();
        Cat(const Cat &assign);
        Cat&   operator=(const Cat &assign);
        void   makeSound() const;
};

#endif
