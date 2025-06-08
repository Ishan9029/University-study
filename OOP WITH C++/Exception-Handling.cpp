#include <iostream>
using namespace std;
int main()
{
    int a, b, res;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    try
    {
        if (a == b || b == 0)
        {
            throw b;
        }
        res = a / b;
        cout << "Result: " << res << endl;
    }
    catch (int x)
    {
        cout << "Exception: Division by zero or equal numbers not allowed." << endl;
    }
    cout << "End of program." << endl;
    return 0;
}