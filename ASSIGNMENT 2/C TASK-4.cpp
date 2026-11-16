#include <iostream>
#include <string>
using namespace std;
 
class SavingsAccount {
private:
    string accountNumber;
    double balance;
    double transactions[10];
    int count;
 
    void addTransaction(double amount) { // private helper
        if (count < 10) {
            transactions[count++] = amount;
        } else {
            for (int i = 1; i < 10; ++i)
                transactions[i - 1] = transactions[i];
            transactions[9] = amount;
        }
    }
 
public:
    SavingsAccount(const string& number, double openingBalance)
        : accountNumber(number), balance(openingBalance), count(0) {
        addTransaction(openingBalance);
    }
 
    void deposit(double amount);       // defined outside
    bool withdraw(double amount);      // defined outside
    void miniStatement() const;        // defined outside
};
 
void SavingsAccount::deposit(double amount) {
    if (amount <= 0) return;
    balance += amount;
    addTransaction(amount);
}
 
bool SavingsAccount::withdraw(double amount) {
    if (amount <= 0 || amount > balance) return false;
    balance -= amount;
    addTransaction(-amount);
    return true;
}
 
void SavingsAccount::miniStatement() const {
    cout << "Account: " << accountNumber << '\\n';
    cout << "Balance: " << balance << '\\n';
    cout << "Recent transactions (oldest to newest):\\n";
    for (int i = 0; i < count; ++i)
        cout << transactions[i] << '\\n';
}
 
int main() {
    SavingsAccount account("SB1001", 1000);
    account.deposit(500);
    account.withdraw(200);
    account.deposit(250);
    account.miniStatement();
    return 0;
}