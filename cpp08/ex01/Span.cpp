#include "Span.hpp"

Span::Span(){
}

Span::~Span(){
}

Span::Span(const Span &assign) :  max(assign.max) {
    tab = assign.tab;
    // for (unsigned long i = 0; i < assign.tab.size(); i++)
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

int    Span::shortestSpan(){
    if (tab.size() < 2)  
        throw std::runtime_error("Not enough elements");  
    std::vector<int> sorted = tab;  
    std::sort(sorted.begin(), sorted.end());  
    int minDiff = sorted[1] - sorted[0];  
    for (size_t i = 2; i < sorted.size(); i++) {  
        int diff = sorted[i] - sorted[i - 1];  
        if (diff < minDiff)  
            minDiff = diff;  
    }  
    return minDiff;
}

int    Span::longestSpan(){
    if (tab.size() < 2)  
        throw std::runtime_error("Not enough elements");
    std::vector<int> sorted = tab;  
    std::sort(sorted.begin(), sorted.end());  
    int maxDiff = sorted[sorted.size() - 1] - sorted[0];  
    return maxDiff;
}
