#include <iostream>
#include <cstdlib> // For exit()
#include <cmath>   // For labs()
using namespace std;

class Fraction
{
private:
    long num; // Numerator
    long den; // Denominator

    // Reduces the fraction to its lowest terms
    void lowterms()
    {
        long tnum = labs(num); // Absolute value of numerator
        long tden = labs(den); // Absolute value of denominator
        long temp, gcd;

        if (tden == 0)
        { // Check for division by zero
            cout << "Illegal fraction: division by 0" << endl;
            exit(1);
        }
        else if (tnum == 0)
        { // If numerator is zero, fraction is 0/1
            num = 0;
            den = 1;
            return;
        }

        // Find the greatest common divisor (GCD) using subtraction method
        while (tnum != 0)
        {
            if (tnum < tden)
            { // Swap to make numerator >= denominator
                temp = tnum;
                tnum = tden;
                tden = temp;
            }
            tnum = tnum - tden; // Subtract smaller from larger
        }
        gcd = tden;

        // Divide numerator and denominator by GCD to simplify fraction
        num = num / gcd;
        den = den / gcd;
    }

public:
    // Default constructor (sets fraction to 0/1)
    Fraction() : num(0), den(1) {}

    // Two-argument constructor
    Fraction(long n, long d) : num(n), den(d)
    {
        lowterms(); // Always store in lowest terms
    }

    // Member function to input fraction
    void getFraction()
    {
        char slash; // To store '/' character
        cout << "Enter fraction (format: a/b): ";
        cin >> num >> slash >> den;
        lowterms(); // Reduce to lowest terms after input
    }

    // Member function to display fraction
    void displayFraction() const
    {
        cout << num << "/" << den;
    }

    // Arithmetic operations — each returns a new Fraction
    Fraction add(const Fraction &f) const
    {
        // Formula: a/b + c/d = (ad + bc) / bd
        long n = num * f.den + den * f.num;
        long d = den * f.den;
        return Fraction(n, d);
    }

    Fraction subtract(const Fraction &f) const
    {
        // Formula: a/b - c/d = (ad - bc) / bd
        long n = num * f.den - den * f.num;
        long d = den * f.den;
        return Fraction(n, d);
    }

    Fraction multiply(const Fraction &f) const
    {
        // Formula: (a/b) * (c/d) = (ac) / (bd)
        long n = num * f.num;
        long d = den * f.den;
        return Fraction(n, d);
    }

    Fraction divide(const Fraction &f) const
    {
        // Formula: (a/b) ÷ (c/d) = (a*d) / (b*c)
        if (f.num == 0)
        {
            cout << "Division by zero fraction!" << endl;
            exit(1);
        }
        long n = num * f.den;
        long d = den * f.num;
        return Fraction(n, d);
    }
};

int main()
{
    Fraction f1, f2, result;
    char operation, choice;

    cout << "Four-Function Fraction Calculator (with lowest terms)" << endl;

    do
    {
        // Step 1: Input two fractions
        f1.getFraction();
        cout << "Enter operation (+, -, *, /): ";
        cin >> operation;
        f2.getFraction();

        // Step 2: Perform operation
        switch (operation)
        {
        case '+':
            result = f1.add(f2);
            break;
        case '-':
            result = f1.subtract(f2);
            break;
        case '*':
            result = f1.multiply(f2);
            break;
        case '/':
            result = f1.divide(f2);
            break;
        default:
            cout << "Invalid operation!" << endl;
            continue; // Skip display
        }

        // Step 3: Display result
        cout << "Result: ";
        result.displayFraction();
        cout << endl;

        // Step 4: Ask if user wants to continue
        cout << "Do another calculation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Calculator exited." << endl;
    return 0;
}
