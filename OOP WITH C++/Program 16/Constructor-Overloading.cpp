#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int width;

public:
    // Default constructor
    Rectangle()
    {
        length = 0;
        width = 0;
        cout << "Default constructor called.\n";
    }

    // Constructor with one parameter
    Rectangle(int l)
    {
        length = l;
        width = l;
        cout << "Constructor with one parameter called.\n";
    }

    // Constructor with two parameters
    Rectangle(int l, int w)
    {
        length = l;
        width = w;
        cout << "Constructor with two parameters called.\n";
    }

    void displayArea()
    {
        cout << "Area: " << (length * width) << endl;
    }
};

int main()
{
    Rectangle r1; // Calls default constructor
    r1.displayArea();

    Rectangle r2(5); // Calls 1-parameter constructor
    r2.displayArea();

    Rectangle r3(4, 6); // Calls 2-parameter constructor
    r3.displayArea();

    return 0;
}
