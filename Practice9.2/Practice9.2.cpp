//  Безопасная реализация класса Time


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

        class WrongTime
        {
        public:
            WrongTime(int err) 
            {
                switch (err)
                {
                case 1:
                    message = "Hour time should be less than 24";
                    break;
                case 2:
                    message = "The time can't be negative";
                    break;
                case 3:
                    message = "It is already another day";
                }
              
            }
            void printMessage() const
            {
                cout << message << endl;
            }
        private:
            string message;
        };
        Time() :hours(0), minutes(0), seconds(0)
        {}
        Time(int h, int m, int s) : hours(h), minutes(m), seconds(s)
        {
           
            if (h >24)
                throw WrongTime(1);
            if (h < 0 || m < 0 || s < 0)
                throw WrongTime(2);
            CheckTime(h, m, s);
        
        }

        friend void showTime(Time&);

        Time plusTime(const Time& t) const {
            Time time;
            time.hours = hours + t.hours;
            time.minutes = minutes + t.minutes;
            time.seconds = seconds + t.seconds;
            time.CheckTime(time.hours, time.minutes, time.seconds);
            if (time.hours > 24)
                throw WrongTime(3);
            return time;
        }
    };

    void showTime(Time & time)
    {
        cout << time.hours << ":" << time.minutes << ":" << time.seconds << endl;
    }


    int main()
    {
        int h, m, s;
        cout << "Input time in hours, minutes and seconds:\n";
            cin >> h >> m >> s;
            
            try {
                Time time1(h, m, s);
                cout << "Input another time in hours, minutes and seconds:\n";
                cin >> h >> m >> s;
                Time time2(h, m, s);
                Time time3 = time1.plusTime(time2);
                showTime(time3);
            }
        

            catch (Time::WrongTime& err)
            {
                err.printMessage();     
            }
    }

       
    


