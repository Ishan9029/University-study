#include <iostream>
using namespace std;

class Student
{
    int id;

public:
    friend istream &operator>>(istream &in, Student &s)
    {
        in >> s.id;
        return in;
    }
    friend ostream &operator<<(ostream &out, Student s)
    {
        out << "ID: " << s.id;
        return out;
    }
};

int main()
{
    Student s;
    cin >> s;
    cout << s;
}
