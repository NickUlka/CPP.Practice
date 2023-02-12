
// Сохранение данных в json-файл

#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;
using namespace std;

void sortArray(int, int*);

int main(int argc, char const* argv[])
{
	json js;
	string fileName = "array.json";
	
	// создание и запись массива в файл json
	js = json::array( { 10, 3, 4, 56, 4, 1, 0, 33, 9, 2});
	ofstream fout(fileName);
	fout << js << endl;
	fout.close();
		

	ifstream fin(fileName);
	fin >> js;
	const int n = 10;
	int mas[n] = { 0 };
	int i = 0;
	for (auto it = js.begin(); it != js.end(); ++it)
	{	
		mas[i]= * it;
		i++;
	}
	fin.close();
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
	string fileName = "arraySorted.json";
	ofstream fout (fileName);
	for (int i = 0; i < N; i++) {
		fout << a[i] << '\t';
	}
	fout.close();
}

