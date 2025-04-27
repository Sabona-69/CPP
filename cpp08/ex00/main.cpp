#include "easyfind.hpp"
#include <algorithm>
#include <vector>


int main()
{
    try
    {
        std::vector<int> a;
        std::vector<int> b;
        a.push_back(1);
        a.push_back(2);
        a.push_back(3);
        a.push_back(4);
        int     find = 4;        
        easyfind(a, find);
        std::cout <<  find << " founded in a container!\n";
        // b.push_back(4);
        easyfind(b, find);
        std::cout <<  find << " founded in b container!\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    

    return 0;
}
