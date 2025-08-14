// Creates safe array (index values are checked before access)
// Uses overloaded [] operator for both put and get

#include <iostream>
#include <process.h> // for exit()
using namespace std;

const int LIMIT = 100; // array size

class safearay
{
private:
    int arr[LIMIT];

public:
    // Overloaded [] operator returning by reference
    int &operator[](int n)
    {
        if (n < 0 || n >= LIMIT)
        {
            cout << "\nIndex out of bounds";
            exit(1);
        }
        return arr[n]; // return reference to the element
    }
};

int main()
{
    safearay sa1;

    // Insert elements
    for (int j = 0; j < LIMIT; j++)
        sa1[j] = j * 10; // left side of equal sign

    // Display elements
    for (int j = 0; j < LIMIT; j++)
    {
        int temp = sa1[j]; // right side of equal sign
        cout << "Element " << j << " is " << temp << endl;
    }

    return 0;
}
