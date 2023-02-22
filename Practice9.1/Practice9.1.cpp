//  Безопасная реализация класса Triangle


#include <iostream>
#include <cmath>
using namespace std;




double triangleSquare(double a, double b, double c) {
    if (a > b + c || b > a + c || c > b + a)
        throw exception("Incorrect side length - one side should not be longer than the sum of lengths of two other sides");
        double p = (a + b + c) / 2;
        double square = sqrt(p * (p - a) * (p - b) * (p - c));
    return square;
}

int main()
{

        std::cout << "Input a dimension of 3 sides of a triangle: ";
        double side1, side2, side3;
        while (std::cin >> side1 >> side2 >> side3)
        {
        try {
            std::cout << "The square of a triangle is " << triangleSquare(side1, side2, side3) << std::endl;
            break;
        }
        catch (const exception& err) {
            std::cout << err.what()<<"\nInput a correct dimension of 3 sides of a triangle: ";
        }
        }
        return 0;
}
