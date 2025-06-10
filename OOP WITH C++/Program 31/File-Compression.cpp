#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // Step 1: Write sample input
    ofstream out("input.txt");
    out << "aaabbccccdd";
    out.close();

    // Step 2: Read input and write compressed output
    ifstream in("input.txt");
    ofstream comp("compressed.txt");
    char prev = '\0', ch;
    int count = 0;

    while (in.get(ch))
    {
        if (ch == prev)
            count++;
        else
        {
            if (prev != '\0')
                comp << prev << count;
            prev = ch;
            count = 1;
        }
    }
    if (prev != '\0')
        comp << prev << count;
    in.close();
    comp.close();

    // Step 3: Show compressed output on screen
    ifstream show("compressed.txt");
    string output;
    getline(show, output); // read full line
    cout << "Compressed Output: " << output << endl;
    show.close();
    return 0;
}
