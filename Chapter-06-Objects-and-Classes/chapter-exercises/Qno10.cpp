#include <iostream>
using namespace std;

//--------------------------------------
// Angle class to store degrees, minutes, and direction (N, S, E, W)
//--------------------------------------
class angle
{
private:
    int degrees;
    float minutes;
    char direction; // 'N', 'S', 'E', 'W'
public:
    // Default constructor
    angle() : degrees(0), minutes(0.0), direction('N') {}

    // Function to get angle data from user
    void getAngle()
    {
        cout << "Enter degrees: ";
        cin >> degrees;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter direction (N/S/E/W): ";
        cin >> direction;
    }

    // Function to display angle in proper format
    void displayAngle() const
    {
        cout << degrees << "° " << minutes << "' " << direction;
    }
};

//--------------------------------------
// Ship class with static serial number counter
//--------------------------------------
class ship
{
private:
    static int shipCount; // Tracks total ships created (shared by all objects)
    int serialNumber;     // Unique ID for each ship
    angle latitude;       // Ship's latitude position
    angle longitude;      // Ship's longitude position

public:
    // Constructor assigns a unique serial number to each ship
    ship()
    {
        shipCount++;
        serialNumber = shipCount;
    }

    // Get ship's position from user
    void setPosition()
    {
        cout << "\nEnter position for Ship #" << serialNumber << ":\n";
        cout << "Latitude:\n";
        latitude.getAngle();
        cout << "Longitude:\n";
        longitude.getAngle();
    }

    // Display ship's serial number and position
    void displayPosition() const
    {
        cout << "\nShip #" << serialNumber << " Position:";
        cout << "\nLatitude: ";
        latitude.displayAngle();
        cout << "\nLongitude: ";
        longitude.displayAngle();
        cout << endl;
    }
};

// Initialize static member
int ship::shipCount = 0;

//--------------------------------------
// Main program
//--------------------------------------
int main()
{
    // Create three ship objects
    ship s1, s2, s3;

    // Input position for each ship
    s1.setPosition();
    s2.setPosition();
    s3.setPosition();

    // Display position of each ship
    cout << "\n--- Ship Positions ---";
    s1.displayPosition();
    s2.displayPosition();
    s3.displayPosition();

    return 0;
}
