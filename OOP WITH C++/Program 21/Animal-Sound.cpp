#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void sound()
    {
        cout << "Animal sound\n";
    }
};

class Dog : public Animal
{
public:
    void sound()
    {
        cout << "Dog barks\n";
    }
};

class Cat : public Animal
{
public:
    void sound()
    {
        cout << "Cat meows\n";
    }
};

int main()
{
    Animal *a;
    Dog d;
    Cat c;

    a = &d;
    a->sound();
    a = &c;
    a->sound();
}
