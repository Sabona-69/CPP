#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(const WrongAnimal &assign);
        WrongAnimal&    operator=(const WrongAnimal &assign);
        void            makeSound() const;
        std::string     getType() const;
};

#endif