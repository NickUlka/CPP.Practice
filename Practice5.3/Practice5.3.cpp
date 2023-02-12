
// Реализация алгоритмов поиска методом транспозиции

#include <iostream>
using namespace std;

int searchWithTranspos(int*, int, int);
void printArray(int*, int);

int main()
{
    const int n = 8;
    int a[n] = {2,3,4,5,6,7,9,8};
    printArray(a, n);
    int value;    
    int search;
    for (int i = 0; i < 4; i++) // цикл для проверки транспозиции
    {
        cout << "\nInput a value to seach and transposition in the array: ";
        cin >> value;
        search = searchWithTranspos(a, 8, value); 
        if (search == -1)
            cout << "\nThere is no such a value in the array";
        else
        {
            cout << "\nThe value " << value << " is under the index " << search << endl;
            printArray(a, n);

        }
    } 
}

void printArray(int* k, int n) {
    for (int i = 0; i < n; i++)
    {
        cout << "[" << i + 1 << "] = " << k[i]<<'\t';
    }
}

int searchWithTranspos(int* k, int n, int key)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        if (k[i] == key)
        {
            if (i == 0)
                return i;
            temp = k[i];
            k[i] = k[i - 1];
            k[i - 1] = temp;
            return i;
        }
    }
    return -1;
}
