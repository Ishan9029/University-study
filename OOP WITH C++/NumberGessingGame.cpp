#include <iostream>
#include <random>
using namespace std;

int main()
{
    int a, b, min, max;
    cout << "\033[H\033[J";
    cout << "Enter minimum number: ";
    cin >> min;

    cout << "Enter maximum number: ";
    cin >> max;

    srand(time(0)); // Uses current time to seed RNG
    a = min + rand() % (max - min + 1);

    cout << "\033[H\033[J";

start:
    cout
        << "Enter Your Guess -: ";
    cin >> b;

    if (b == a)
    {
        cout << "\033[H\033[J";
        cout << "Condrats, You Guessed Correct, The Correct Number is " << a << endl;
    }

    else if (b < a)
    {
        cout << "\033[H\033[J";
        cout << "Too Low, Try Again" << endl;
        goto start;
    }

    else
    {
        cout << "\033[H\033[J";
        cout << "Too High, Try Again" << endl;
        goto start;
    }
    return 0;
}