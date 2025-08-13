#include <iostream>
using namespace std;

class angle
{
private:
    int degree;
    float minutes;
    char direction;

public:
    angle() {}
    angle(int d, float m, char dr) : degree(d), minutes(m), direction(dr) {}

    // getter
    void getdata()
    {
        cout << "Enter degrees: ";
        cin >> degree;

        cout << "Enter minutes: ";
        cin >> minutes;

        cout << "Enter direction (N/S/E/W): ";
        cin >> direction;
    }

    // setter
    void showdata()
    {
        cout << degree << "\xF8" << minutes << "'" << direction << endl;
    }
};
int main()
{

    angle a1(149, 34.8, 'W');
    a1.showdata();
    angle a2;
    a2.getdata();
    a2.showdata();

    return 0;
}