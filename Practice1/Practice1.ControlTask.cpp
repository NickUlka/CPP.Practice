

#include <iostream>
#include <windows.h>
#include <cmath>



int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::cout.precision(4);

    std::cout << "Введите координаты первой вершины пятиугольника x1 и y1:\n";
    double x1, y1;
    std::cin >> x1;
    std::cin >> y1;

    std::cout << "\nВведите координаты второй вершины пятиугольника x2 и y2:\n";
    double x2, y2;
    std::cin >> x2;
    std::cin >> y2;

    std::cout << "\nВведите координаты третьей вершины пятиугольника x3 и y3:\n";
    double x3, y3;
    std::cin >> x3;
    std::cin >> y3;

    std::cout << "\nВведите координаты червертой вершины пятиугольника x4 и y4:\n";
    double x4, y4;
    std::cin >> x4;
    std::cin >> y4;

    std::cout << "\nВведите координаты пятой вершины пятиугольника x5 и y5:\n";
    double x5, y5;
    std::cin >> x5;
    std::cin >> y5;

    double s = x1 * y2 + x2 * y3 + x3 * y4 + x4 * y5 + x5 * y1 - x2 * y1 - x3 * y2 - x4 * y3 - x5 * y4 - x1 * y5;
    std::cout << "\nПлощадь данного пятиугольника равна: " << fabs(s)/2 << std::endl;
}


