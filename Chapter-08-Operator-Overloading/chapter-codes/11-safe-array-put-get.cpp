// 09-safe-array-put-get.cpp
// Safe Array Implementation using Separate putel() and getel() Functions
#include <iostream>
#include <process.h> // for exit()
using namespace std;

const int LIMIT = 100; // Maximum size of the array

//============================================================
// Class: safearay
// Purpose: Implements an integer array with bounds checking

class safearay
{
private:
    int arr[LIMIT]; // Fixed-size integer array

public:
    // Function to set value at a specific index
    void putel(int n, int elvalue)
    {
        if (n < 0 || n >= LIMIT)
        {
            cout << "\nIndex out of bounds";
            exit(1); // Exit program if index is invalid
        }
        arr[n] = elvalue;
    }

    // Function to get value from a specific index
    int getel(int n) const
    {
        if (n < 0 || n >= LIMIT)
        {
            cout << "\nIndex out of bounds";
            exit(1); // Exit program if index is invalid
        }
        return arr[n];
    }
};

int main()
{
    safearay sa1;

    // Insert elements into the safe array
    for (int j = 0; j < LIMIT; j++)
    {
        sa1.putel(j, j * 10); // Each element = index * 10
    }

    // Display elements from the safe array
    for (int j = 0; j < LIMIT; j++)
    {
        int temp = sa1.getel(j);
        cout << "Element " << j << " is " << temp << endl;
    }

    return 0;
}
