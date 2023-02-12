
// Передача параметров в программу

#include <iostream>
#include <cstring>

using namespace std;


int main(int argc, char* argv[])
{
	if(argc < 4)
	{
		cerr << "Less than 4 parameters"<<endl;
		return 1;
	}
	else if(strncmp(argv[1],"-a",2)!=0 
		&& strncmp(argv[1],"-m",2)!=0)
	{
		cerr << "Not correct flag of operation, input -a or -m"<<endl;
		return 1;
	}

	int num1 = atoi(argv[2]);
	int num2 = atoi(argv[3]);
	int num;
	if(strncmp(argv[1],"-a",2)==0)
	{
		num = num1 + num2;
		cout << "Sum of " << num1 << " and " << num2 << " is " << num << endl;
	}
	else if (strncmp(argv[1], "-m", 2)==0)
	{
		num = num1 * num2;
		cout << "Multiplication of "<<num1<<" and "<<num2<<" is "<< num << endl;
	}
	return 0;

}

