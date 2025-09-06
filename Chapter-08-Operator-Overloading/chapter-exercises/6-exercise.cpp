// 6. Add to the time class of Exercise 5 the ability to subtract two time values using the
// overloaded (-) operator, and to multiply a time value by a number of type float, using
// the overloaded (*) operator.

#include <iostream>
using namespace std;

class Time
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {}
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    void display() const
    {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    // Overloaded + operator
    Time operator+(Time t)
    {
        Time temp;
        temp.seconds = seconds + t.seconds;
        temp.minutes = minutes + t.minutes;
        temp.hours = hours + t.hours;

        if (temp.seconds >= 60)
        {
            temp.minutes++;
            temp.seconds -= 60;
        }
        if (temp.minutes >= 60)
        {
            temp.hours++;
            temp.minutes -= 60;
        }
        return temp;
    }

    // Overloaded - operator
    Time operator-(Time t)
    {
        Time temp;
        temp.seconds = seconds - t.seconds;
        temp.minutes = minutes - t.minutes;
        temp.hours = hours - t.hours;

        if (temp.seconds < 0)
        {
            temp.seconds += 60;
            temp.minutes--;
        }
        if (temp.minutes < 0)
        {
            temp.minutes += 60;
            temp.hours--;
        }
        return temp;
    }

    // Overloaded * operator (multiply time by float)
    Time operator*(float num)
    {
        // Convert full time into total seconds
        int totalSeconds = hours * 3600 + minutes * 60 + seconds;
        // Scale by float
        totalSeconds = static_cast<int>(totalSeconds * num);

        // Convert back to h:m:s
        Time temp;
        temp.hours = totalSeconds / 3600;
        totalSeconds %= 3600;
        temp.minutes = totalSeconds / 60;
        temp.seconds = totalSeconds % 60;

        return temp;
    }
};

int main()
{
    Time t1(2, 30, 45);
    Time t2(1, 20, 30);

    cout << "Time 1: ";
    t1.display();
    cout << "Time 2: ";
    t2.display();

    Time t3 = t1 + t2;
    cout << "t1 + t2 = ";
    t3.display();
    
    Time t4 = t1 - t2;
    cout << "t1 - t2 = ";
    t4.display();

    Time t5 = t1 * 2.5; // multiply time by 2.5
    cout << "t1 * 2.5 = ";
    t5.display();

    return 0;
}
