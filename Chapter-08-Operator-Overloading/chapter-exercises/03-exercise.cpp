// *3. Modify the time class from Exercise 3 in Chapter 6 so that instead of a function
// add_time() it uses the overloaded + operator to add two times. Write a program to test
// this class.
#include <iostream>
using namespace std;
class time
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    time() : hours(0), minutes(0), seconds(0) {}
    time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    void display()
        const
    {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
    // operator overloading function
    //  time operator+(time t)
    time operator+(time t)
    {
        time temp;
        temp.seconds = seconds + t.seconds;
        temp.minutes = minutes + t.minutes;
        temp.hours = hours + t.hours;

        if (temp.seconds > 60)
        {
            temp.minutes++;
            temp.seconds -= 60;
        }
        if (temp.minutes > 60)
        {
            temp.hours++;
            temp.minutes -= 60;
        }
        return temp;
    }
    // - operator overriding function
    time operator-(time t)
    {
        time temp;
        temp.seconds = seconds - t.seconds;
        temp.minutes = minutes - t.minutes;
        temp.hours = hours - t.hours;

        if (temp.seconds < 0)
        {
            temp.minutes--;
            temp.seconds += 60;
        }
        if (temp.minutes < 0)
        {
            temp.hours--;
            temp.minutes += 60;
        }
        return temp;
    }
};
int main()
{
    time t1 = {10, 20, 30};
    time t2 = {10, 50, 55};
    t1.display();
    t2.display();
    time t3;
    t3 = t1 - t2;
    t3.display();
    t3 = t1 + t2;
    t3.display();

    return 0;
}