
//Класс Time

#include <iostream>
using namespace std;

class Time {

private:
    int hours;
    int minutes;
    int seconds;
    void CheckTime(int& h,int& m, int& s)
    {
        {
            if (s / 60 > 0) {
                m += s / 60;
                s = s % 60;
            }
            if (m / 60 > 0) {
                h += m / 60;
                m = m % 60;
            }
        }
    }

public:
    Time() :hours(0), minutes(0), seconds(0)
    {}
    Time (int h, int m, int s): hours(h), minutes(m), seconds(s)
    {
        CheckTime(h, m, s);
    }

    friend void showTime(Time&); 
   
    Time plusTime(const Time& t) const{
        Time time;
        time.hours = hours + t.hours;
        time.minutes = minutes + t.minutes;
        time.seconds = seconds + t.seconds;
        time.CheckTime(time.hours, time.minutes, time.seconds);
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