#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>


template <typename T>
class MutantStack : public std::stack<T> {
    // private: 
    //     std::stack<T> arr; 
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack &assign);
        MutantStack& operator=(const MutantStack &assign);
        iterator begin();
        iterator  end();
        // void 
        
    };
template <typename T>
std::stack<T>::MutantStack::MutantStack(){

}
    
MutantStack::~MutantStack(){

}
MutantStack::MutantStack(const MutantStack &assign){

}
MutantStack::MutantStack& operator=(const MutantStack &assign){

}
template <typename T>
iterator MutantStack::begin(){

}
iterator MutantStack::end(){

}

#endif
