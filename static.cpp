#include <iostream>
using namespace std;

class BankAccount {
private:
    static int accountCount;  // Static variable to count the number of accounts created
    int accountNumber;        // Account number of each bank account
    double balance;           // Balance of the bank account

public:
    // Constructor to initialize accountNumber and balance
    BankAccount(int accNum, double bal) {
        this->accountNumber = accNum;  // Assign passed account number to the instance variable
        balance = bal;                 // Set balance from constructor argument
        accountCount++;                // Increment the account count when a new account is created
    }

    // Method to deposit money into the account
    void deposit(double amount) {
        balance += amount;  // Add the deposit amount to the balance
        cout << "Deposit Successful. New Balance: " << balance << endl;
    }

    // Method to withdraw money from the account
    void withdraw(double amount) {
        if (balance >= amount) {  // Check if there's enough balance to withdraw
            balance -= amount;  // Deduct the withdrawal amount from the balance
            cout << "Withdrawal Successful. Remaining Balance: " << balance << endl;
        } else {
            cout << "Insufficient Balance!" << endl;  // If balance is insufficient, display a warning
        }
    }

    // Static method to get the total number of bank accounts created
    static int getAccountCount() {
        return accountCount;  // Return the value of static accountCount
    }

    // Method to display account information
    void accountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Initialize static variable
int BankAccount::accountCount = 0;

int main() {
    // Create two bank accounts
    BankAccount acc1(1001, 500.0);  // Account 1 with account number 1001 and balance 500.0
    BankAccount acc2(1002, 1000.0); // Account 2 with account number 1002 and balance 1000.0

    // Display account information for acc1
    acc1.accountInfo();
    
    // Perform some transactions on acc1
    acc1.withdraw(200);   // Withdraw 200 from acc1
    acc1.deposit(300);    // Deposit 300 into acc1
    acc1.accountInfo();   // Display updated account information for acc1

    // Display the total number of bank accounts created
    cout << "Total Bank Accounts Created: " << BankAccount::getAccountCount() << endl;

    return 0;
}

