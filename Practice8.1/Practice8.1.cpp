
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
   
    friend void showTime(Time&); 
   
    Time plusTime(const Time& t) const
    {
        Time time;
        time.hours = hours + t.hours;
        time.minutes = minutes + t.minutes;
        time.seconds = seconds + t.seconds;
        if (time.seconds / 60 > 0) {
            time.minutes += time.seconds / 60;
            time.seconds = time.seconds % 60;
        }
        if (time.minutes / 60 > 0) {
            time.hours += time.minutes / 60;
            time.minutes = time.minutes % 60;
        }
        return time;
    }
};

void showTime(Time& time)
{
    cout << time.hours << ":" << time.minutes << ":" << time.seconds << endl;
}

int main()
{
    int h, m, s;
    cout << "Input time in hours, minutes and seconds:\n";
    cin >> h >> m >> s;
    Time time1(h, m, s);
    cout << "Input another time in hours, minutes and seconds:\n";
    cin >> h >> m >> s;
    Time time2(h, m, s);
    Time time3 = time1.plusTime(time2);
    showTime(time3);
}