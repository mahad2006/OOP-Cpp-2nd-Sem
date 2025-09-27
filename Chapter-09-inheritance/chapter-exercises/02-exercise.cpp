// *2. Recall the STRCONV example from Chapter 8. The String class in this example has a
// flaw: It does not protect itself if its objects are initialized to have too many characters.
// (The SZ constant has the value 80.) For example, the definition
// String s = “This string will surely exceed the width of the “
// “screen, which is what the SZ constant represents.”;
// will cause the str array in s to overflow, with unpredictable consequences, such as
// crashing the system.
// With String as a base class, derive a class Pstring (for “protected string”) that prevents
// buffer overflow when too long a string constant is used in a definition. A new constructor
// in the derived class should copy only SZ–1 characters into str if the string constant is
// longer, but copy the entire constant if it’s shorter. Write a main() program to test different
// lengths of strings.
#include <iostream>
#include <cstring>
using namespace std;
class String
{
protected:
    enum
    {
        SZ = 80
    }; // max size
    char str[SZ]; // holds string

public:
    String() { strcpy(str, ""); }              // no-arg constructor
    String(const char s[]) { strcpy(str, s); } // 1-arg constructor

    void display() const { cout << str; } // display string

    void getstr() { cin.get(str, SZ); } // read string from user

    bool operator==(const String &ss) const
    { // equality check
        return strcmp(str, ss.str) == 0;
    }
};

class Pstring : public String
{
public:
    Pstring() : String() {}

    Pstring(const char s[])
    {
        if (strlen(s) >= SZ)
        {                            // too long
            strncpy(str, s, SZ - 1); // copy only SZ-1 chars
            str[SZ - 1] = '\0';      // ensure null termination
        }
        else
        {
            strcpy(str, s); // safe to copy whole string
        }
    }
};

int main()
{
    Pstring s1("This is a short string.");
    Pstring s2("This string will surely exceed the width of the screen, which is what the SZ constant represents.");

    cout << "String 1: ";
    s1.display();
    cout << "\nString 2: ";
    s2.display();
    cout << endl;

    return 0;
}
// Output:
// String 1: This is a short string.
// String 2: This string will surely exceed the width of the screen, which is what the SZ co
// nstant represents.
