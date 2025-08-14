// 4. Create an employee class, basing it on Exercise 4 of Chapter 4. The member data should
// comprise an int for storing the employee number and a float for storing the employee’s
// compensation. Member functions should allow the user to enter this data and display it.
// Write a main() that allows the user to enter data for three employees and display it.
#include <iostream>
using namespace std;
class Employee
{
private:
    int empNumber;
    float compensation;

public:
    // Function to enter data
    void getData()
    {
        cout << "Enter employee number: ";
        cin >> empNumber;
        cout << "Enter compensation: ";
        cin >> compensation;
    }

    // Function to display data
    void displayData() const
    {
        cout << "Employee Number: " << empNumber
             << ", Compensation: $" << compensation << endl;
    }
};
int main()
{
    Employee emp[3]; // array for 3 employees

    cout << "=== Enter data for 3 employees ===\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "\nEmployee " << i + 1 << ":\n";
        emp[i].getData();
    }

    cout << "\n=== Employee Details ===\n";
    for (int i = 0; i < 3; i++)
    {
        emp[i].displayData();
    }

    return 0;
}