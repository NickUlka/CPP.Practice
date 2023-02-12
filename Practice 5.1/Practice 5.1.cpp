
//Контрольное задание 5.1. Передача массива в функцию 

#include <iostream>
using namespace std;


//Упражнение 1. Обработка данных массива
int sumArray(int, int*);
int sumNegative(int, int*);
int sumPositive(int, int*);
int sumOddIdx(int, int*);
int sumNotOddIdx(int, int*);

//Упражнение 2. Сортировка массива
void sortArray(int, int*);


int main()
{
	const int n = 10;
	int mas[n]={0};
	for (int i = 0; i < n; i++)
	{
		cout << "mas[" << i << "]=";
		cin >> mas[i];
	}
	//Упражнение 1. Обработка данных массива
	int sum = sumArray(n, mas);
	cout << "The sum of the elemenemts in the array is " << sum << endl;
	cout << "The middle value of the elemenemts in the array is " << (double)sum / n << endl;
	cout << "The sum of the negative elemenemts in the array is " << sumNegative(n,mas) << endl;
	cout << "The sum of the positive elemenemts in the array is " << sumPositive(n, mas) << endl;
	cout << "The sum of the elemenets with odd index is " << sumOddIdx(n, mas) << endl;
	cout << "The sum of the elemenets with not odd index is " << sumNotOddIdx(n, mas) << endl;

	//Упражнение 2. Сортировка массива
	sortArray(n, mas);
}



//Упражнение 1. Обработка данных массива
int sumArray(int n, int* mas)
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		s += mas[i];
	}
	return s;
}

int sumNegative(int n, int* mas) {
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		if (mas[i]<0)
		s += mas[i];
	}
	return s;
}

int sumPositive(int n, int* mas) {
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		if (mas[i] > 0)
			s += mas[i];
	}
	return s;
}

int sumOddIdx(int n, int* mas) {
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		if (i%2==0)
			s += mas[i];
	}
	return s;
}

int sumNotOddIdx(int n, int* mas) {
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 1)
			s += mas[i];
	}
	return s;
}

//Упражнение 2. Сортировка массива
void sortArray(int N, int* a) {
	int min = 0; // для записи минимального значения
	int buf = 0; // для обмена значениями

	for (int i = 0; i < N; i++)
	{
		min = i; // номер текущей ячейки, как ячейки с минимальным значением
		// в цикле найдем реальный номер ячейки с минимальным значением
		for (int j = i + 1; j < N; j++)
			min = (a[j] < a[min]) ? j : min;
		// перестановка этого элемента, поменяв его местами с текущим
		if (i != min)
		{
			buf = a[i];
			a[i] = a[min];
			a[min] = buf;
		}
	}
	cout << "Sorted array: \n";
	for (int i = 0; i < N; i++) {
		cout << "mas[" << i << "]=" << a[i] << '\t' << endl;
	}
}
