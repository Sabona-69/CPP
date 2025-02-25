#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point {
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const Point &assign);
		Point(const float &x, const float &y);
		Point&	operator=(Point& assign);
		Fixed	getX() const;
		Fixed	getY() const;
		~Point();
};

#endif