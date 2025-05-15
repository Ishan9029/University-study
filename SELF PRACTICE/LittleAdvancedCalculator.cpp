#include <iostream>
using namespace std;
int main()
{
    double a = 0, b, c;
    char opp;
    cout << "\033[H\033[J";
    cout << "WELCOME TO THIS CALCULATOR MADE BY ISHAN" << endl;
    cout << "ENTER NUMBER -: ";
    cin >> b;
    a = a + b;
    cout << "\033[H\033[J";
start:
    cout << "AVAILABLE CHOICES\n\n1. '+'\n\n2. '-'\n\n3. '*'\n\n4. '/'\n\n5. '='(EXIT)\n\nENTER YOUR CHOICE -: ";
    cin >> opp;
    if (opp == '=')
    {
        cout << "\033[H\033[J";
        cout << "RESULT -: " << a << endl;
        cout << "THANK YOU FOR USING THIS CALCULATOR!!";
        return 0;
    }
    else if (opp != '+' && opp != '-' && opp != '*' && opp != '/' && opp != '%' && opp != '=')
    {
        cout << "INVALID OPERATOR" << endl;
    }
    cout << "\033[H\033[J";
    cout << "ENTER NUMBER - ";
    cin >> b;
    cout << "\033[H\033[J";
    switch (opp)
    {
    case '+':
        a = a + b;
        cout << "RESULT -: " << a << endl
             << endl
             << endl;
        goto start;
        break;
    case '-':
        a = a - b;
        cout << "RESULT -: " << a << endl
             << endl
             << endl;
        goto start;
        break;
    case '*':
        a = a * b;
        cout << "RESULT -: " << a << endl
             << endl
             << endl;
        goto start;
        break;
    case '/':
        a = a / b;
        cout << "RESULT -: " << a << endl
             << endl
             << endl;
        goto start;
        break;
    }
    return 0;
}