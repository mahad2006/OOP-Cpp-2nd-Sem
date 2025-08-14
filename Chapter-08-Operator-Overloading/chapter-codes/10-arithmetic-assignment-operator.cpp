// 08-arithmetic-assignment-operator.cpp
// Demonstrating operator overloading for the '+=' arithmetic assignment operator

#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    // Default constructor
    Distance() : feet(0), inches(0.0) {}

    // Parameterized constructor
    Distance(int ft, float in) : feet(ft), inches(in) {}

    // Function to get distance from user
    void getdist()
    {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    // Function to display distance
    void showdist() const
    {
        cout << feet << "\'-" << inches << '\"';
    }

    // Overloaded += operator (arithmetic assignment)
    void operator+=(Distance d2)
    {
        feet += d2.feet;     // Add feet
        inches += d2.inches; // Add inches

        // Handle conversion if inches >= 12
        if (inches >= 12.0)
        {
            inches -= 12.0;
            feet++;
        }
    }
};

int main()
{
    Distance dist1; // First distance
    dist1.getdist();

    cout << "\ndist1 = ";
    dist1.showdist();

    Distance dist2(11, 6.25); // Second distance (initialized)
    cout << "\ndist2 = ";
    dist2.showdist();

    // Using overloaded += operator
    dist1 += dist2; // dist1 = dist1 + dist2

    cout << "\nAfter addition,";
    cout << "\ndist1 = ";
    dist1.showdist();
    cout << endl;

    return 0;
}
