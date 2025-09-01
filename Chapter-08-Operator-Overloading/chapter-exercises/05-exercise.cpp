// 5. Augment the time class referred to in Exercise 3 to include overloaded increment (++)
// and decrement (--) operators that operate in both prefix and postfix notation and return
// values. Add statements to main() to test these operators.
#include <iostream>
using namespace std;

class time
{
private:
    int hours;
    int minutes;
    int seconds;

    // function to fix minutes and seconds into proper range
    void normalize()
    {
        if (seconds >= 60)
        {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (seconds < 0)
        {
            minutes -= (abs(seconds) + 59) / 60;
            seconds = (seconds % 60 + 60) % 60;
        }

        if (minutes >= 60)
        {
            hours += minutes / 60;
            minutes %= 60;
        }
        if (minutes < 0)
        {
            hours -= (abs(minutes) + 59) / 60;
            minutes = (minutes % 60 + 60) % 60;
        }
    }

public:
    time() : hours(0), minutes(0), seconds(0) {}
    time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    void display() const
    {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    // prefix ++
    time operator++()   
    {
        ++seconds;
        normalize();
        return *this;
    }

    // postfix ++
    time operator++(int)
    {
        time temp = *this;
        seconds++;
        normalize();
        return temp;
    }

    // prefix --
    time operator--()
    {
        --seconds;
        normalize();
        return *this;
    }

    // postfix --
    time operator--(int)
    {
        time temp = *this;
        seconds--;
        normalize();
        return temp;
    }
};

int main()
{
    time t1(10, 59, 59);
    cout << "Initial: ";
    t1.display();

    cout << "Prefix ++: ";
    (++t1).display();

    cout << "Postfix ++: ";
    (t1++).display();
    cout << "After postfix ++: ";
    t1.display();

    cout << "Prefix --: ";
    (--t1).display();

    cout << "Postfix --: ";
    (t1--).display();
    cout << "After postfix --: ";
    t1.display();

    return 0;
}
