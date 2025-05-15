#include <iostream>
using namespace std;

int main()
{
    cout << "Enter The Number You Want The Factorial of -: ";
    int n, i, a = 1;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        a = a * i;
    }
    cout << "The Factorial of " << n << " is " << a;
    return 0;
}