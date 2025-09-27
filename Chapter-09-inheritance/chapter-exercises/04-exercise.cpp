// 4. Assume that the publisher in Exercises 1 and 3 decides to add a third way to distribute
// books: on computer disk, for those who like to do their reading on their laptop. Add a
// disk class that, like book and tape, is derived from publication. The disk class should
// incorporate the same member functions as the other classes. The data item unique to this
// class is the disk type: either CD or DVD. You can use an enum type to store this item.
// The user could select the appropriate type by typing c or d.
#include <iostream>
using namespace std;
class Publication
{
    string title;
    float price;

public:
    void getdata()
    {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }
    void putdata() const
    {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};
class Book : public Publication
{
    int pagecount;

public:
    void getdata()
    {
        Publication::getdata();
        cout << "Enter page count: ";
        cin >> pagecount;
    }
    void putdata() const
    {
        Publication::putdata();
        cout << "Page count: " << pagecount << endl;
    }
};
class Tape : public Publication
{
    float playtime;

public:
    void getdata()
    {
        Publication::getdata();
        cout << "Enter play time (in minutes): ";
        cin >> playtime;
    }
    void putdata() const
    {
        Publication::putdata();
        cout << "Play time: " << playtime << " minutes" << endl;
    }
};
class Disk : public Publication
{
    enum DiskType
    {
        CD,
        DVD
    } dtype;

public:
    void getdata()
    {
        Publication::getdata();
        char type;
        cout << "Enter disk type (c for CD, d for DVD): ";
        cin >> type;
        if (type == 'c' || type == 'C')
            dtype = CD;
        else if (type == 'd' || type == 'D')
            dtype = DVD;
        else
        {
            cout << "Invalid disk type! Defaulting to CD." << endl;
            dtype = CD;
        }
    }
    void putdata() const
    {
        Publication::putdata();
        cout << "Disk type: " << (dtype == CD ? "CD" : "DVD") << endl;
    }
};
int main()
{
    Book book;
    Tape tape;
    Disk disk;
    cout << "Enter details for book:" << endl;
    book.getdata();

    cout << "\nEnter details for tape:" << endl;
    tape.getdata();

    cout << "\nEnter details for disk:" << endl;
    disk.getdata();
    cout << "\nDetails of book:" << endl;
    book.putdata();
    cout << "\nDetails of tape:" << endl;
    tape.putdata();
    cout << "\nDetails of disk:" << endl;
    disk.putdata();

    return 0;
}