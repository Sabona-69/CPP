#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

#define	RANDOM 1
#define	SEQUENCE 2


class Span {
	private:
		std::vector<int> vecNum;
		unsigned int max;
		Span();
		public:
		Span(const Span &assign);
		~Span();
		Span(unsigned int n);
		Span& operator=(const Span &assign);
		void	generateNum(unsigned int n);
		void	addNumber(int n);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int shortestSpan();
		unsigned int longestSpan();

	public:
		const std::vector<int>&	getVecNum() const;
		unsigned int		getMax() const;


};

#endif
