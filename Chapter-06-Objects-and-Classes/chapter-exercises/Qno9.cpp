#include <iostream>
using namespace std;

class fraction
{
private:
    int numerator;
    int denominator;

public:
    // getter
    void getdata()
    {
        char ch;
        cout << "Enter the Fraction in this format n/d.";
        cin >> numerator >> ch >> denominator;
        // Ensure denominator is not zero (invalid fraction)
        if (denominator == 0)
        {
            cout << "Denominator cannot be zero! Setting it to 1 by default.\n";
            denominator = 1;
        }
    }
    // display functiona
    void showdata() const
    {
        cout << numerator << "/" << denominator << endl;
    }

    fraction add(fraction f)
    {
        fraction temp;
        temp.numerator = numerator * f.denominator + denominator * f.numerator;
        temp.denominator = denominator * f.denominator;
        return temp;
    }
};
int main()
{
    fraction f1, f2, f3;
    f1.getdata();
    f2.getdata();
    f3 = f1.add(f2);
    f3.showdata();
    return 0;
}