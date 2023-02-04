#include <iostream>
#include <windows.h>
using namespace std;
// Проверка номера СНИЛС

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // разделение введенного номера ИНН на составляющие, позиции основного номера меняются местами
    long long inn;
    cout << "Input INN: ";
    cin >> inn;
    int num10 = inn % 100;
    long long div = 1000;
    long long div2 = 100;
    int arr[9];
    for (int i = 0; i<9; i++) {
        arr[i] = inn % div%div/div2;
        div *= 10;
        div2 *= 10;
    }
    //1. проверка ввода двух одинаковых цифр в основной части (9 цифр) номера (для проверки 11234567890)
    bool flag = true;
    for (int i = 0; i < 8; i++) {
        if (arr[i] == arr[i + 1])
            flag = false;
      
    }
   
    int sum=0;
    if (flag) {
        for (int i = 0; i < 9; i++)
            //Каждая цифра СНИЛС умножается на номер своей позиции (позиция отсчитывается с конца), полученные произведения \
             суммируются
            sum += arr[i] * (i + 1);

//  2. Если сумма меньше 100, то контрольное число равно самой сумме (для проверки 12121212165)
      /* 3.Если сумма равна 100 или 101, то контрольное число равно 00 (для проверки 32123231400)
          4.  Если сумма больше 101, то вычисляется остаток от деления суммы на 101 
         4.1.   Если остаток меньше 100, то контрольное число равно остаток. (для проверки 12345678964)
         4.2   Если остаток равен 100, то контрольное число равно 00 (для проверки 19191918000)*/

        if (((sum < 100 && num10 == sum) || ((sum == 100 || sum == 101) && num10 == 0)) || ((sum > 101) \
            && ((sum % 101 < 100 && num10 == sum % 101) || (sum % 101 == 100 && num10 == 0))))
           
            cout << "TRUE\t"<< "sum = " << sum << endl;
        
        else
            cout << "FALSE\t" << "sum = " << sum << endl;

    }
    else
        cout << "FALSE!" << sum << endl;
   
}