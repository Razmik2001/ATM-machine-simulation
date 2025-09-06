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

bool ATM_interface::userExists(const Username& login) const {
    return users.find(login) != users.end();
}


bool ATM_interface::checkPassword(customer &user) {
    std::string password;

    while (!user.isBlocked) {
        std::cout << "Enter password: ";
        std::cin >> password;

        if (password != user.password) {
            user.wrongPass(); 
            if (user.isBlocked) {
                std::cout << "Your account is blocked.\n";
                return false;
            }
            std::cout << "Wrong password. Try again.\n";
        } else {
            return true; 
        }
    }

    return false; 
}


void ATM_interface::cashOut(const std::string& login) {
    if (!userExists(login)) {
        std::cout << "User doesn't exist.\n";
        return;
    }

    if (!checkPassword(user)) {
        return;
    }

    try {
        int amount;
        std::cout << "Set amount (it must be integer): ";
        std::cin >> amount;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::invalid_argument("Input is not an integer!");
        }

        us.cashOut(amount);
        std::cout << "Withdrawal successful.\n";
    } catch (const std::exception &e) {
        std::cout << "Withdrawal failed: " << e.what() << "\n";
    }
}

void ATM_interface::cashIN(const std::string& login) {
    if (!userExists(login)) {
        std::cout << "User doesn't exist.\n";
        return;
    }

    customer &user = users[login];

    if (!checkPassword(user)) {
        return; // пользователь заблокирован
    }

    std::vector<int> cash;
    int choice = 0;

    std::cout << "Enter banknotes to deposit (100, 50, 20, 10, 5, 1).\n";
    std::cout << "Enter 0 to finish.\n";

    while (true) {
        std::cout << "Choose banknote: ";
        std::cin >> choice;

        if (std::cin.fail()) { // проверка на нечисловой ввод
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 0) break; // завершение ввода

        switch (choice) {
            case 100:
            case 50:
            case 20:
            case 10:
            case 5:
            case 1:
                cash.push_back(choice);
                break;
            default:
                std::cout << "Invalid banknote. Try again.\n";
                break;
        }
    }

    try {
        user.cashIn(cash);
        std::cout << "Deposit successful.\n";
    } catch (const std::exception &e) {
        std::cout << "Deposit failed: " << e.what() << "\n";
    }
}
