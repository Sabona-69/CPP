#include "RPN.hpp"

RPN::RPN(){ }

RPN::~RPN(){ }

RPN::RPN(const RPN &assign){ this->_stack = assign._stack; }

RPN& RPN::operator=(const RPN &assign){
    if (this != &assign) _stack = assign._stack;
    return *this;
}

std::stack<int> RPN::getStack() const { return _stack; }

void RPN::calculateInputs(std::string input){
	long	res = 0;
	for (size_t i = 0; i < input.size(); i++){
		if (isdigit(input[i])) {
			_stack.push(input[i] - '0');
			i++;
		}
		else if (input[i] == SUM || input[i] == SUB || input[i] == MULT || input[i] == DIV)
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Not enough numbers in the stack.");
			long b = _stack.top();
			_stack.pop();
			long a = _stack.top();
			_stack.pop();
			switch (input[i]) {
				case SUM:
					res = a + b;
					break;
				case SUB:
					res = a - b;
					break;
				case MULT:
					res = a * b;
					break;
				case DIV:
					if (b == 0) throw std::runtime_error("Division by zero.");
					res = a / b;
					break;
				default:
					throw std::runtime_error("Invalid operator.");
			}
			if (res < INT_MIN || res > INT_MAX)
				throw std::runtime_error("Out of int range.");
			_stack.push(res);
			i++;
		}
		if (input[i] != ' ' && input[i] != '\0')
			throw std::runtime_error("Invalid character in the input.");
	}
	if (_stack.size() != 1)
		throw std::runtime_error("The user input not valid.");
}
