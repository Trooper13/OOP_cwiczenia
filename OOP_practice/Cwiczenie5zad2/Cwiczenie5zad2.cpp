//Author: Mateusz Mitura
//14.12.2017

#include "stdafx.h"
#include <iostream>

class Vector
{
	double x, y, z;
public:
	Vector();
	Vector(double x, double y, double z);
	Vector operator-() const;
	Vector operator*(double a) const;
	friend Vector operator+(const Vector&, const Vector&);
	friend Vector operator-(const Vector&, const Vector&);
	friend double operator*(const Vector&, const Vector&);
	friend Vector operator*(double, const Vector&);
	friend std::ostream& operator<<(std::ostream&,
		const Vector&);
};

Vector::Vector()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector::Vector(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector Vector::operator-() const
{
	return Vector(-this->x, -this->y, -this->z);
}


Vector Vector::operator*(double a) const
{
	return Vector(a*this->x, a*this->y, a*this->z);
}

Vector operator+(const Vector& v1, const Vector& v2)
{
	return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector operator-(const Vector& v1, const Vector& v2)
{
	return  Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
	//return v1 + (-v2);
}

double operator*(const Vector& v1, const Vector& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector operator*(double a, const Vector& v)
{
	return Vector(a*v.x, a*v.y, a*v.z);
	// return v * a;
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
	os << "[" << v.x << "," << v.y << "," << v.z << "]";
}

int main()
{
	Vector w1(1, 1, 1), w2(2, 2, 2), w3(1, 2, 1);
	Vector v = -(w1 + w2 - w3);
	Vector w = 2 * v + w1 * 2;
	std::cout << v << " " << w
		<< " " << v * w << std::endl;
	return 0;
}
