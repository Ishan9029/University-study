#include <iostream>
using namespace std;

// Base class
class Vehicle
{
protected:
    string brand;
    int year;

public:
    void setData(string b, int y)
    {
        brand = b;
        year = y;
    }

    void display()
    {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
    }
};

// Derived class Car
class Car : public Vehicle
{
private:
    int seats;

public:
    void setCarData(string b, int y, int s)
    {
        setData(b, y);
        seats = s;
    }

    void displayCar()
    {
        cout << "Car details:\n";
        display();
        cout << "Number of seats: " << seats << endl;
    }
};

// Derived class Truck
class Truck : public Vehicle
{
private:
    int loadCapacity; // in tons

public:
    void setTruckData(string b, int y, int capacity)
    {
        setData(b, y);
        loadCapacity = capacity;
    }

    void displayTruck()
    {
        cout << "Truck details:\n";
        display();
        cout << "Load Capacity: " << loadCapacity << " tons" << endl;
    }
};

int main()
{
    Car myCar;
    Truck myTruck;

    myCar.setCarData("Toyota", 2020, 5);
    myTruck.setTruckData("Volvo", 2018, 15);

    myCar.displayCar();
    cout << endl;
    myTruck.displayTruck();

    return 0;
}
