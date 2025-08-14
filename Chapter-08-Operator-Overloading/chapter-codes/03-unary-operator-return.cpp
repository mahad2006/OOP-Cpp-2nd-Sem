#include <iostream>
using namespace std;

// Class representing a counter
class Counter
{
private:
    unsigned int count; // stores the count

public:
    // Constructor initializes count to 0
    Counter() : count(0) {}

    // Function to get current count
    unsigned int get_count() const
    {
        return count;
    }

    // Overload prefix ++ operator and return a Counter object
    Counter operator++()
    {
        ++count;            // increment this object's count
        Counter temp;       // create temporary Counter object
        temp.count = count; // copy the incremented value
        return temp;        // return the copy
    }
};

int main()
{
    Counter c1, c2; // initial counts: c1=0, c2=0

    cout << "\nc1 = " << c1.get_count();
    cout << "\nc2 = " << c2.get_count();

    ++c1;      // c1 = 1
    c2 = ++c1; // c1 = 2, c2 = 2

    cout << "\nc1 = " << c1.get_count();
    cout << "\nc2 = " << c2.get_count() << endl;

    return 0;
}
