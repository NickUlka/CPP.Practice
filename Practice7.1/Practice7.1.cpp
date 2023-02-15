
// Структура Time

#include <iostream>
using namespace std;

struct Time
{
    int hours;
    int minutes;
    int seconds;
    void plusInterval(Time t) {
        Time time;
        time.hours = hours + t.hours;
        time.minutes = minutes + t.minutes;
        time.seconds = seconds + t.seconds;
        if (time.seconds >= 60)
        {
            time.minutes++;
            time.seconds -= 60;
        }
        if (time.minutes >= 60) {
            time.hours++;
            time.minutes -= 60;
        }
        cout << "The sum of two times is " << time.hours << ":" << time.minutes << ":" << time.seconds << endl;
    }
    void minusInterval(Time t, long secTime1) {
        Time time;
        long secTime2 = t.seconds + 60 * (t.minutes + t.hours * 60);
        long dif = secTime1 - secTime2;
        if (dif < 0)
            dif = -dif;
       
        time.hours = dif / 3600;
        time.minutes = dif % 3600 / 60;
        time.seconds= dif % 3600 % 60;
  
        cout << "The interval between two times is " << time.hours << ":" << time.minutes << ":" << time.seconds << endl;
    }
};

Time inputTime() {
    Time time;
    cout << "\nhours: ";
    cin >> time.hours;
    cout << "minuts: ";
    cin >> time.minutes;
    cout << "seconds: ";
    cin >> time.seconds;
    return time;
}

int main()
{
    Time time1, time2;
    cout << "Input time to calculate in seconds";
    time1 = inputTime();
    long secTime = time1.seconds + 60 *(time1.minutes + time1.hours * 60);
    cout << "Your time in seconds is equal to "<<secTime<<endl;
    cout << "Input time to calculate the interval between first and second time";
    time2 = inputTime();
    time1.plusInterval(time2);
    time1.minusInterval(time2, secTime);
}

