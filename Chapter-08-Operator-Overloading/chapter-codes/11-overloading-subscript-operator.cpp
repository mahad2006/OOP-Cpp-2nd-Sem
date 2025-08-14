
// Demonstrates overloading the subscript operator [] to create a safe array

#include <iostream>
#include <cstdlib> // for exit()
using namespace std;

class SafeArray
{
private:
    static const int SIZE = 100; // Maximum size of the array
    int arr[SIZE];               // Internal storage

public:
    // Constructor - initialize all elements to 0
    SafeArray()
    {
        for (int i = 0; i < SIZE; i++)
        {
            arr[i] = 0;
        }
    }

    // Overloaded subscript operator - return by reference
    int &operator[](int index)
    {
        if (index < 0 || index >= SIZE)
        {
            cerr << "Error: Index " << index << " is out of bounds!" << endl;
            exit(1); // terminate program
        }
        return arr[index]; // return reference to the element
    }

    // Const version of operator[] for read-only access
    const int &operator[](int index) const
    {
        if (index < 0 || index >= SIZE)
        {
            cerr << "Error: Index " << index << " is out of bounds!" << endl;
            exit(1);
        }
        return arr[index];
    }
};

int main()
{
    SafeArray sa;

    // Store values
    for (int i = 0; i < 10; i++)
    {
        sa[i] = i * 10; // works like normal array
    }
   
    // Display values
    for (int i = 0; i < 10; i++)
    {
        cout << "Element at index " << i << " = " << sa[i] << endl;
    }

    // Uncomment to test out-of-bounds check
    // sa[150] = 999;

    return 0;
}
