
//  Рекурсивная функция суммы ряда

#include <iostream>

int recurse(int n) {
    if (n == 1)
        return 5 * n;
    else
        return (5 * n + recurse(n - 1));
}

int main()
{
    std::cout << "Input quantity of repetition - ";
    int repeat;
    std::cin >> repeat;
    std::cout << "The sum of recurse function is " << recurse(repeat) << std::endl;
}

