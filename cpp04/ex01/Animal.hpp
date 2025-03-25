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
        virtual void     makeSound() const;
        std::string     getType() const;
        void            set_Brain(std::string& str, int index);
};

#endif