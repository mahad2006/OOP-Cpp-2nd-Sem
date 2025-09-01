// *1. To the Distance class in the ENGLPLUS program in this chapter, add an overloaded
// - operator that subtracts two distances. It should allow statements like dist3=
// dist1-dist2;. Assume that the operator will never be used to subtract a larger number
// from a smaller one (that is, negative distances are not allowed).
#include <iostream>
using namespace std;
class Distance
{
private:
    int feet;
    float inches;

public:
    // constructor
    Distance() : feet(0), inches(0.0) {}
    // parameterized constructor
    Distance(int f, float i) : feet(f), inches(i) {}
    // getter
    void getdata()
    {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }
    // display functiona
    void showdata() const
    {
        cout << feet << " feet and " << inches << " inches." << endl;
    }
    // operator overloading function
    Distance operator-(Distance d)
    {
        Distance temp;
        temp.feet = feet - d.feet;
        temp.inches = inches - d.inches;
        return temp;
    }
    Distance operator+(Distance d)
    {
        Distance temp;
        temp.feet = feet + d.feet;
        temp.inches = inches + d.inches;
        return temp;
    }
};

int main()
{
    Distance d1, d2, d3;
    d1.getdata();
    d2.getdata();
    d3 = d1 - d2; // d3 = d1.operator-(d2);
    d3.showdata();
    d3 = d1 + d2; // d3 = d1.operator+(d2);
    d3.showdata();
    return 0;
}