#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point {
	private:
		Fixed x; 
		Fixed y; 
	public:
		Point();
		Point(Point &assign);
		Point(float &x, float &y);
		Point&	operator=(const Point& assign);
		~Point();
}

#endif