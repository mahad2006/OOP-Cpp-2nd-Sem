// *3. Start with the publication, book, and tape classes of Exercise 1. Add a base class sales
// that holds an array of three floats so that it can record the dollar sales of a particular
// publication for the last three months. Include a getdata() function to get three sales
// amounts from the user, and a putdata() function to display the sales figures. Alter the
// book and tape classes so they are derived from both publication and sales. An object
// of class book or tape should input and output sales data along with its other data. Write
// a main() function to create a book object and a tape object and exercise their input/output
// capabilities.
// *1. Imagine a publishing company that markets both book and audiocassette versions of its
// works. Create a class publication that stores the title (a string) and price (type float)
// of a publication. From this class derive two classes: book, which adds a page count (type
// int), and tape, which adds a playing time in minutes (type float). Each of these three
// classes should have a getdata() function to get its data from the user at the keyboard,
// and a putdata() function to display its data.
// Write a main() program to test the book and tape classes by creating instances of them,
// asking the user to fill in data with getdata(), and then displaying the data with putdata().
#include <iostream>
using namespace std;
class Publication
{
private:
    string title;
    float price;

public:
    // constructor
    Publication() : title(""), price(0.0) {}
    // parameterized constructor
    Publication(string t, float p) : title(t), price(p) {}
    // getter

    void getdata()
    {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }
    // display functiona
    void putdata() const
    {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};
class Sales
{
private:
    float sales[3]; // sales for last 3 months
public:
    // constructor
    Sales()
    {
        for (int i = 0; i < 3; ++i)
            sales[i] = 0.0;
    }
    // getter
    void getdata()
    {
        cout << "Enter sales for the last 3 months:\n";
        for (int i = 0; i < 3; ++i)
        {
            cout << "Month " << (i + 1) << ": ";
            cin >> sales[i];
        }
    }
    // display functiona
    void putdata() const
    {
        cout << "Sales for the last 3 months:\n";
        for (int i = 0; i < 3; ++i)
        {
            cout << "Month " << (i + 1) << ": $" << sales[i] << endl;
        }
    }
};
class Book : public Publication, public Sales
{
private:
    int pageCount;

public:
    // constructor
    Book() : pageCount(0) {}
    // parameterized constructor
    Book(string t, float p, int pc) : Publication(t, p), pageCount(pc) {}
    // getter
    void getdata()
    {
        Publication::getdata(); // get title and price
        cout << "Enter page count: ";
        cin >> pageCount;
        Sales::getdata(); // get sales data
    }
    // display functiona
    void putdata() const
    {
        Publication::putdata(); // display title and price
        cout << "Page Count: " << pageCount << endl;
        Sales::putdata(); // display sales data
    }
};
class Tape : public Publication, public Sales
{
private:
    float playTime; // in minutes
public:
    // constructor
    Tape() : playTime(0.0) {}
    // parameterized constructor
    Tape(string t, float p, float pt) : Publication(t, p), playTime(pt) {}
    // getter
    void getdata()
    {
        Publication::getdata(); // get title and price
        cout << "Enter play time (in minutes): ";
        cin >> playTime;
        Sales::getdata(); // get sales data
    }
    // display functiona
    void putdata() const
    {
        Publication::putdata(); // display title and price
        cout << "Play Time: " << playTime << " minutes" << endl;
        Sales::putdata(); // display sales data
    }
};
int main()
{
    Book b;
    Tape t;
    cout << "Enter book details:\n";
    b.getdata();
    cout << "\nBook details:\n";
    b.putdata();
    cout << "\nEnter tape details:\n";
    t.getdata();
    cout << "\nTape details:\n";
    t.putdata();

    return 0;
}