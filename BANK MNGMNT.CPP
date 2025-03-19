#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Account {
public:
    int accountNumber;
    string accountHolder;
    double balance;
    string pin;

    Account(int accNum, string accHolder, double initBalance, string accPin) {
        accountNumber = accNum;
        accountHolder = accHolder;
        balance = initBalance;
        pin = accPin;
    }
};

void showMenu();
void createAccount(vector<Account>& accounts);
void viewBalance(vector<Account>& accounts, int accountNumber);
void deposit(vector<Account>& accounts, int accountNumber, double amount);
void withdraw(vector<Account>& accounts, int accountNumber, double amount);
void transferFunds(vector<Account>& accounts, int fromAccount, int toAccount, double amount);
Account* findAccount(vector<Account>& accounts, int accountNumber);

int main() {
    vector<Account> accounts;
    showMenu();
    return 0;
}

void deposit(double amount) {
    balance += amount;
    cout << "Deposited: " << amount << endl;
}

void withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        cout << "Withdrawn: " << amount << endl;
    } else {
        cout << "Insufficient funds!" << endl;
    }
}

void showMenu() {
    cout << "\nBank Management System" << endl;
    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Display Account Details" << endl;
    cout << "4. Exit" << endl;
}

int main() {
    BankAccount account1(101, "John Doe", 5000);
    int choice;
    double amount;

    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                account1.deposit(amount);
                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                account1.withdraw(amount);
                break;
            case 3:
                account1.displayAccountDetails();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}

class BankAccount {
private:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(int accNum, string accHolder, double initialBalance)
        : accountNumber(accNum), accountHolder(accHolder), balance(initialBalance) {}

    void displayAccountDetails() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
    }

    int getAccountNumber() const { return accountNumber; }
};

class Bank {
private:
    BankAccount* accounts[10];
    int numAccounts;

public:
    Bank() : numAccounts(0) {}

    void addAccount(BankAccount* account) {
        if (numAccounts < 10) {
            accounts[numAccounts++] = account;
        } else {
            cout << "Bank is full!" << endl;
        }
    }

    void displayAllAccounts() {
        for (int i = 0; i < numAccounts; i++) {
            accounts[i]->displayAccountDetails();
        }
    }
};

int main() {
    Bank bank;
    BankAccount* acc1 = new BankAccount(101, "John Doe", 5000);
    bank.addAccount(acc1);
    
    BankAccount* acc2 = new BankAccount(102, "Jane Smith", 3000);
    bank.addAccount(acc2);

    bank.displayAllAccounts();

    return 0;
}

bool isValidAmount(double amount) {
    return amount > 0;
}
void deleteAccount(int accountNum) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i]->getAccountNumber() == accountNum) {
            delete accounts[i];
            accounts[i] = accounts[numAccounts - 1];
            numAccounts--;
            cout << "Account " << accountNum << " deleted!" << endl;
            return;
        }
    }
    cout << "Account not found!" << endl;
}





