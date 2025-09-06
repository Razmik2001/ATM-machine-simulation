#include "customer.hpp"
#include <cmath>


// Constructor
customer::customer(string fullName, string login, string password)
    bankBalance(0.0) {
        setPassword(password);
        setFullName(fullName);
        setLogin(login);
    }

// Destructor
customer::~customer() {}

// --- Getters ---
string customer::getFullName() const { return fullName; }
string customer::getLogin() const { return login; }
string customer::getPassword() const { return password; }
double customer::getBankBalance() const { return bankBalance; }

// --- Setters ---
void customer::setFullName(const string& name) { fullName = name; }
void customer::setLogin(const string& log) { login = log; }
void customer::setPassword(const string& pass) { password = pass; }

// --- Functions ---
void customer::cashIn(std::vector<int> cash, ATM &atm) {
    int money = 0;
    for (mon:cash){
        money += mon;
    }
    if (money <= 0) {
        throw InvalidBalanceException("Deposit must be positive.");
    }
    atm.cashIn(std::vector<int> cash);
    bankBalance += money;
}

void customer::cashOut(int money, ATM &atm) {
    if (money <= 0) {
        throw InvalidBalanceException("Withdrawal must be positive.");
    }
    if ((bankBalance - 1.001 * money) < 0) {
        throw InvalidBalanceException("You don't have enough money.");
    }
    atm.cashOut(money);
    bankBalance -= 1.001 * money;
    bankBalance = std::round(bankBalance * 100.0) / 100.0;
}
