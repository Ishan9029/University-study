#include <iostream>
#include <fstream>
#include <string> // Required for string
using namespace std;

int main()
{
    ofstream file("students.txt", ios::app);
    string name;
    int roll;
    cout << "Enter name and roll: ";
    cin >> name >> roll;
    file << name << " " << roll << endl;
    file.close();

    ifstream read("students.txt");
    string n;
    int r;
    cout << "\nStudent Records:\n";
    while (read >> n >> r)
    {
        cout << "Name: " << n << ", Roll: " << r << endl;
    }
    read.close();
    return 0;
}
