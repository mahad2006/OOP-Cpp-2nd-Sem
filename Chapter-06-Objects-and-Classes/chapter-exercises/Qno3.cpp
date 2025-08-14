// *3. Create a class called time that has separate int member data for hours, minutes, and
// seconds. One constructor should initialize this data to 0, and another should initialize it
// to fixed values. Another member function should display it, in 11:59:59 format. The final
// member function should add two objects of type time passed as arguments.
// A main() program should create two initialized time objects (should they be const?) and
// one that isn’t initialized. Then it should add the two initialized values together, leaving the
// result in the third time variable. Finally it should display the value of this third variable.
// Make appropriate member functions const
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

    time addTime(time t)
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
};
int main()
{
    time t1 = {10, 20, 30};
    time t2 = {10, 50, 55};
    t1.display();
    t2.display();
    time t3;
    t3 = t1.addTime(t2);
    t3.display();
    return 0;
}