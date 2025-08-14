// Overloading the '<' operator to compare two distances

#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;     // feet part of distance
    float inches; // inches part of distance

public:
    // Default constructor
    Distance() : feet(0), inches(0.0) {}

    // Parameterized constructor
    Distance(int ft, float in) : feet(ft), inches(in) {}

    // Function to take input from user
    void getdist()
    {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    // Function to display distance
    void showdist() const
    {
        cout << feet << "\'-" << inches << '\"';
    }

    // Overloaded '<' operator to compare distances
    bool operator<(Distance d2) const
    {
        // Convert both distances to total feet
        float bf1 = feet + inches / 12.0;
        float bf2 = d2.feet + d2.inches / 12.0;

        // Return comparison result
        return (bf1 < bf2);
    }
};

int main()
{
    Distance dist1;  // First distance
    dist1.getdist(); // Input from user

    Distance dist2(6, 2.5); // Second distance (initialized)

    // Display both distances
    cout << "\ndist1 = ";
    dist1.showdist();
    cout << "\ndist2 = ";
    dist2.showdist();

    // Compare using overloaded '<' operator
    if (dist1 < dist2)
        cout << "\n\nResult: dist1 is less than dist2";
    else
        cout << "\n\nResult: dist1 is greater than (or equal to) dist2";

    cout << endl;
    return 0;
}