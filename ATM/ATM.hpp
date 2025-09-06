#ifndef ATM_HPP
#define ATM_HPP
#include <map>
#include <vector>
#include "../exeptions/MyExeptions.hpp"

using std::map;

class ATM {
    map<int,int> ATMCash;
    int sumOfMoney = 0;
public:
    // Constructor
    ATM();              
    ATM(const ATM&) = delete;         
    ATM(ATM&&) = delete;              
    ATM& operator=(const ATM&) = delete;
    ATM& operator=(ATM&&) = delete;

    // Destructor
    ~ATM() = default;                 
    void ATMloading();

    // --- Functions ---
    void cashIn(std::vector<int> cash);
    void cashOut(int money);
};


#endif // ATM_HPP