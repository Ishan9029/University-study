#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cout << "Entr The First Number : ";
    cin >> a;
    cout << "Enter The Second Number : ";
    cin >> b;
    cout << "Before Swapping\n";
    cout << "First Number : " << a << "\nSecond Number : " << b;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "\nAfter Swapping\n";
    cout << "First Number : " << a << "\nSecond Number : " << b;
    return 0;
}