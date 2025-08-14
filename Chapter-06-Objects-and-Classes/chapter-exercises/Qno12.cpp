#include <iostream>
using namespace std;

//============================
// Fraction Class Declaration
//============================
class Fraction
{
private:
    int numerator;   // Numerator part of fraction
    int denominator; // Denominator part of fraction

public:
    // Constructor to initialize fraction
    Fraction(int num = 0, int den = 1)
    {
        numerator = num;
        denominator = den;
    }

    // Function to set fraction values
    void setFraction(int num, int den)
    {
        numerator = num;
        denominator = den;
    }

    // Function to display fraction in the form "num/den"
    void display() const
    {
        cout << numerator << "/" << denominator;
    }

    // Function to multiply current fraction with another fraction
    Fraction multiply(const Fraction &f) const
    {
        // Multiplication: (a/b) * (c/d) = (a*c) / (b*d)
        return Fraction(numerator * f.numerator, denominator * f.denominator);
    }
};

//============================
// Main Program
//============================
int main()
{
    int den; // Denominator for all fractions in the table

    // Step 1: Get denominator from the user
    cout << "Enter a denominator for the fractions: ";
    cin >> den;

    // Step 2: Create an array of fractions between 0 and 1
    // Example: if den = 6, fractions = 1/6, 2/6, 3/6, 4/6, 5/6
    Fraction fractions[100]; // Arbitrary large size (safe limit)
    int count = 0;           // Number of fractions stored

    for (int num = 1; num < den; num++)
    {
        fractions[count].setFraction(num, den);
        count++;
    }

    // Step 3: Display top row (fractions only, no multiplication yet)
    cout << "\t"; // Space for the first column
    for (int i = 0; i < count; i++)
    {
        fractions[i].display();
        cout << "\t";
    }
    cout << endl;

    // Step 4: Display a line separator for table readability
    for (int i = 0; i <= count; i++)
    {
        cout << "--------";
    }
    cout << endl;

    // Step 5: Generate multiplication table
    for (int i = 0; i < count; i++)
    {
        // First column: fraction itself
        fractions[i].display();
        cout << "\t";

        // Multiply with each fraction and display result
        for (int j = 0; j < count; j++)
        {
            Fraction result = fractions[i].multiply(fractions[j]);
            result.display();
            cout << "\t";
        }
        cout << endl;
    }

    return 0;
}
