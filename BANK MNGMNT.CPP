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
