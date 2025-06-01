#include <iostream>
using namespace std;

class Counter
{
private:
    static int count; // Static data member

public:
    // Static member function to increment count
    static void increment()
    {
        count++;
    }

    // Static member function to display count
    static void showCount()
    {
        cout << "Current count is: " << count << endl;
    }
};

// Define and initialize static data member
int Counter::count = 0;

int main()
{
    // Call static functions using class name
    Counter::showCount(); // Output: 0
    Counter::increment(); // Increment once
    Counter::increment(); // Increment again
    Counter::showCount(); // Output: 2

    return 0;
}
