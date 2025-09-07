#ifndef ATM_INTERFACE_HPP
#define ATM_INTERFACE_HPP

#include <iostream>
#include <map>
#include <string>
#include "../customer/customer.hpp"
#include "ATM.hpp"

using std::string;

class ATM_interface {
    std::map<string, customer> users;
    ATM atm; 
public:
    ATM_interface();

    void addUserFromConsole();

    // универсальная проверка пользователя
    customer* authUser(const string& login);

    void cashOut(const string& login);
    void cashIn(const string& login);
    void start();
};

#endif // ATM_INTERFACE_HPP
