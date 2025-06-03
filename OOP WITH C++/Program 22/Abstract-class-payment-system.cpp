#include <iostream>
using namespace std;

class Payment
{
public:
    virtual void pay() = 0; // pure virtual
};

class Card : public Payment
{
public:
    void pay()
    {
        cout << "Paid using Card\n";
    }
};

int main()
{
    Payment *p;
    Card c;
    p = &c;
    p->pay();
}
