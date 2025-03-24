#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
    private:
        /* data */
    public:
        Animal(/* args */);
        ~Animal();
        Animal(const Animal &assign);
        Animal&   operator=(const Animal &assign);
};

#endif