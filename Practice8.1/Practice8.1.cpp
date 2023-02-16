
//Класс Time

#include <iostream>
using namespace std;

class Time {

private:
    int hours;
    int minutes;
    int seconds;

public:
    Time() :hours(0), minutes(0), seconds(0)
    {
    }
    Time (int h, int m, int s): hours(h), minutes(m), seconds(s)
    {
        if (seconds/60>0) {
            minutes+=seconds/60;
            seconds =seconds%60;
        }
        if (minutes / 60 > 0) {
            hours += minutes / 60;
            minutes = minutes % 60;
        }
    }

    void showTime()	const
    {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
    void plusTime(const Time& t1,const Time& t2) {
        this->hours = t1.hours + t2.hours;
        this->minutes = t1.minutes + t2.minutes;
        this->seconds = t1.seconds + t2.seconds;
        if (seconds / 60 > 0) {
            minutes += seconds / 60;
            seconds = seconds % 60;
        }
        if (minutes / 60 > 0) {
            hours += minutes / 60;
            minutes = minutes % 60;
        }
    }
};



int main()
{
    int h, m, s;
    cout << "Input time in hours, minutes and seconds:\n";
    cin >> h >> m >> s;
    Time time1(h, m, s);
    cout << "Input another time in hours, minutes and seconds:\n";
    cin >> h >> m >> s;
    Time time2(h, m, s);
    Time time3;
    time3.plusTime(time1, time2);
    time3.showTime();
}