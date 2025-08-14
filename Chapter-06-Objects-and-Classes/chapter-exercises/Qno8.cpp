#include <iostream>
using namespace std;

class SerialNumber
{
private:
    static int objectCount;
    int serial;

public:
    // Constructor — assigns a serial number when an object is created
    SerialNumber()
    {
        objectCount++;        // Increment total object count
        serial = objectCount; // Assign current count as this object's serial number
    }

    // Function to display this object's serial number
    void showSerial() const
    {
        cout << "I am object number " << serial << endl;
    }
};

// Initialize static data member (must be done outside the class)
int SerialNumber::objectCount = 0;

int main()
{
    // Create three objects
    SerialNumber obj1;
    SerialNumber obj2;
    SerialNumber obj3;

    // Each object reports its serial number
    obj1.showSerial(); // Output: I am object number 1
    obj2.showSerial(); // Output: I am object number 2
    obj3.showSerial(); // Output: I am object number 3
    return 0;
}