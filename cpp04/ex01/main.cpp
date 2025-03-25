// #include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    for (int k = 0; k < 50; k++){
        j.    
    }

    delete j;
    delete meta;
    delete i;
    std::cout <<  std::string(30, '=') << "\n";
}   