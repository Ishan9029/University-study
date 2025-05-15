#include <iostream>
#include "fact.h"
using namespace std;

int main()
{
    int a;
    cout << "Enter The Number -: ";
    cin >> a;
    cout << "Factorial = " << fact(a) << endl;
    return 0;
}