#include <iostream>
using namespace std;

// Class representing a counter
class Counter
{
private:
    unsigned int count; // stores the count

public:
    // Default constructor
    // Counter() : count(0) {}

    // Constructor with one argument
    Counter(int c = 0) : count(c) {}

    // Function to get current count
    unsigned int get_count() const
    {
        return count;
    }

    // Overload prefix ++ operator using nameless temporary object
    Counter operator++()
    {
        ++count;               // increment this object's count
        return Counter(count); // return a temporary Counter object
    }
};

int main()
{
    Counter c1, c2; // initial counts: c1=0, c2=0

    cout << "\nc1 = " << c1.get_count();
    cout << "\nc2 = " << c2.get_count();

    ++c1;      // c1 = 1
    c2 = ++c1; // c1 = 2, c2 = 2 using temporary object

    cout << "\nc1 = " << c1.get_count();
    cout << "\nc2 = " << c2.get_count() << endl;

    return 0;
}
