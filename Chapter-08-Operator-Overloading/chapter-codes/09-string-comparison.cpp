// Overloaded '==' operator to compare strings

#include <iostream>
#include <string.h> // for strcmp()
using namespace std;

class String // user-defined string type
{
private:
    enum
    {
        SZ = 80
    };            // max size
    char str[SZ]; // holds string

public:
    String() // no-arg constructor
    {
        strcpy(str, "");
    }

    String(char s[]) // 1-arg constructor
    {
        strcpy(str, s);
    }

    void display() const // display string
    {
        cout << str;
    }

    void getstr() // read string from user
    {
        cin.get(str, SZ);
    }

    bool operator==(String ss) const // equality check
    {
        return (strcmp(str, ss.str) == 0) ? true : false;
    }
};

int main()
{
    String s1 = "yes";
    String s2 = "no";
    String s3;

    cout << "\nEnter 'yes' or 'no': ";
    s3.getstr(); // get user input

    if (s3 == s1) // compare with "yes"
        cout << "You typed yes\n";
    else if (s3 == s2) // compare with "no"
        cout << "You typed no\n";
    else
        cout << "You didn't follow instructions\n";

    return 0;
}
