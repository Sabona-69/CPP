#include "Span.hpp"

Span::Span(){
}

Span::~Span(){
}

Span::Span(const Span &assign) : tab(assign.tab), max(assign.max) {
    
    // for (int i = 0; i < assign.tab.size(); i++)
    //     tab.push_back(assign.tab[i]);
}

Span& Span::operator=(const Span &assign){
    if (this != &assign){
        tab = assign.tab;
        max = assign.max;
    }
    return *this;
}

Span::Span(unsigned int n) : max(n) {

}
void    Span::addNumber(unsigned int n){
    if (this->tab.size() == max)
        throw std::runtime_error("There is no space left !");
    if (std::find(tab.begin(), tab.end(), n) != tab.end())
        throw std::runtime_error("The number you tried to add already exist !");
    tab.push_back(n);
}
void    shortestSpan(){
    // std::vector<int>::iterator it = 
}

void    longestSpan(){
    
}
