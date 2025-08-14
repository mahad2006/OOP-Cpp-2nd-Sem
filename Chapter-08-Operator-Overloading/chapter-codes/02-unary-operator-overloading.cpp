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

    // Function to get the current count
    unsigned int get_count() const
    {
        return count;
    }

    // Overload prefix ++ operator to increment count
    void operator++()
    {
        ++count; // increment the count
    }
};

int main()
{
    Counter c1, c2; // create two Counter objects

    cout << "\nc1 = " << c1.get_count(); // initial value 0
    cout << "\nc2 = " << c2.get_count();

    ++c1; // increment c1
    ++c2; // increment c2
    ++c2; // increment c2 again

    cout << "\nc1 = " << c1.get_count(); // after increment
    cout << "\nc2 = " << c2.get_count() << endl;

    return 0;
}
