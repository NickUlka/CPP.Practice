
//Вычисление корней квадратного уравнения

#include <iostream>
#include <cmath>

int Myroot(double, double, double, double&, double&);


int main()
{
    double x1,x2;
    //double a = 1, b = 2, c = 3; // нет корней
    double a = 2, b = 4, c = 2; // одинаковые корни
   // double a = 1, b = 4, c = 3; // 2 корня
    int result = Myroot(a, b, c, x1, x2);
    switch (result)
    {
    case 1:
        std::cout << "The roots of the equation are: x1 = " << x1 << ", x2 = " << x2 << std::endl;
        break;
    case 0:
        std::cout << "The roots of the equation are equal: x1 = x2 = " << x1 << std::endl;
        break;
    default:
        std::cout << "There are no roots in the equation";
    }

}

int Myroot(double a, double b, double c, double& x1, double& x2) {
    double d = b * b - 4 * a * c;
   
    if (d > 0) {
        x1 = (-b - sqrt(d)) / 2 * a;
        x2 = (-b + sqrt(d)) / 2 * a;
        return 1;
    }
    else if (d == 0) {
        x1 = x2 = -b / 2 * a;
        return 0;
    }
    else
        return -1;

}