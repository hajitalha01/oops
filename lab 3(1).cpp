#include <iostream>
#include <string>
using namespace std;

class employ {
private:
    string accountname;
    string accountnumber;
    double balance;

    // Check if withdrawal amount is valid
    bool validateamount(double amount) {
        if (balance >= amount)
            return true;
        else
            return false;
    }

public:
    // Constructor to initialize values
    employ(string name, string accnum, double bal) {
        accountname = name;
        accountnumber = accnum;
        balance = bal; // ? Fixed this line
    }

    // Withdraw amount from balance
    void withdraw(double amount) {
        if (validateamount(amount)) {
            balance -= amount;
            cout << "Withdrawal successful. Remaining balance: " << balance << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    // Deposit amount into balance
    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful. New balance: " << balance << endl;
    }

    // Show account information
    void accountinfo() {
        cout << "Account Name: " << accountname << endl;
        cout << "Account Number: " << accountnumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    employ talha("Talha", "12211", 100.0); // object created

    talha.accountinfo();     // show initial info
    talha.withdraw(45.0);    // withdraw 45
    talha.deposit(100.0);    // deposit 100
    talha.accountinfo();     // show updated info

    return 0;
}

