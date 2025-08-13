// *1. Create a class that imitates part of the functionality of the basic data type int. Call the
// class Int (note different capitalization). The only data in this class is an int variable.
// Include member functions to initialize an Int to 0, to initialize it to an int value, to display it (it looks just like an int), and to add two Int values.
// Write a program that exercises this class by creating one uninitialized and two initialized
// Int values, adding the two initialized values and placing the response in the uninitialized
// value, and then displaying this result.

#include <iostream>
using namespace std;

class Int
{
private:
    int value;

public:
    // Default constructor (initialize to 0)
    Int()
    {
        value = 0;
    }

    // Constructor with int parameter
    Int(int v)
    {
        value = v;
    }

    // Display the value
    void display() const
    {
        cout << value;
    }

    // Add two Int objects and return a new Int
    Int add(const Int &i2) const
    {
        Int temp;
        temp.value = value + i2.value;
        return temp;
    }
};
int main()
{
    Int num1;     // uninitialized (will be 0 by default)
    Int num2(5);  // initialized with 5
    Int num3(10); // initialized with 10

    // Add num2 and num3, store result in num1
    num1 = num2.add(num3);

    // Display the result
    cout << "The sum is: ";
    num1.display();
    cout << endl;
    return 0;
}