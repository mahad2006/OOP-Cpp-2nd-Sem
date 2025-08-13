#include <iostream>
using namespace std;

// ================= Date Class =================
class Date
{
private:
    int month, day, year;

public:
    void getdate()
    {
        char slash;
        cout << "Enter date (MM/DD/YY): ";
        cin >> month >> slash >> day >> slash >> year;
    }
    void showdate() const
    {
        cout << month << "/" << day << "/" << year;
    }
};

// ================= Employee Type Enum =================
enum etype
{
    laborer,
    secretary,
    manager,
    accountant,
    executive,
    researcher
};

class Employee
{
private:
    int empNumber;
    float compensation;
    Date hireDate;
    etype empType;

public:
    // getter
    void getemploy()
    {
        char typeChar;
        cout << "Enter employee number : ";
        cin >> empNumber;
        cout << "Enter employ salary : ";
        cin >> compensation;

        hireDate.getdate();

        cout << "Enter employee type (first letter only)\n";
        cout << "laborer (l), secretary (s), manager (m), accountant (a), executive (e), researcher (r): ";
        cin >> typeChar;

        switch (typeChar)
        {
        case 'l':
            empType = laborer;
            break;
        case 's':
            empType = secretary;
            break;
        case 'm':
            empType = manager;
            break;
        case 'a':
            empType = accountant;
            break;
        case 'e':
            empType = executive;
            break;
        case 'r':
            empType = researcher;
            break;
        default:
            cout << "Invalid type! Defaulting to laborer.\n";
            empType = laborer;
        }
    }

    // Display employee data
    void putemploy() const
    {
        cout << "Employee Number: " << empNumber
             << ", Compensation: $" << compensation
             << ", Hire Date: ";
        hireDate.showdate();
        cout << ", Type: ";

        switch (empType)
        {
        case laborer:
            cout << "Laborer";
            break;
        case secretary:
            cout << "Secretary";
            break;
        case manager:
            cout << "Manager";
            break;
        case accountant:
            cout << "Accountant";
            break;
        case executive:
            cout << "Executive";
            break;
        case researcher:
            cout << "Researcher";
            break;
        }
        cout << endl;
    }
};
int main()
{
    Employee emp[3];

    cout << "=== Enter details for 3 employees ===\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "\nEmployee " << i + 1 << ":\n";
        emp[i].getemploy();
    }

    cout << "\n=== Employee Records ===\n";
    for (int i = 0; i < 3; i++)
    {
        emp[i].putemploy();
    }

    return 0;
}