#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream outFile("example.txt");
    outFile << "Hello, this is a test file.\n";
    outFile << "We are writing to it.\n";
    outFile.close();

    ifstream inFile("example.txt");
    string line;
    while (getline(inFile, line))
    {
        cout << line << endl;
    }
    inFile.close();
    return 0;
}
