// #include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    int c = 2;

    const Animal  *arr[c];

    for (int i = 0; i < c / 2; i++)
        arr[i] = new Cat();
    for (int i = c / 2; i < c; i++)
        arr[i] = new Dog();
    for (int i = 0 ; i < c; i++)
        delete arr[i];
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    Dog basic;
    {
        Dog tmp = basic;
    }

    Dog dog1;
    Dog dog2(dog1); 
    dog1 = dog2;

    Cat cat1;
    Cat cat2(cat1); 
    cat1 = cat2;
}   