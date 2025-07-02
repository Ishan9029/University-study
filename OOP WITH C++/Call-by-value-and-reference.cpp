#include <iostream>
using namespace std;

void value(int a)
{
    a = a + 10;
    cout << "Inside Value, a = " << a << endl;
}

void ref(int &a)
{
    a = a + 10;
    cout << "Inside Ref, a = " << a << endl;
}

int main()
{
    int x = 5;
    value(x);
    cout << "outside Value, x = " << x << endl;
    ref(x);
    cout << "Outside Ref, x = " << x << endl;
    ref(x);
    return 0;
}