
// Применение итерации реализации функции

#include <iostream>
#include <cmath>
using namespace std;

double cubeRoot (double n) {
    double root = n / 3.0;
    for (int i=0; i<20; i++)
        root= (2*root + n / (root * root)) / 3.0;
    return root;
}

int main()
{
    cout << "Input a number for cube root: ";
    double num;
    cin >> num;
    double cube = cubeRoot(num);
    cout.precision(4);
    cout << "Cube root from a formula = " << cube<< ", cube root from pow function = " << pow(num, 1.0 / 3)<<endl;
   
    
  

}

