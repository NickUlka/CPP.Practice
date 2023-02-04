

#include <iostream>

double sqrtf(double target) {
	double x = 1;
	double oldx;
	do {
		oldx = x;
		x = (x + target / x) / 2;
	} while (oldx != x);
	return oldx;
}

int main()
{
	std::cout << "Input a number: ";
	double a;
	std::cin >> a;
	double sqr = sqrtf(a);
	std::cout << "\n Square root of this number is equal to "<<sqr<<std::endl;
	std::cout << "\n Check the correct answer -  " << sqr*sqr << std::endl;
    
}

