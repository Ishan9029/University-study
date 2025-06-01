#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void makeSound()
    {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal
{
public:
    void makeSound() override
    {
        cout << "Dog says: Woof!" << endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound() override
    {
        cout << "Cat says: Meow!" << endl;
    }
};

int main()
{
    Animal *animal;
    Dog d;
    Cat c;

    animal = &d;
    animal->makeSound(); // Outputs: Dog says: Woof!

    animal = &c;
    animal->makeSound(); // Outputs: Cat says: Meow!

    return 0;
}
