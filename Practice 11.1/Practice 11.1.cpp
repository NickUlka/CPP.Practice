//  Перегрузка операторов в классе Time

#include <iostream>
using namespace std;

class Time {

private:
    int hours;
    int minutes;
    int seconds;

    void CheckTime(int& h, int& m, int& s)
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
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s)
    {
        CheckTime(h, m, s);   
    }
    Time(float time) {
        hours = (int)time;
        float floatMin = 60*(time - hours);
         minutes = (int)floatMin;
        seconds = (int)(60 * (floatMin - minutes));
    }

    //

    long secConvert() const {
        return   seconds + 60 * (minutes + hours * 60);
    }

    friend void showTime(Time&);

    Time operator+ (const Time&) const;
    Time operator- (const Time&) const;
    bool operator>= (const Time&) const;

};

Time Time::operator+ (const Time& t) const
{
    Time time;
    time.hours = hours + t.hours;
    time.minutes = minutes + t.minutes;
    time.seconds = seconds + t.seconds;
    time.CheckTime(time.hours, time.minutes, time.seconds);
    return time;
  
}

Time Time::operator- (const Time& t) const
{
    Time time;  
        long dif = secConvert() - t.secConvert();
        time.hours = dif / 3600;
        time.minutes = dif % 3600 / 60;
        time.seconds = dif % 3600 % 60;
        return time;
}

bool Time::operator>= (const Time& t) const
{
    bool flag = 1;
    if (secConvert() >= t.secConvert())
        flag;
    else
        flag = 0;
    return flag;
}


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
    Time time3;
    time3 = time1 + time2;
    cout << "The sum of these two times is ";
    showTime(time3);
    if (time1 >= time2) {
        time3 = time1 - time2;
        cout << "The substitution of these two times is ";
        showTime(time3);
    }
    else
        cout << "Fist time is less than second one. We can't subtract because of negative result!" << endl;
    cout << "Input time in float format: ";
    float floatTime;
    cin >> floatTime;
    cout << "The sum of "<< floatTime<< " hour and ";
    showTime(time2);
    Time time4(floatTime);
    time3 = time2 + time4;
    showTime(time3);
    time3 = time4 + time2;
    cout << "And sum vice-versa ";
    showTime(time3);
    return 0;
}


