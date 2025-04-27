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
        Span(const Span &assign);
    public:
        ~Span();
        Span(unsigned int n);
        Span& operator=(const Span &assign);
        void    addNumber(unsigned int n);
        void shortestSpan();
        void longestSpan();
    };
    
#endif
