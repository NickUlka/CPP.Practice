#include "triangle.h"
#include <cmath>
// отношение между треугольником (целое) и точкой (часть)– как композиция(целое отвечает за жизненный цикл части)

Triangle::Triangle(Dot& d1, Dot& d2, Dot& d3) 
{
	a = new Dot(d1);
	b = new Dot(d2);
	c = new Dot(d3);
	ab = a->distanceTo(*b);
	bc = b->distanceTo(*c);
	ca = c->distanceTo(*a);
}
Triangle::~Triangle() {
	delete a;
	delete b;
	delete c;
}

double Triangle:: perimeter() {
	return ab + bc + ca;
}

double Triangle::square() {
	double pol = perimeter() / 2.0;
	return sqrt(pol * (pol - ab) * (pol - bc) * (pol - ca));
}