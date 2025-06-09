#include <iostream>

using namespace std;

int main()
{

    int a, b;

    cout << "Enter numerator: ";
    cin >> a;

    cout << "Enter denominator: ";
    cin >> b;

    try
    {
        if (b == 0)
        {
            throw 0;
        }
        if (a < 0 || b < 0)
        {
            throw 'n'; // throw char if any number is negative
        }
        float result = (float)a / b;
        cout << "Result: " << result << endl;
    }
    catch (int)
    {
        cout << "Exception: Division by zero is not allowed." << endl;
    }
    catch (char c)
    {
        cout << "Exception: Negative numbers are not allowed." << endl;
    }
    catch (...)
    {
        cout << "Exception: Unknown error occurred." << endl;
    }

    return 0;
}