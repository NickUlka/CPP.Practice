
// Работа с различными треугольниками


#include <iostream>
#include <cmath>

double triangleSquare(double a) {
    double square = (sqrt(3) * pow(a, 2)) / 4;
    return square;
}

double triangleSquare(double a, double b, double c) {
    double p = (a + b + c) / 2;
    double square = sqrt(p*(p-a)*(p-b)*(p-c));
    return square;
}

int main()
{
    std::cout << "Choose a trianle, the square of which you want to calculate:\n 1 - a equilateral triangle \
        \n 2 - a versatile triangle\n";
    char choose;
    std::cin >> choose;

    switch (choose)
    {
    case '1':
        std::cout << "Input a dimension of one side: ";
            double side;
        std::cin >> side;
        std::cout << "The square of the equilateral triangle is " << triangleSquare(side) << std::endl;
        break;
    case '2':
        std::cout << "Input a dimension of 3 sides: ";
        double side1, side2, side3;
        std::cin >> side1 >> side2 >> side3;
        std::cout << "The square of the versatile triangle is " << triangleSquare(side1, side2, side3) << std::endl;
        break;
    default:
        std::cout << "There are no such a choice!";
    }
}

