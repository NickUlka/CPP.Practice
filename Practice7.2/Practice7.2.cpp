
//Решение квадратного уравнения с помощью структуры

#include <iostream>
#include<cmath>


struct SqRoot {
    double x1;
    double x2;
    int flag;
};




SqRoot Myroot(double a, double b, double c) {
    SqRoot sqRoots;
    double d = b * b - 4 * a * c;

    if (d > 0) {
        sqRoots.x1 = (-b - sqrt(d)) / 2 * a;
        sqRoots.x2 = (-b + sqrt(d)) / 2 * a;
        sqRoots.flag = 1;
        return sqRoots;
    }
    else if (d == 0) {
        sqRoots.x1 = sqRoots.x2 = -b / 2 * a;
        sqRoots.flag = 0;
        return sqRoots;
    }
    else {
        sqRoots.flag = -1;
        return sqRoots;
    }
}

int main()
{
    //double a = 1, b = 2, c = 3; // нет корней
   // double a = 2, b = 4, c = 2; // одинаковые корни
    double a = 1, b = 4, c = 3; // 2 корня
    SqRoot result = Myroot(a, b, c);
    switch (result.flag)
    {
    case 1:
        std::cout << "The roots of the equation are: x1 = " << result.x1 << ", x2 = " << result.x2 << std::endl;
        break;
    case 0:
        std::cout << "The roots of the equation are equal: x1 = x2 = " << result.x1 << std::endl;
        break;
    default:
        std::cout << "There are no roots in the equation";
    }
}


