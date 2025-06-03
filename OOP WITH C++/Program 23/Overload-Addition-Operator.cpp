#include <iostream>
using namespace std;

class Complex
{
    int r, i;

public:
    Complex(int a = 0, int b = 0)
    {
        r = a;
        i = b;
    }
    Complex operator+(Complex c)
    {
        return Complex(r + c.r, i + c.i);
    }
    void show() { cout << r << "+" << i << " = " << r + i << "\n"; }
};

int main()
{
    Complex a(2, 3), b(1, 4), c;
    c = a + b;
    c.show();
}
