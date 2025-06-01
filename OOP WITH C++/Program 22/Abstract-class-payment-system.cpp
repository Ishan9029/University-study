#include <iostream>
using namespace std;

class Payment
{
public:
    virtual void pay(float amount) = 0; // Pure virtual function
};

class CreditCardPayment : public Payment
{
public:
    void pay(float amount) override
    {
        cout << "Paid ₹" << amount << " using Credit Card." << endl;
    }
};

class PayPalPayment : public Payment
{
public:
    void pay(float amount) override
    {
        cout << "Paid ₹" << amount << " using PayPal." << endl;
    }
};

int main()
{
    Payment *payment;
    CreditCardPayment cc;
    PayPalPayment pp;

    payment = &cc;
    payment->pay(1500.00); // Outputs: Paid ₹1500 using Credit Card.

    payment = &pp;
    payment->pay(2200.50); // Outputs: Paid ₹2200.5 using PayPal.

    return 0;
}
