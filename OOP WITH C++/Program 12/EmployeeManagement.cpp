#include <iostream>
#include <string>
using namespace std;
class Employee
{
public:
    string name;
    string ID;
    string position;
    float salary;
    Employee(string n, string id, string pos, float sal) : name(n), ID(id), position(pos),
                                                           salary(sal) {}
    void displayEmployeeDetails()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }
};
int main()
{
    Employee employee("Ishan Ahmed", "E123", "Software Developer", 75000);
    employee.displayEmployeeDetails();
    return 0;
}