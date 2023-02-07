
// Реализация ввода данных


#include <iostream>
using namespace std;

bool Input (int &a, int &b){
    cout << "Input 2  numbers: \n";
    cin >> a >> b;
    if (a!=b) 
        return true;
    else
        return false;   
}


int main()
{
    int a, b;
    if (Input(a, b) == false) // if(!Input(a,b))
    {
        cerr << "error";
        return 1;
    }
    int s = a + b;
    cout << "The sum of this 2 numbers is "<<s<<endl;
        return 0;


}

