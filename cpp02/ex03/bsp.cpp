#include "Point.hpp" 

Fixed	area( Point const a, Point const b, Point const c )
{
	// three points (X1, Y1), (X2, Y2), (X3, Y3)
	// Area= 1/2 * |(x1(y2 - y3) + x2(y3 - y1) + x3(y1 -y2))|
	Fixed res =	(a.getX() * (b.getY() - c.getY())) +
				(b.getX() * (c.getY() - a.getY())) +
				(c.getX() * (a.getY() - b.getY()));
	if (res < 0)
		res = res * -1;
	return Fixed(0.5f) * res;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed abc = area(a, b, c);
	Fixed abp = area(a, b, point);
	Fixed apc = area(a, point, c);
	Fixed pbc = area(point, b, c);
	return (abp + apc + pbc == abc && abp > 0 && apc > 0 && pbc > 0);
}