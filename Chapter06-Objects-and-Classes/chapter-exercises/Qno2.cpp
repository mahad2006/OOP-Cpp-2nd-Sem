// *2. Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a 50 cent
// toll. Mostly they do, but sometimes a car goes by without paying. The tollbooth keeps
// track of the number of cars that have gone by, and of the total amount of money collected
// Model this tollbooth with a class called tollBooth. The two data items are a type
// unsigned int to hold the total number of cars, and a type double to hold the total amount
// of money collected. A constructor initializes both of these to 0. A member function called
// payingCar() increments the car total and adds 0.50 to the cash total. Another function,
// called nopayCar(), increments the car total but adds nothing to the cash total. Finally, a
// member function called display() displays the two totals. Make appropriate member
// functions const.
// Include a program to test this class. This program should allow the user to push one key
// to count a paying car, and another to count a nonpaying car. Pushing the Esc key should
// cause the program to print out the total cars and total cash and then exit.

#include <iostream>
#include <conio.h> // for _getch() on Windows
using namespace std;
class tollBooth
{
private:
    unsigned int noOfCars;
    double totalAmount;

public:
    tollBooth()
    {
        noOfCars = 0;
        totalAmount = 0;
    }
    void payingCar()
    {
        noOfCars++;
        totalAmount += 0.50;
    }
    void nopayCar()
    {
        noOfCars++;
    }
    // Display totals
    void display() const
    {
        cout << "\nTotal cars passed: " << noOfCars << endl;
        cout << "Total cash collected: $" << totalAmount << endl;
    }
};
int main()
{
    tollBooth booth;
    char ch;

    // Show menu
    cout << "Tollbooth system:\n";
    cout << "[p] - Paying car\n";
    cout << "[n] - Non-paying car\n";
    cout << "[Esc] - Exit and show totals\n";

    // Functionality

    while (true)
    {
        ch = _getch(); // read a key without pressing Enter
        if (ch == 'p' || ch == 'P')
        {
            booth.payingCar();
            cout << "Paying car recorded.\n";
        }
        else if (ch == 'n' || ch == 'N')
        {
            booth.nopayCar();
            cout << "Non-paying car recorded.\n";
        }
        else if (ch == 27)
        { // ESC key ASCII code
            cout << "\nExiting...\n";
            booth.display();
            break;
        }
    }

    return 0;
}