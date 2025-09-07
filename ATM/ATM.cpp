#include "ATM.hpp"
#include <iostream>

ATM::ATM() {
    ATMCash[1] = 0;
    ATMCash[5] = 0;
    ATMCash[10] = 0;
    ATMCash[20] = 0;
    ATMCash[50] = 0;
    ATMCash[100] = 0;
    sumOfMoney = 0;
}

void ATM::ATMloading() {
    ATMCash[1] = 200;
    ATMCash[5] = 100;
    ATMCash[10] = 50;
    ATMCash[20] = 50;
    ATMCash[50] = 20;
    ATMCash[100] = 10;
    sumOfMoney = 4200;
}

void ATM::cashIn(std::vector<int> cash) {
    for (auto i : cash) {
        ATMCash[i]++;
        sumOfMoney += i;
    }
}

void ATM::cashOut(int money) {
    if (sumOfMoney < money) {
        throw ATMExeption("ATM doesn't have enough money");
    }

    std::map<int, int, std::greater<int>> used;
    int remaining = money;

    for (auto it = ATMCash.rbegin(); it != ATMCash.rend(); ++it) {
        int denom = it->first;
        int count = it->second;

        int need = remaining / denom;
        if (need > 0) {
            int give = std::min(need, count);
            used[denom] = give;
            remaining -= give * denom;
        }
    }

    if (remaining > 0) {
        throw ATMExeption("ATM cannot dispense the exact amount with available denominations");
    }

    std::cout << "ATM gives you: " << std::endl;
    for (auto &u : used) {
        ATMCash[u.first] -= u.second;
        std::cout << u.second << " banknotes of " << u.first << std::endl;
    }

    sumOfMoney -= money;
}
