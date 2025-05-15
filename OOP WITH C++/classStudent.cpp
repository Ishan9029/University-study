#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Student
{
public:
    string name;
    string ID;
    vector<int> grades;
    Student(string n, string id, vector<int> g) : name(n), ID(id), grades(g) {}
    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Grades: ";
        for (int grade : grades)
        {
            cout << grade << " ";
        }
        cout << endl;
    }
};
int main()
{
    vector<int> grades = {85, 90, 88};
    Student student("Ishan Ahmed", "S123", grades);
    student.displayInfo();
    return 0;
}