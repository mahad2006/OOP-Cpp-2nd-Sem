// Demonstrates a safe array with a single access() function
// returning by reference to allow both reading and writing.

#include <iostream>
#include <process.h> // for exit()
using namespace std;

const int LIMIT = 100; // Maximum size of the safe array

class safearay
{
private:
    int arr[LIMIT]; // Internal array

public:
    // Function to access an element (for both put and get)
    int &access(int n)
    {
        // Check if index is out of bounds
        if (n < 0 || n >= LIMIT)
        {
            cout << "\nIndex out of bounds";
            exit(1); // Terminate program
        }
        return arr[n]; // Return reference to array element
    }
};

int main()
{
    safearay sa1;

    // Insert elements into the safe array
    for (int j = 0; j < LIMIT; j++)
        sa1.access(j) = j * 10; // Writing using reference

    // Display elements from the safe array
    for (int j = 0; j < LIMIT; j++)
    {
        int temp = sa1.access(j); // Reading using reference
        cout << "Element " << j << " is " << temp << endl;
    }

    return 0;
}
