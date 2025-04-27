#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>


template <typename T>
class MutantStack {
    private: 
        T arr;
    public:
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack &assign);
        MutantStack& operator=(const MutantStack &assign);
        void push(const T& add);
        class iterator
        {
            private:
            public:
                T* begin();
                T* end();
        };
};

#endif
