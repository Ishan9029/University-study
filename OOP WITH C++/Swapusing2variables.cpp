#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cout << "Enter The First Number -: ";
    cin >> a;
    cout << "Enter The Second Number -: ";
    cin >> b;
    cout << "Before Swapping" << endl;
    cout << "First Number -: " << a << endl;
    cout << "Second Number -: " << b << endl;

    a = a + b;
    b = a - b;
    a = a - b;
    cout << "After Swapping" << endl;
    cout << "First Number -: " << a << endl;
    cout << "Second Number -: " << b << endl;
}