#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>
#include "MyExceptions.hpp" 
#include "ATM.hpp"

using std::string;

class customer {
    string fullName;
    string login;
    string password;
    double bankBalance;

    // --- Setters ---
    void setFullName(const string& name);
    void setLogin(const string& log);
    void setPassword(const string& pass);

public:
    // Constructor
    customer(string fullName, string login, string password);
    customer() = delete;                          
    customer(const customer&) = delete;           
    customer(customer&&) = delete;      
    // Assignment operators
    customer& operator=(const customer&) = delete;
    customer& operator=(customer&&) = delete;          
    // Destructor	
    ~customer();

    // --- Getters ---
    string getFullName() const;
    string getLogin() const;
    string getPassword() const;
    double getBankBalance() const;

    // --- Functions ---
    void cashIn(std::vector<int> cash, ATM &atm);
    void cashOut(int money, ATM &atm);

    // --- Friend ---
    friend void ATM::cashIn(std::vector<int> cash);
    friend void ATM::cashOut(int money);
};

#endif // CUSTOMER_HPP
