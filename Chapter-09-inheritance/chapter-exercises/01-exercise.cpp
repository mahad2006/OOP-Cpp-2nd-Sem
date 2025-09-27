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
class Book : public Publication
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
    }
    // display functiona
    void putdata() const
    {
        Publication::putdata(); // display title and price
        cout << "Page Count: " << pageCount << endl;
    }
};
class Tape : public Publication
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
    }
    // display functiona
    void putdata() const
    {
        Publication::putdata(); // display title and price
        cout << "Play Time: " << playTime << " minutes" << endl;
    }
};
int main()
{
    Book b;
    Tape t;
    cout << "Enter book details:\n";
    b.getdata();
    cout << "\nEnter tape details:\n";
    t.getdata();
    cout << "\nBook details:\n";
    b.putdata();
    cout << "\nTape details:\n";
    t.putdata();
    return 0;
}