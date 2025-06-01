#include <iostream>
using namespace std;

int main()
{
    char str[100];
    int length = 0;

    cout << "Enter a string (no spaces): ";
    cin >> str;

    // Find the length of the string
    while (str[length] != '\0')
    {
        length++;
    }

    // Display reversed string
    cout << "Reversed string: ";
    for (int i = length - 1; i >= 0; i--)
    {
        cout << str[i];
    }
    cout << endl;

    return 0;
}
