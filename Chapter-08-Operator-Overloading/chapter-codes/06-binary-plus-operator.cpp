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

    // Constructor with parameters
    Distance(int ft, float in) : feet(ft), inches(in) {}

    // Get distance from user
    void getdist()
    {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    // Display distance
    void showdist() const
    {
        cout << feet << "\'-" << inches << "\"";
    }

    // Overload binary '+' operator
    Distance operator+(Distance d2) const
    {
        int f = feet + d2.feet;       // add feet
        float i = inches + d2.inches; // add inches

        if (i >= 12.0)
        { // adjust if inches >= 12
            i -= 12.0;
            f++;
        }

        return Distance(f, i); // return a temporary Distance object
    }
};

int main()
{
    Distance dist1, dist3, dist4;

    dist1.getdist();          // user input
    Distance dist2(11, 6.25); // initialized directly

    dist3 = dist1 + dist2;         // using overloaded '+'
    dist4 = dist1 + dist2 + dist3; // chained addition

    cout << "\ndist1 = ";
    dist1.showdist();
    cout << "\ndist2 = ";
    dist2.showdist();
    cout << "\ndist3 = ";
    dist3.showdist();
    cout << "\ndist4 = ";
    dist4.showdist();
    cout << endl;

    return 0;
}
