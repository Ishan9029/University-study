#include <iostream>
using namespace std;

// Base class
class Shape
{
public:
    void display()
    {
        cout << "This is a shape." << endl;
    }
};

// Derived class Circle
class Circle : public Shape
{
private:
    float radius;

public:
    void setRadius(float r)
    {
        radius = r;
    }

    float area()
    {
        return 3.1416f * radius * radius;
    }
};

// Derived class Square
class Square : public Shape
{
private:
    float side;

public:
    void setSide(float s)
    {
        side = s;
    }

    float area()
    {
        return side * side;
    }
};

int main()
{
    Circle c;
    Square s;

    c.setRadius(5);
    s.setSide(4);

    cout << "Circle area: " << c.area() << endl;
    cout << "Square area: " << s.area() << endl;

    // Calling base class method
    c.display();
    s.display();

    return 0;
}
