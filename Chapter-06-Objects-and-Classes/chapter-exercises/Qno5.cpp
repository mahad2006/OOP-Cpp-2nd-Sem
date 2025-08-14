// 5. Start with the date structure in Exercise 5 in Chapter 4 and transform it into a date class.Its member data should consist of three ints : month, day, and year.It should also have two member functions : getdate(), which allows the user to enter a date in 12 / 31 / 02 format, and showdate(), which displays the date.

#include <iostream>
using namespace std;

class Date
{
private:
    int month;
    int day;
    int year;

public:
    // Function to get date from user in MM/DD/YY format
    void getdate()
    {
        char slash; // to read and ignore '/' characters
        cout << "Enter date (MM/DD/YY): ";
        cin >> month >> slash >> day >> slash >> year;
    }

    // Function to display date in MM/DD/YY format
    void showdate() const
    {
        cout << month << "/" << day << "/" << year << endl;
    }
};

int main()
{
    Date d;

    d.getdate();
    cout << "The date you entered is: ";
    d.showdate();

    return 0;
}
