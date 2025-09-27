// 5. Derive a class called employee2 from the employee class in the EMPLOY program in this
// chapter. This new class should add a type double data item called compensation, and
// also an enum type called period to indicate whether the employee is paid hourly, weekly,
// or monthly. For simplicity you can change the manager, scientist, and laborer classes
// so they are derived from employee2 instead of employee. However, note that in many
// circumstances it might be more in the spirit of OOP to create a separate base class called
// compensation and three new classes manager2, scientist2, and laborer2, and use
// multiple inheritance to derive these three classes from the original manager, scientist,
// and laborer classes and from compensation. This way none of the original classes
// needs to be modified.
# include <iostream>
using namespace std;
class Employee
{
private:
    string name;
    int id;
public:
    // Default constructor
    Employee() : name(""), id(0) {}
    // Parameterized constructor
    Employee(string n, int i) : name(n), id(i) {}
    // Member functions
    void getdata()
    {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter ID: ";
        cin >> id;
    }
    void putdata() const
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }
};
enum Period { HOURLY, WEEKLY, MONTHLY };
class Employee2 : public Employee
{   
private:
    double compensation;
    Period period;
public:
    Employee2() : compensation(0.0), period(HOURLY) {}
    Employee2(string n, int i, double c, Period p) : Employee(n, i), compensation(c), period(p) {}
    void getdata()
    {
        Employee::getdata(); // get name and ID
        cout << "Enter compensation: ";
        cin >> compensation;
        int p;
        cout << "Enter period (0 for HOURLY, 1 for WEEKLY, 2 for MONTHLY): ";
        cin >> p;
        period = static_cast<Period>(p);
    }
    void putdata() const
    {
        Employee::putdata(); // display name and ID
        cout << "Compensation: $" << compensation << endl;
        cout << "Period: ";
        switch (period)
        {
            case HOURLY: cout << "HOURLY" << endl; break;
            case WEEKLY: cout << "WEEKLY" << endl; break;
            case MONTHLY: cout << "MONTHLY" << endl; break;
        }
    }
};
int main()
{
    Employee2 emp;
    emp.getdata();
    emp.putdata();
    return 0;
}