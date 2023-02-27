// Реализация класса Triangle


#include <iostream>
#include "dot.h"
#include "triangle.h"
#include "Triangle2.h"

void showDistance(Triangle& t) {
    std::cout << "The lengths of thee sides of the triangle1 are: " << t.ab<<", "\
        <<t.bc<<", "<<t.ca<<std::endl;
}

void showDistance(Triangle2& t) {
    std::cout << "The lengths of thee sides of the triangle2 are: " << t.ab << ", "\
        << t.bc << ", " << t.ca << std::endl;
}


int main()
{
    Dot a(0, 2), b(3, 0), c(0, 0);
    Triangle t(a, b, c); //треугольник (целое) и точка (часть)– как композиция(целое отвечает за жизненный цикл части)

    Triangle2 t2(&a, &b, &c); //треугольник (целое) и точка (часть)– как агрегация(часть и целое могут существовать по отдельности)
    showDistance(t);
    showDistance(t2);
    std::cout << "The square of the triangle1 is " << t.square()<<std::endl;
    std::cout << "The square of the triangle2 is " << t2.square()<<std::endl;

    return 0;
}

