#include "Span.hpp"

int main()
{
    // for (size_t i = 0; i < 5; i++)
    // {
        //     sp.addNumber(i);
        //     std::cout << sp.getTab()[i] << std::endl;
        // }
        // Span sp1(sp);
        // for (size_t i = 0; i < 5; i++)
        //     {
            //     std::cout << sp1.getTab()[i] << std::endl;
            // }
            // std::vector<int> tab {3, 2 ,1};
            // std::vector<int> sorted = tab;
            
            
    // if (!std::is_sorted(sorted.begin(), sorted.end()))
    // std::stable_sort(sorted.begin(), sorted.end());
    // std::vector<int>::iterator it = tab.begin();

    // for (size_t i = 0; i < sorted.size(); i++)
    // {
    //     std::cout << tab[i] << std::endl;
    // }
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(1000);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}