#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <deque>

// #include <containers>

template<typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {
	private: 
		 std::stack<T> arr; 
typedef	
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack &assign);
		MutantStack& operator=(const MutantStack &assign);
		// iterator begin();
		std::stack<T>::iterator 
		// iterator  end();
		// void 


};
// template <typename T>
// iterator MutantStack::begin(){

// }
// iterator MutantStack::end(){

// }

#endif
