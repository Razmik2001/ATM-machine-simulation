#include "ATM.hpp"


ATM::ATM(){
    map[1] = 0;
    map[5] = 0;
    map[10] = 0;
    map[20] = 0;
    map[50] = 0;
    map[100] = 0;
    sumOfMoney = 0;
}


void ATM::ATMloading(){
    map[1] = 200;
    map[5] = 100;
    map[10] = 50;
    map[20] = 50;
    map[50] = 20;
    map[100] = 10;
    sumOfMoney = 4200;
}

void ATM::cashIn(std::vector<int> cash){
    for(auto i:cash){
        map[i]++;
        sumOfMoney += i;
    }
}


void ATM::cashOut(int money){
    if (sumOfMoney < money)
    {
        throw ATMExeption("ATM dosen`t have enoghe money");
    }

    std::map<int, int, std::greater<int>> used;
    int remaining = money;

    for (auto it = map.rbegin(); it != map.rend(); ++it) {
        int denom = it->first;
        int count = it->second;

        int need = remaining / denom;
        if (need > 0) {
            int give = std::min(need, count);
            used[denom] = give;
            remaining -= give * denom;
        }
    }
    for (auto &u : used) {
        map[u.first] -= u.second;
    }
    sumOfMoney -= money;
}