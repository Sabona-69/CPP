#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>


template<typename T>
typename T::iterator    easyfind(T& t, int i)
{
    typename T::iterator it = std::find(t.begin(), t.end(), i);
    if (it == t.end()) {
        throw std::runtime_error("Value not founded!");
    }
    return it;
}

#endif