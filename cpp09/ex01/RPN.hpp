#ifndef RPN_HPP
#define RPN_HPP

#define SUM		'+'
#define SUB		'-'
#define MULT	'*'
#define DIV		'/'

#include <iostream>
#include <climits>
#include <stack>

class RPN {
	private:
		std::stack<int>	_stack;
    public:
        RPN();
        ~RPN();
        RPN(const RPN &assign);
        RPN& operator=(const RPN &assign);
		std::stack<int> getStack() const;
		void calculateInputs(std::string input);
};

#endif
