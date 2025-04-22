#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template<typename T>

void easyfind(const T& t, int i){
    T search = find(t, (sizeof(t) / sizeof(int)), i);
    std::cerr << "cannot find element !\n" ;
    
}

#endif