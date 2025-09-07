
#include "ATM_interface.hpp"
#include <limits>
#include <vector>
#include <stdexcept>
#include <string>

using std::string;

void ATM_interface::addUserFromConsole() {
    std::string fullName, login, password;

    std::cout << "Set full name: ";
    std::getline(std::cin, fullName);

    while (true) {
        std::cout << "Set login: ";
        std::getline(std::cin, login);

        if (userExists(login)) {
            std::cout << "User already exists. Try another login.\n";
        } else {
            break; 
        }
    }

    std::cout << "Set password: ";
    std::getline(std::cin, password);

    customer c(fullName, login, password);

    users[login] = c;

    std::cout << "User added successfully.\n";
}

ATM_interface::ATM_interface() {
    atm.ATMloading();
}

customer* ATM_interface::authUser(const string& login) {
    auto it = users.find(login);
    if (it == users.end()) {
        std::cout << "User doesn't exist.\n";
        return nullptr;
    }

    customer &user = it->second;
    std::string password;

    while (!user.isBlocked()) {
        std::cout << "Enter password: ";
        std::cin >> password;

        if (password != user.getPassword()) {
            user.wrongPass();
            if (user.isBlocked()) {
                std::cout << "Your account is blocked.\n";
                return nullptr;
            }
            std::cout << "Wrong password. Try again.\n";
        } else {
            return &user;
        }
    }
    return nullptr;
}

void ATM_interface::cashOut(customer &user) {
    try {
        int amount;
        std::cout << "Set amount (it must be integer): ";
        std::cin >> amount;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::invalid_argument("Input is not an integer!");
        }

        user->cashOut(amount, atm);
        std::cout << "Withdrawal successful.\n";
    } catch (const std::exception &e) {
        std::cout << "Withdrawal failed: " << e.what() << "\n";
    }
}

void ATM_interface::cashIn(customer &user) {
    std::vector<int> cash;
    int choice = 0;

    std::cout << "Enter banknotes to deposit (100, 50, 20, 10, 5, 1).\n";
    std::cout << "Enter 0 to finish.\n";

    while (true) {
        std::cout << "Choose banknote: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 0) break;

        switch (choice) {
            case 100: case 50: case 20:
            case 10: case 5: case 1:
                cash.push_back(choice);
                break;
            default:
                std::cout << "Invalid banknote. Try again.\n";
                break;
        }
    }

    try {
        user->cashIn(cash, atm);
        std::cout << "Deposit successful.\n";
    } catch (const std::exception &e) {
        std::cout << "Deposit failed: " << e.what() << "\n";
    }
}


void ATM_interface::start(){
    while(true){
        string username;
        std::cout << "write your username : ";
        std::cin >> username
        customer user = authUser(username) 
        if (user == nullptr){
            std::cout << "user dont exist" << std::endl;
            continue;
        }
        int choice;
         std::cout << "What do you want to do?\n"
                     "1: Check balance\n"
                     "2: Cash in\n"
                     "3: Cash out\n"
                     "4: Change login\n"
                     "5: Change password\n"
                     "6: Reset input attempts\n"
                     "7: choice another user\n"
                     "else: exit"
        std::cin >> choice
        switch(choice){
        case 1:{
            user.getBankBalance();
            break
        }
        case 2:{
            cashIn(user);
            break
        }
        case 3:{
            cashOut(user):
            break
        }
        case 4: {
            std::string newLogin;
            std::cout << "Set new login: ";
            std::cin >> newLogin;

            if (users.find(newLogin) != users.end()) {
                std::cout << "This login is already taken.\n";
                break;
            }

            std::string oldLogin = user->getLogin();

            user->setLogin(newLogin);

            users[newLogin] = *user;
            users.erase(oldLogin);

            std::cout << "Login changed successfully.\n";
            break;
        }

        case 5:{
            std::cout << "Set new password : "
            std::cin >> username;
            user.setLogin(username);
            break
        }

        case 6:{
            user.resetInputAttempts();
            break;
        }
        case 7:{
            continue;
            break;
        }
        default:
            std::cout << "thenk you dor using our ATM"    }
}
}