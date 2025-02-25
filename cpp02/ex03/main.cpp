#include <iostream>
#include "Point.hpp"  // Include the header for your Point class
#include "Fixed.hpp"  // Include the header for your Fixed class

// Your existing bsp function (from your previous code)
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    // Define the three vertices of the triangle
    const Point a(0, 0);   // Point A at (0, 0)
    const Point b(20, 0);  // Point B at (20, 0)
    const Point c(10, 30); // Point C at (10, 30)
    const Point p(0, 0); // Point P at (10, 15)
    if (bsp(a, b, c, p))
        std::cout << "Inside\n";  // Point is inside the triangle
    else
        std::cout << "Not Inside\n";  // Point is outside the triangle

    return 0;
}
