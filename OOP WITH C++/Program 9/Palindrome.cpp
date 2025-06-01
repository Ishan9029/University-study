#include <iostream>
using namespace std;

int main()
{
    char str[100];
    int length = 0, i, isPalindrome = 1;

    cout << "Enter a string (no spaces): ";
    cin >> str;

    // Manually calculate length
    while (str[length] != '\0')
    {
        length++;
    }

    // Compare characters from front and back
    for (i = 0; i < length / 2; i++)
    {
        if (str[i] != str[length - 1 - i])
        {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        cout << "The string is a palindrome." << endl;
    else
        cout << "The string is not a palindrome." << endl;

    return 0;
}
