#include <iostream>
using namespace std;

int main()
{
    int a = 10, b;
    cout << "Enter divisor: ";
    cin >> b;
    try
    {
        if (b == 0)
            throw "Cannot divide by zero";
        cout << "Result: " << a / b;
    }
    catch (const char *e)
    {
        cout << e;
    }
}
