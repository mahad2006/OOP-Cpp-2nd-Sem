#include <iostream>
using namespace std;

// Class representing a counter
class Counter
{
private:
    unsigned int count; // stores the count

public:
    // Default constructor
    Counter() : count(0) {}

    // Constructor with one argument
    Counter(int c) : count(c) {}

    // Function to get current count
    unsigned int get_count() const
    {
        return count;
    }

    // Prefix ++ operator: increment first, then return
    Counter operator++()
    {
        return Counter(++count); // increment, then return a temporary object
    }

    // Postfix ++ operator: return value first, then increment
    Counter operator++(int)
    {
        return Counter(count++); // return temporary object initialized to current count
    }
};

int main()
{
    Counter c1, c2; // initial counts: c1=0, c2=0

    cout << "\nc1 = " << c1.get_count();
    cout << "\nc2 = " << c2.get_count();

    ++c1;      // prefix: c1 = 1
    c2 = ++c1; // prefix: c1 = 2, c2 = 2

    cout << "\nc1 = " << c1.get_count();
    cout << "\nc2 = " << c2.get_count();

    c2 = c1++; // postfix: c2 = 2, c1 = 3

    cout << "\nc1 = " << c1.get_count();
    cout << "\nc2 = " << c2.get_count() << endl;

    return 0;
}
