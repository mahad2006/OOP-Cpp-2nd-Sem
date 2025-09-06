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
    long gcd(long a, long b)
    {
        while (b != 0)
        {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void lowterms()
    {
        if (den == 0)
        {
            cout << "Illegal fraction: denominator is 0" << endl;
            exit(1);
        }
        if (num == 0)
        {
            den = 1;
            return;
        }
        long g = gcd(labs(num), labs(den));
        num /= g;
        den /= g;
        if (den < 0)
        { // keep denominator positive
            num = -num;
            den = -den;
        }
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
    // Overloaded + operator
    Fraction operator+(const Fraction &f) const
    {
        // Formula: a/b + c/d = (ad + bc) / bd
        long n = num * f.den + den * f.num;
        long d = den * f.den;
        return Fraction(n, d);
    }
    Fraction operator-(const Fraction &f) const
    {
        // Formula: a/b - c/d = (ad - bc) / bd
        long n = num * f.den - den * f.num;
        long d = den * f.den;
        return Fraction(n, d);
    }

    Fraction operator*(const Fraction &f) const
    {
        // Formula: (a/b) * (c/d) = (ac) / (bd)
        long n = num * f.num;
        long d = den * f.den;
        return Fraction(n, d);
    }

    Fraction operator/(const Fraction &f) const
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
    // overloading == operator
    bool operator==(const Fraction &f) const
    {
        return (num == f.num && den == f.den);
    }
    // overloading != operator
    bool operator!=(const Fraction &f) const
    {
        return !(num == f.num && den == f.den);
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
        if (f1 == Fraction(0, 1) && f2 == Fraction(0, 1))
        {
            cout << "Exit condition met (0/1 and 0/1 entered)." << endl;
            break;
        }

        // Step 2: Perform operation
        switch (operation)
        {
        case '+':
            result = f1 + f2;
            break;
        case '-':
            result = f1 - f2;
            break;
        case '*':
            result = f1 * f2;
            break;
        case '/':
            result = f1 / f2;
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
