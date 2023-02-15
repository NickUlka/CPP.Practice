
// Решение квадратного уравнения c помощью кортежа

#include <iostream>
#include <tuple>
#include<cmath>


using Tuple = std::tuple<double, double, int>;





Tuple Myroot(double a, double b, double c) {
    double d = b * b - 4 * a * c;

    if (d > 0) 
     return   Tuple((-b - sqrt(d)) / 2 * a, (-b + sqrt(d)) / 2 * a, 1);
     
    else if (d == 0) {
        return Tuple(-b / 2 * a, -b / 2 * a, 0);
    }
    else 
        return Tuple(0,0,-1);
    
}

int main()
{
   // double a = 1, b = 2, c = 3; // нет корней
    double a = 2, b = 4, c = 2; // одинаковые корни
    //double a = 1, b = 4, c = 3; // 2 корня
    Tuple result = Myroot(a, b, c);
    switch (std::get<2>(result))
    {
    case 1:
        std::cout << "The roots of the equation are: x1 = " << std::get<0>(result) << ", x2 = " << std::get<1>(result) << std::endl;
        break;
    case 0:
        std::cout << "The roots of the equation are equal: x1 = x2 = " << std::get<0>(result) << std::endl;
        break;
    default:
        std::cout << "There are no roots in the equation";
    }
}



