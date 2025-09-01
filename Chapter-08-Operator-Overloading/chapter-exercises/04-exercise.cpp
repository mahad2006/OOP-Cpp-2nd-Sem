// *4. Create a class Int based on Exercise 1 in Chapter 6. Overload four integer arithmetic
// operators (+, -, *, and /) so that they operate on objects of type Int. If the result of any
// such arithmetic operation exceeds the normal range of ints (in a 32-bit environment)—
// from 2,147,483,648 to –2,147,483,647—have the operator print a warning and terminate
// the program. Such a data type might be useful where mistakes caused by arithmetic overflow are unacceptable. Hint: To facilitate checking for overflow, perform the calculations
// using type long double. Write a program to test this class.
#include <iostream>
using namespace std;
class Int
{
private:
    int value;

public:
    // Default constructor (initialize to 0)
    Int() : value(0) {}

    // Constructor with int parameter
    Int(int v) : value(v) {}

    // Display the value
    void display() const
    {
        cout << value;
    }
    Int operator+(const Int &i2) const
    {
        long double result = static_cast<long double>(value) + static_cast<long double>(i2.value);
        if (result > 2147483647 || result < -2147483648)
        {
            cout << "Overflow in addition!" << endl;
            exit(1);
        }
        return Int(static_cast<int>(result));
    }
    Int operator-(const Int &i2) const
    {
        long double result = static_cast<long double>(value) - static_cast<long double>(i2.value);
        if (result > 2147483647 || result < -2147483648)
        {
            cout << "Overflow in subtraction!" << endl;
            exit(1);
        }
        return Int(static_cast<int>(result));
    }
    Int operator*(const Int &i2) const
    {
        long double result = static_cast<long double>(value) * static_cast<long double>(i2.value);
        if (result > 2147483647 || result < -2147483648)
        {
            cout << "Overflow in multiplication!" << endl;
            exit(1);
        }
        return Int(static_cast<int>(result));
    }
    Int operator/(const Int &i2) const
    {
        if (i2.value == 0)
        {
            cout << "Division by zero error!" << endl;
            exit(1);
        }
        long double result = static_cast<long double>(value) / static_cast<long double>(i2.value);
        if (result > 2147483647 || result < -2147483648)
        {
            cout << "Overflow in division!" << endl;
            exit(1);
        }
        return Int(static_cast<int>(result));
    }
};
int main()
{
    Int num1, num2, num3;
    int val1, val2;
    cout << "Enter first integer: ";
    cin >> val1;
    cout << "Enter second integer: ";
    cin >> val2;
    num1 = Int(val1);
    num2 = Int(val2);
    num3 = num1 + num2;
    cout << "Addition result: ";
    num3.display();
    cout << endl;
    num3 = num1 - num2;
    cout << "Subtraction result: ";
    num3.display();
    cout << endl;
    num3 = num1 * num2;
    cout << "Multiplication result: ";
    num3.display();
    cout << endl;
    num3 = num1 / num2;
    cout << "Division result: ";
    num3.display();
    cout << endl;
    return 0;
}