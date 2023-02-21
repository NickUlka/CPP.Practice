#pragma once
#include "dot.h"

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