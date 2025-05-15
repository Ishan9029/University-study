#include <iostream>
using namespace std;
int main()
{
    int a, b = 0, rev = 0;
    cout << "Enter The Number -: ";
    cin >> a;
    cout << "Number = " << a << endl;
    while (a != 0)
    {
        b = a % 10;
        rev = rev * 10 + b;
        a = a / 10;
    }
    cout << "Reversed Number = " << rev << endl;
}