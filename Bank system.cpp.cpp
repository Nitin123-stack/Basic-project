#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountHolderName;
    double balance;

public:
    BankAccount(string name, double initialBalance) {
        accountHolderName = name;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0) {
            if (amount <= balance) {
                balance -= amount;
                cout << "Withdrawn: $" << amount << endl;
            } else {
                cout << "Insufficient balance." << endl;
            }
        } else {
            cout << "Withdrawal amount must be positive." << endl;
        }
    }

    void checkBalance() const {
        cout << "Current balance: $" << balance << endl;
    }

    void displayAccountInfo() const {
        cout << "Account Holder: " << accountHolderName << endl;
        checkBalance();
    }
};

int main() {
    string name;
    double initialDeposit;
    int choice;
    double amount;

    cout << "Enter account holder name: ";
    getline(cin, name);
    cout << "Enter initial deposit amount: $";
    cin >> initialDeposit;

    BankAccount account(name, initialDeposit);

    do {
        cout << "\n--- Bank Menu ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Display Account Info\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.checkBalance();
                break;
            case 4:
                account.displayAccountInfo();
                break;
            case 5:
                cout << "Exiting. Thank you for using our banking system.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

