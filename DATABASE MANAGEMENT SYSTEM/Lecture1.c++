#include <iostream>

using namespace std;

int main()
{
    int a, b, temp;
    cout << "Enter the First Number : ";
    cin >> a;
    cout << "Enter the Second Number : ";
    cin >> b;
    cout << "Before Swapping : " << endl;
    cout << "First Number : " << a << endl;
    cout << "Second Number : " << b << endl;
    temp = a;
    a = b;
    b = temp;
    cout << "After Swapping : " << endl;
    cout << "First Number : " << a << endl;
    cout << "Second Number : " << b << endl;
    return 0;
}