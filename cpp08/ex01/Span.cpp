#include "Span.hpp"

Span::Span(){
}

Span::~Span(){
}

Span::Span(const Span &assign) :  max(assign.max) {
	vecNum = assign.vecNum;
	// for (unsigned long i = 0; i < assign.vecNum.size(); i++)
	//	 vecNum.push_back(assign.vecNum[i]);
}

Span& Span::operator=(const Span &assign){
	if (this != &assign){
		vecNum = assign.vecNum;
		max = assign.max;
	}
	return *this;
}

Span::Span(unsigned int n) : max(n) {

}


const std::vector<int>&	Span::getVecNum() const { return this->vecNum; };
unsigned int	Span::getMax() const { return this->max; };

void 	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	
	if (n > max)
		throw std::runtime_error("There is no space left !");



}

void	Span::addNumber(int n){
	if (this->vecNum.size() >= max)
		throw std::runtime_error("There is no space left !");
	if (std::find(vecNum.begin(), vecNum.end(), n) != vecNum.end())
		throw std::runtime_error("The number you tried to add already exist !");
	vecNum.push_back(n);
}

unsigned int	Span::shortestSpan(){
	if (vecNum.size() < 2)  
		throw std::runtime_error("Not enough elements");  
	std::vector<int> sorted = vecNum;  
	std::sort(sorted.begin(), sorted.end());  
	unsigned int minDiff = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); i++) {  
		unsigned int diff = sorted[i] - sorted[i - 1];  
		if (diff < minDiff)  
			minDiff = diff;  
	}  
	return minDiff;
}

unsigned int	Span::longestSpan(){
	if (vecNum.size() < 2)  
		throw std::runtime_error("Not enough elements");
	return (unsigned int)(*std::max_element(vecNum.begin(), vecNum.end()) - *std::min_element(vecNum.begin(), vecNum.end()));
}
