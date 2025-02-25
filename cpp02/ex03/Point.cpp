#include "Point.hpp"

Point:: Point() : x(0), y(0){}

Point:: Point(const Point &assign) : x(assign.getX().toFloat()), y(assign.getY().toFloat()){
}

Point:: Point(const float &x,const float &y) : x(x), y(y){}

Point&	Point::operator=(Point& assign){
	 (void)assign;
    return *this; 
}

Point:: ~Point(){
	
}

Fixed	Point::getX() const{
	return this->x;
}

Fixed	Point::getY() const{
	return this->y;
}