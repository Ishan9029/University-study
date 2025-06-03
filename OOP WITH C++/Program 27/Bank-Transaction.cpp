#include <iostream>
using namespace std;

int main()
{
    int bal = 1000, amt;
    cout << "Enter amount to withdraw: ";
    cin >> amt;
    try
    {
        if (amt > bal)
            throw "Insufficient Balance";
        bal -= amt;
        cout << "Remaining: " << bal;
    }
    catch (const char *e)
    {
        cout << e;
    }
}
