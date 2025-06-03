#include <iostream>
using namespace std;

class Date
{
    int d, m, y;

public:
    Date(int a, int b, int c)
    {
        d = a;
        m = b;
        y = c;
    }
    bool operator==(Date dt)
    {
        return d == dt.d && m == dt.m && y == dt.y;
    }
};

int main()
{
    Date d1(1, 1, 2024), d2(1, 1, 2024);
    if (d1 == d2)
        cout << "Equal\n";
    else
        cout << "Not Equal\n";
}
