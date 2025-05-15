#include <iostream>
using namespace std;
int main()
{
    int i, n, a = 0;
    cout << "Enter the Number Before Which you want the multiples of 3 & 5 -: ";
    cin >> n;
    cout << "Multiples of 3 and 5 -:  ";
    for (i = 1; i < n; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            cout << i << "\t";
            a = a + i;
        }
    }
    cout << endl;
    cout << "Sum of multiples -: " << a;
    return 0;
}