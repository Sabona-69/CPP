#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>


class Span {
	private:
		std::vector<int> tab;
		unsigned int max;
		Span();
		public:
		Span(const Span &assign);
		~Span();
		Span(unsigned int n);
		Span& operator=(const Span &assign);
		void	addNumber(int n);
		unsigned int shortestSpan();
		unsigned int longestSpan();
	};
	

#endif
