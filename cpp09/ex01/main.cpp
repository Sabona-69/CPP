#include "RPN.hpp"

int main(int argc, char **argv){
	RPN rpn;
	try
	{
		if (argc != 2) throw  std::runtime_error("Invalid number of arguments.");
		rpn.calculateInputs(argv[1]);
		std::cout << rpn.getStack().top() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	
	return 0;
}