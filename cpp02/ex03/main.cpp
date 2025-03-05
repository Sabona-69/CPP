#include <iostream>
#include "Point.hpp" 
#include "Fixed.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    const Point a(0, 0);
    const Point b(20, 0);  
    const Point c(10, 30); 
    const Point p(0, 0); 
    if (bsp(a, b, c, p))
        std::cout << "Inside\n";
    else
        std::cout << "Not Inside\n";
    return 0;
}
