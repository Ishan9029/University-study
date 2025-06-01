#include <iostream>
using namespace std;
int main()
{
    int x, y, a;
    char i;
start:
    cout << "\033[H\033[J";
    cout << "Welcome To The Basic Calculator" << endl;
    cout << "Enter The First Number -: ";
    cin >> x;
    cout << "\033[H\033[J";
    cout << "Enter The Second Number -: ";
    cin >> y;
    cout << "\033[H\033[J";
    cout << "Enter an Choice" << endl
         << "Addition = +" << endl
         << "Subtraction = -" << endl
         << "Multiplication = *" << endl
         << "Division = /" << endl
         << "Modulus = % " << endl
         << " -: ";
    cin >> i;

    switch (i)
    {
    case '+':
        cout << "\033[H\033[J";
        cout << "Ans -: " << x + y << endl;
        cout << "\n\n\nDo You Wish To Continue?" << endl;
        cout << "1 = YES\n2 = NO" << endl;
        cin >> a;
        if (a == 1)
        {
            goto start;
        }
        else
        {
            cout << "\033[H\033[J";
            cout << "Thank You For Using This Calculator" << endl;
            return 0;
        }
    case '-':
        cout << "\033[H\033[J";
        cout << "Ans -: " << x - y << endl;
        cout << "\n\n\nDo You Wish To Continue?" << endl;
        cout << "1 = YES\n2 = NO" << endl;
        cin >> a;
        if (a == 1)
        {
            goto start;
        }
        else
        {
            cout << "\033[H\033[J";
            cout << "Thank You For Using This Calculator" << endl;
            return 0;
        }
    case '*':
        cout << "\033[H\033[J";
        cout << "Ans -: " << x * y << endl;
        cout << "\n\n\nDo You Wish To Continue?" << endl;
        cout << "1 = YES\n2 = NO" << endl;
        cin >> a;
        if (a == 1)
        {
            goto start;
        }
        else
        {
            cout << "\033[H\033[J";
            cout << "Thank You For Using This Calculator" << endl;
            return 0;
        }
    case '/':
        if (y == 0)
        {
            cout << "Error: Division by zero is not allowed.";
        }
        else
        {
            cout << "\033[H\033[J";
            cout << "Ans -: " << x / y << endl;
        }
        cout << "\n\n\nDo You Wish To Continue?" << endl;
        cout << "1 = YES\n2 = NO" << endl;
        cin >> a;
        if (a == 1)
        {
            goto start;
        }
        else
        {
            cout << "\033[H\033[J";
            cout << "Thank You For Using This Calculator" << endl;
            return 0;
        }
    case '%':
        cout << "\033[H\033[J";
        cout << "Ans -: " << x % y << endl;
        cout << "\n\n\nDo You Wish To Continue?" << endl;
        cout << "1 = YES\n2 = NO" << endl;
        cin >> a;
        if (a == 1)
        {
            goto start;
        }
        else
        {
            cout << "\033[H\033[J";
            cout << "Thank You For Using This Calculator" << endl;
            return 0;
        }
    default:
        cout << "\033[H\033[J";
        cout << "Invalid Operator";
        cout << "\n\n\nDo You Wish To Continue?" << endl;
        cout << "1 = YES\n2 = NO" << endl;
        cin >> a;
        if (a == 1)
        {
            goto start;
        }
        else
        {
            cout << "\033[H\033[J";
            cout << "Thank You For Using This Calculator" << endl;
            return 0;
        }
    }
    return 0;
}