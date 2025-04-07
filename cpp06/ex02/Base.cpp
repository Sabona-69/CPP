#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){
    std::cout << "Default Base Destructor called !" << std::endl;
}

Base * Base::generate(void){
    std::srand(time(0));
    int random = std::rand() % 3;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    return new C();
}

void Base::identify(Base* p){
    if (dynamic_cast<A*>(p)) 
        std::cout << "Type is A !\n";
    else if (dynamic_cast<B*>(p)) 
        std::cout << "Type is B !\n";
    else if (dynamic_cast<C*>(p)) 
        std::cout << "Type is C !\n";
}

void Base::identify(Base& p){
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Type is A !\n";
        return;
    } catch (...) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Type is B !\n";
        return;
    } catch (...) {}
    
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Type is C !\n";
        return;
    } catch (...) {}
    
}
