#include "Point.hpp"

Point:: Point(){
	this->x.setRawBits(0);
	this->y.setRawBits(0);
}

Point:: Point(Point &assign){
	this->x = assign.x;
	this->y = assign.y;
}

Point:: Point(float &x, float &y){
	this->x.setRawBits(x);
	this->y.setRawBits(y);
}
Point&	Point::operator=(const Point& assign){
	this->x = assign.x;
	this->y = assign.y;
}

Point:: ~Point(){
	
}