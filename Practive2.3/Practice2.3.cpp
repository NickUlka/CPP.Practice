
// Размен монет
#include <iostream>

int main()
{
    // иницииализируем переменные значениями рублевых монет
    short const r1 = 1, r2 = 2, r5 = 5, r10 = 10;
    int rub;
    std::cout << "Input a sum in rubles for change: ";
    std::cin >> rub;
    std::cout << "Your amount of " << rub << "rub can be exchanged of: " << std::endl;

    int s10 =0, s5, s2 =0, s1;
    if (rub >= r10)
    {
        do {
            rub -= r10;
            ++s10;
        } while (rub>= r10);
        std::cout << s10 << ": 10-rub coins" << std::endl;
    }
    if (rub < r10 && rub>=r5)
    {
        rub -= r5;
        s5 = 1;      
        std::cout << s5 << ": 5-rub coin" << std::endl;
    }
    if (rub < r5 && rub >= r2)
    {
        do {
            rub -= r2;
            ++s2;
        } while (rub >= r2);
        std::cout << s2 << ": 2-rub coins" << std::endl;
    }
    if (rub == 1)
    {
        s1 = 1;
        std::cout << s1 << ": 1-rub coin" << std::endl;
    }
}

