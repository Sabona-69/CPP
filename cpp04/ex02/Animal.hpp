#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal &assign);
        Animal&   operator=(const Animal &assign);
        virtual void     makeSound() const = 0;;
        std::string     getType() const;
};

#endif