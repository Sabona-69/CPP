#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class   WrongCat : public WrongAnimal{
    public:
        WrongCat ();
        ~WrongCat();
        WrongCat(const WrongCat &assign);
        WrongCat&   operator=(const WrongCat &assign);
        void   makeSound() const;
};

#endif