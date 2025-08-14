#include <iostream>
using namespace std;

// Class representing a distance in meters
class Distance {
private:
    int meters; // Distance value in meters

public:
    // Constructor with default value
    Distance(int m = 0) {
        meters = m;
    }

    // Function to display the distance
    void showDistance() {
        cout << meters << " meters" << endl;
    }

    // Overloading the + operator
    Distance operator + (const Distance& d) {
        // Create a new Distance object with sum of meters
        Distance temp;
        temp.meters = meters + d.meters;
        return temp;
    }
};

int main() {
    Distance d1(5), d2(10), d3;

    // Using overloaded + operator to add two objects
    d3 = d1 + d2;

    cout << "Distance d1: ";
    d1.showDistance();

    cout << "Distance d2: ";
    d2.showDistance();

    cout << "Sum of d1 and d2 (d3): ";
    d3.showDistance();

    return 0;
}
