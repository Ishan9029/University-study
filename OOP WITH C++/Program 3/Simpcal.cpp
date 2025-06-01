#include <iostream>
using namespace std;
int main()
{
    int a, b;
    char ch;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> ch;
    switch (ch)
    {
    case '+':
        cout << a << " + " << b << " = " << a + b;
        break;
    case '-':
        cout << a << " - " << b << " = " << a - b;
        break;
    case '*':
        cout << a << " * " << b << " = " << a * b;
        break;
    case '/':
        cout << a << " / " << b << " = " << a / b;
        break;
    default:
        cout << "Error! operator is not correct";
        break;
    }
    return 0;
}