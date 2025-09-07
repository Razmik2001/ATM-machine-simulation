#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>
#include "../ATM/ATM.hpp"

using std::string;

class customer {
    string fullName;
    string login;
    string password;
    double bankBalance;
    int wrongPassAttempts = 3;

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
    
    // --- Setters ---
    void setLogin(const string& log);
    void setPassword(const string& pass);

    // --- Getters ---
    string getFullName() const;
    string getLogin() const;
    string getPassword() const;
    double getBankBalance() const;
    bool isBlocked(){
        return wrongPassAttempts == 0;
    }

    // --- Functions ---
    void cashIn(std::vector<int> cash, ATM &atm);
    void cashOut(int money, ATM &atm);
    void wrongPass(){wrongPassAttempts--;}
    void resetInputAttempts();
};

#endif // CUSTOMER_HPP
