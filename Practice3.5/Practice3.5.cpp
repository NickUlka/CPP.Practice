
// Применение рекурсии для перевода целого числа в двоичный код

#include <iostream>
using namespace std;

int toBinary (int n)
{
    if (n == 0)
        return 0;
    else
        return (n % 2 + 10 *
            toBinary(n / 2));
}


int main()
{
    cout << "Input a positive decimal number for conversion to binary: ";
    int decimal;
    cin >> decimal;
    cout << decimal<<" is "<< toBinary(decimal)<<" in binary system"<<endl;
   
}

