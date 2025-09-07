#include <iostream>
#include <vector>
#include "customer/customer.hpp"

int main() {
    ATM atm;
    atm.ATMloading(); // загружаем банкомат

    std::cout << "Initial ATM state loaded.\n";

    // Пользователи
    std::vector<std::vector<int>> userCashIn = {
        {100, 50, 20},    // User 1
        {10, 10, 5, 1},   // User 2
        {100, 100, 50}    // User 3
    };

    std::vector<int> userCashOut = {
        15000,  // User 1
        25,   // User 2
        250   // User 3
    };

    // Cash In
    for (int i = 0; i < 3; i++) {
        std::cout << "User " << i + 1 << " deposits: ";
        for (auto c : userCashIn[i]) std::cout << c << " ";
        std::cout << "\n";
        atm.cashIn(userCashIn[i]);
    }

    // Cash Out
    for (int i = 0; i < 3; i++) {
        std::cout << "User " << i + 1 << " tries to withdraw " << userCashOut[i] << "\n";
        try {
            atm.cashOut(userCashOut[i]);
            std::cout << "Withdrawal successful.\n";
        } catch (const std::exception &e) {
            std::cout << "Withdrawal failed: " << e.what() << "\n";
        }
    }

    return 0;
}
