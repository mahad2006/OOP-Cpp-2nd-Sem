// *2. Write a program that substitutes an overloaded += operator for the overloaded + operator
// in the STRPLUS program in this chapter. This operator should allow statements like
// s1 += s2;
// where s2 is added (concatenated) to s1 and the result is left in s1. The operator should
// also permit the results of the operation to be used in other calculations, as in
// s3 = s1 += s2;

#include <iostream>
#include <cstring>   // for strcpy(), strlen(), strcat()
#include <process.h> // for exit()
using namespace std;

////////////////////////////////////////////////////////////////
class String // user-defined string type
{
private:
    enum
    {
        SZ = 80
    };            // maximum size of String objects
    char str[SZ]; // holds a C-style string

public:
    // ----- Constructors -----

    // No-argument constructor
    String()
    {
        strcpy(str, ""); // initialize as empty string
    }

    // 1-argument constructor (must take const char* for string literals)
    String(const char s[])
    {
        strcpy(str, s); // initialize with given C-string
    }

    // ----- Member Functions -----

    // Display the String
    void display() const
    {
        cout << str;
    }

    // Overloaded += operator
    // Concatenates another String (ss) to the current String (this->str)
    // and returns *this by reference for chaining
    String &operator+=(const String &ss)
    {
        // Check if concatenation will exceed max size
        if (strlen(str) + strlen(ss.str) >= SZ)
        {
            cout << "\nString overflow";
            exit(1); // terminate program if overflow
        }
        strcat(str, ss.str); // append ss.str to str
        return *this;        // return reference to the current object
    }
};
////////////////////////////////////////////////////////////////

int main()
{
    // Create String objects
    String s1 = "Happy Independence Day! "; // uses 1-arg constructor
    String s2 = "Happy New Year!";          // uses 1-arg constructor
    String s3;                              // uses no-arg constructor

    // Demonstrating overloaded += operator
    s3 = s1 += s2; // concatenates s2 to s1, assigns the result to s3

    // Display results
    cout << "\ns1 = ";
    s1.display();
    cout << "\ns2 = ";
    s2.display();
    cout << "\ns3 = ";
    s3.display();
    cout << endl;

    return 0;
}
// End of program