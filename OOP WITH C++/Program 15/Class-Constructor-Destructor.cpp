#include <iostream>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    char accountHolder[50];
    float balance;

public:
    // Constructor
    BankAccount()
    {
        cout << "Enter account number: ";
        cin >> accountNumber;

        cout << "Enter account holder name: ";
        cin >> accountHolder;

        cout << "Enter initial balance: ";
        cin >> balance;

        cout << "Account created successfully!\n";
    }

    // Function to display account info
    void display()
    {
        cout << "\nAccount Information:\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
    }

    // Destructor
    ~BankAccount()
    {
        cout << "\nDestructor called. Account " << accountNumber << " is closed.\n";
    }
};

int main()
{
    BankAccount acc1; // Object created
    acc1.display();   // Display account info

    return 0; // Object destroyed here, destructor called
}
