#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
    private:
        const Fixed& x;
        const Fixed& p;
    public:
        Point();
        Point(float& x, float&y);
        ~Point();
        Point operator=(Point& inst);


};

#endif