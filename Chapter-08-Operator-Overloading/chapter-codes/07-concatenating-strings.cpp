#include <iostream>
#include <cstring> // for strcpy(), strcat()
using namespace std;

class String
{
private:
    static const int SZ = 80; // Maximum size of string
    char str[SZ];             // Character array to store string

public:
    // Default constructor
    String()
    {
        strcpy(str, "");
    }

    // Constructor with parameter
    String(const char s[])
    {
        strcpy(str, s);
    }

    // Display the string
    void display() const
    {
        cout << str;
    }

    // Overload '+' operator to concatenate two String objects
    String operator+(const String &s2) const
    {
        String temp;

        // Check if total length fits in SZ
        if (strlen(str) + strlen(s2.str) < SZ)
        {
            strcpy(temp.str, str);    // copy first string
            strcat(temp.str, s2.str); // append second string
        }
        else
        {
            cout << "\nString overflow!";
            exit(1);
        }

        return temp; // return concatenated result
    }
};

int main()
{
    String s1("\nHappy Independence Day! ");
    String s2("Happy New Year!");
    String s3; // empty string

    cout << "s1: ";
    s1.display();
    cout << "\ns2: ";
    s2.display();

    // Concatenate s1 and s2
    s3 = s1 + s2;

    cout << "\ns3 (s1 + s2): ";
    s3.display();

    cout << endl;
    return 0;
}
