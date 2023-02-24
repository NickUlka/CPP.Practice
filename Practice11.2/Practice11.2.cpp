// Реализация сортировки точек в векторе

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // для алгоритма сортировки
#include <cmath>

class Point {
private:
	double x;
	double y;
	double distanceToCentre() const {
		return sqrt(x * x + y * y);
	}

public:
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}

	

	friend std::ostream& operator<< (std::ostream&, const Point&);
	friend bool operator<(const Point&, const Point&);
};

bool operator<(const Point& p1, const Point& p2) {
	if (p1.distanceToCentre() < p2.distanceToCentre())
		return true;
	else
		return false;
}

 std::ostream& operator<< (std::ostream& out, const Point& p) {
	 out << "Point(" << p.x << ", " << p.y << ")";
	 return out;
}


int main()
{
	std::vector<Point> v;
	v.push_back(Point(1, 2));
	v.push_back(Point(10, 12));
	v.push_back(Point(21, 7));
	v.push_back(Point(4, 8));
	std::sort(v.begin(), v.end()); // перегрузка оператора < для
	// класса Point
	for (auto& point : v)
		std::cout << point << '\n'; // перегрузка оператора << для  класса Point
	return 0;
}

