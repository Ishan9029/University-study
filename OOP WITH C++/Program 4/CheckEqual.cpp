#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cout << "Enter The First Number -: ";
    cin >> a;
    cout << "Enter The Second Number -: ";
    cin >> b;
    if (a == b)
    {
        cout << "Both Numbers Are Equal" << endl
             << "The First Number -: " << a << endl
             << "The Second Number -: " << b << endl;
    }
    else
    {
        cout << "Both Numbers Are not Equal" << endl
             << "The First Number -: " << a << endl
             << "The Second Number -: " << b << endl;
    }
    return 0;
}