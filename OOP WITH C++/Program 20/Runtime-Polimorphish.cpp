#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void draw()
    {
        cout << "Drawing a shape" << endl;
    }
};

class Circle : public Shape
{
public:
    void draw() override
    {
        cout << "Drawing a circle" << endl;
    }
};

class Square : public Shape
{
public:
    void draw() override
    {
        cout << "Drawing a square" << endl;
    }
};

int main()
{
    Shape *shape;
    Circle c;
    Square s;

    shape = &c;
    shape->draw(); // Outputs: Drawing a circle

    shape = &s;
    shape->draw(); // Outputs: Drawing a square

    return 0;
}
