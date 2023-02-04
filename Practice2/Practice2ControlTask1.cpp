

#include <iostream>
#include <windows.h>

//определение суперпростых чисел

//функция, определяющее простое число (true/false)
bool simple(long long n) {
    for (long long i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::cout << "Enter a number: ";
    long long number;
    std::cin >> number;
    long count = 1;
   
  // вычисляем позицию числа среди простых чисел
    if ((simple(number)) && (number!=1))
  {
      std::cout << "This number is simple\n";
      for (long long i = 3; i<=number; i++)
      {
          if (simple(i))
              count++;
      }
 // если число простое, оределяем, является ли эта позиция простым числом, и соответственно само число - суперпростое   
      if ((simple(count))  && (count!=1))
          std::cout << "And SUPER simple\n";
      else
          std::cout << "But NOT super simple\n";
  }
  else
      std::cout << "This number is NOT simple\n";  
}

