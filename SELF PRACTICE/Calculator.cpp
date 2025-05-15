#include <iostream>
using namespace std;
int main()
{
    int a = 0, b, c;
    char opp;
    cout << "\033[H\033[J";
    cout << "Welcome To Calculator" << endl;
    cout << "Enter Number -: ";
    cin >> b;
    a = a + b;
    cout << "\033[H\033[J";
start:
    cout << "Choice of Operators\n1. '+'\n2. '-'\n3. '*'\n4. '/'\n5. '%'\nEnter Operator -: ";
    cin >> opp;
    cout << "\033[H\033[J";
    cout << "Enter Number - ";
    cin >> b;
    cout << "\033[H\033[J";
    switch (opp)
    {
    case '+':
        a = a + b;
        cout << "Choices\n1. Enter Another Number\n2. Show Result\n Enter Your choice -: ";
        cin >> c;
        cout << "\033[H\033[J";
        if (c == 1)
        {
            goto start;
        }
        else if (c == 2)
        {
            cout << "Result -: " << a;
            break;
        }
        else
        {
            cout << "Invalid";
            break;
        }
    case '-':
        a = a - b;
        cout << "Choices\n1. Enter Another Number\n2. Show Result\n Enter Your choice -: ";
        cin >> c;
        cout << "\033[H\033[J";
        if (c == 1)
        {
            goto start;
        }
        else if (c == 2)
        {
            cout << "Result -: " << a;
            break;
        }
        else
        {
            cout << "Invalid";
            break;
        }
    case '*':
        a = a * b;
        cout << "Choices\n1. Enter Another Number\n2. Show Result\n Enter Your choice -: ";
        cin >> c;
        cout << "\033[H\033[J";
        if (c == 1)
        {
            goto start;
        }
        else if (c == 2)
        {
            cout << "Result -: " << a;
            break;
        }
        else
        {
            cout << "Invalid";
            break;
        }
    case '/':
        a = a / b;
        cout << "Choices\n1. Enter Another Number\n2. Show Result\n Enter Your choice -: ";
        cin >> c;
        cout << "\033[H\033[J";
        if (c == 1)
        {
            goto start;
        }
        else if (c == 2)
        {
            cout << "Result -: " << a;
            break;
        }
        else
        {
            cout << "Invalid";
            break;
        }
    case '%':
        a = a % b;
        cout << "Choices\n1. Enter Another Number\n2. Show Result\n Enter Your choice -: ";
        cin >> c;
        cout << "\033[H\033[J";
        if (c == 1)
        {
            goto start;
        }
        else if (c == 2)
        {
            cout << "Result -: " << a;
            break;
        }
        else
        {
            cout << "Invalid";
            break;
        }
    default:
        cout << "Invalid Operator";
        break;
    }
    return 0;
}