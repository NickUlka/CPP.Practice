
//  Сохранение данных в текстовый файл

#include <iostream>
#include <fstream>

using namespace std;


void sortArray(int, int*);


int main()
{
	string fileName = "array.txt";
	ofstream fout(fileName);

	const int n = 10;
	int mas[n] = { 0 };
	cout << "Input array for sorting:\n";
	fout << "Array before sorting:"<<endl;

	for (int i = 0; i < n; i++)
	{
		cout << "mas[" << i << "] = ";
		fout << "mas[" << i << "] = ";
		cin >> mas[i];
		fout << mas[i] << endl;
	}
	fout.close();
	sortArray(n, mas);
}
	

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
	string fileName = "array.txt";
	ofstream fout(fileName,ios::app);
	fout << "Sorted array: \n";
	for (int i = 0; i < N; i++) {
		fout << "mas[" << i << "]=" << a[i] << '\t' << endl;
	}
	fout.close();
}
