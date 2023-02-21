#pragma once
#include "dot.h"
// отношение между треугольником (целое) и точкой (часть)– как композиция(целое отвечает за жизненный цикл части)
class Triangle
{
public:
	Triangle(Dot&, Dot&, Dot&);
	~Triangle();
	friend void showDistance(Triangle&);
	double square();
	double perimeter();

private:
	Dot* a;
	Dot* b;
	Dot* c;
	double ab, bc, ca;
};

