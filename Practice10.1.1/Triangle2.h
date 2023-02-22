#pragma once
#include "dot.h"


//отношение между треугольником (целое) и точкой (часть)– как агрегация(часть и целое могут существовать по - отдельности)

class Triangle2
{
public:
	Triangle2(Dot*, Dot*, Dot*);
	friend void showDistance(Triangle2&);
	double square();
	double perimeter();

private:
	Dot* a;
	Dot* b;
	Dot* c;
	double ab, bc, ca;
};