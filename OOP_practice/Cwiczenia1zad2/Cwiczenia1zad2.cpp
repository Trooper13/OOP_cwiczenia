// Author: Mateusz Mitura
// Date: 25.10.2017
// WIT

#include "stdafx.h"
#include <iostream>
#include <cmath>

class Point
{
	double x, y;
public:
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(double s)
	{
		x = s;
		y = s;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	double getX() const
	{
		return x;
	}
	double getY() const
	{
		return y;
	}
	Point& setX(double xx)
	{
		this->x = xx;
		return *this;
	}
	Point& setY(double yy)
	{
		this->y = yy;
		return *this;
	}
	Point& transX(double dx)
	{
		this->x += dx;
		return *this;
	}
	Point& transY(double dy)
	{
		this->y += dy;
		return *this;
	}
	Point& transXY(double dx, double dy)
	{
		return (*this).transX(dx).transY(dy);
	}
	static double dist(const Point& p, const Point& q)
	{
		return sqrt((p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y));
	}
};

int main()
{
	Point p;
	Point q(1);
	Point r(1, 2);
	p.transXY(5, 6);
	q.transX(-1).transY(-1).transXY(2, 2);
	r.setX(10).transY(-8);
	std::cout << Point::dist(p, q) << std::endl;
	std::cout << Point::dist(p, r) << std::endl;

	getchar();
	getchar();
	return 0;
}

