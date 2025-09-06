#ifndef ATM_INTERFACE
#define ATM_INTERFACE

#include <iostream>
#include <map>
#include <string>
#include "../customer/customer.hpp"
#include "ATM.hpp" // подключаем класс ATM

using std::string;

class ATM_interface {
    std::map<string, customer> users;
    ATM atm; 
public:
    ATM_interface() {
        atm.ATMloading();
    }

    void addUserFromConsole();
    bool userExists(const string& login) const;
    void cashOut(string login);
    void cashIn(string login);
    bool checkPassword(customer &user)
};

#endif // ATM_INTERFACE
