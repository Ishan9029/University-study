#include <iostream>
using namespace std;

class Library
{
private:
    static int totalBooks; // Static data member

public:
    // Static function to add books
    static void addBook(int num)
    {
        totalBooks += num;
        cout << num << " book(s) added.\n";
    }

    // Static function to issue a book
    static void issueBook()
    {
        if (totalBooks > 0)
        {
            totalBooks--;
            cout << "One book issued.\n";
        }
        else
        {
            cout << "No books available to issue.\n";
        }
    }

    // Static function to display total books
    static void displayBooks()
    {
        cout << "Total books in library: " << totalBooks << endl;
    }
};

// Definition and initialization of static data member
int Library::totalBooks = 0;

int main()
{
    Library::displayBooks(); // Initially 0
    Library::addBook(5);     // Add 5 books
    Library::displayBooks(); // Show updated count
    Library::issueBook();    // Issue one book
    Library::displayBooks(); // Show count after issue
    Library::issueBook();    // Issue another book
    Library::displayBooks(); // Final count

    return 0;
}
