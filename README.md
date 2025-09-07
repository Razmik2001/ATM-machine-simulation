# ATM Machine Simulation

This project simulates a simple ATM (Automated Teller Machine) system in C++.
It allows users to create accounts, authenticate, deposit and withdraw cash, and manage account information.

---

## Features

* User account creation and authentication
* Deposit cash with different denominations (100, 50, 20, 10, 5, 1)
* Withdraw cash with denomination handling
* Check account balance
* Change login and password
* Reset input attempts
* User blocking after 3 wrong password attempts

---

## Project Structure

```
ATM-machine-simulation/
├── ATM/
│   ├── ATM.hpp
│   ├── ATM.cpp
│   ├── ATM_interface.hpp
│   └── ATM_interface.cpp
├── customer/
│   ├── customer.hpp
│   └── customer.cpp
├── main.cpp
├── Makefile
└── README.md
```

* `ATM/` – contains the ATM class and the interface for interacting with the ATM.
* `customer/` – contains the Customer class representing a bank user.
* `main.cpp` – main program that starts the ATM simulation.
* `Makefile` – build instructions for compiling the project.

---

## Build & Run

### Prerequisites

* C++ compiler with C++11 support (e.g., g++)
* Linux or Windows environment

### Compilation

```bash
make
```

### Run

```bash
./ATM_test
```

---

## Usage Example

```
Do you need ATM? (y/n): y
Do you already have a user? (y/n): n
Set full name: John Doe
Set login: john123
Set password: 12345
User added successfully.

Enter your username: john123
Enter password: 12345

What do you want to do?
1: Check balance
2: Cash in
3: Cash out
4: Change login
5: Change password
6: Reset input attempts
7: Choose another user
Else: Exit
1
Balance: 0

What do you want to do?
1: Check balance
2: Cash in
3: Cash out
4: Change login
5: Change password
6: Reset input attempts
7: Choose another user
Else: Exit
2
Enter banknotes to deposit (100, 50, 20, 10, 5, 1).
Enter 0 to finish.
Choose banknote: 100
Choose banknote: 50
Choose banknote: 0
Deposit successful.

What do you want to do?
1: Check balance
2: Cash in
3: Cash out
4: Change login
5: Change password
6: Reset input attempts
7: Choose another user
Else: Exit
1
Balance: 150

What do you want to do?
1: Check balance
2: Cash in
3: Cash out
4: Change login
5: Change password
6: Reset input attempts
7: Choose another user
Else: Exit
3
Set amount (it must be integer): 120
Withdrawal successful.

Balance after withdrawal: 30

Thank you for using our ATM.
```

---

## Notes

* Users are blocked after 3 incorrect password attempts.
* The ATM only accepts integer cash amounts.
* Deposits and withdrawals handle standard denominations: 100, 50, 20, 10, 5, 1.
* Switching users allows multiple accounts to be managed in the same session.

---

## Author

**Razmik Grigoryan**
