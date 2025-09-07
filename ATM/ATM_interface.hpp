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

    string addUserFromConsole();

    customer* authUser(const string& login);

    void cashOut(customer &user);
    void cashIn(customer &user);
    void start();
};

#endif // ATM_INTERFACE_HPP
