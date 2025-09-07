#ifndef MYEXEPTIONS_HPP
#define MYEXEPTIONS_HPP

#include <exception>
#include <string>

class InvalidBalanceException : public std::exception {
    std::string msg;
public:
    InvalidBalanceException(const std::string& m) : msg(m) {}
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

class AuthenticationException : public std::exception {
    std::string msg;
public:
    AuthenticationException(const std::string& m) : msg(m) {}
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

class ATMExeption : public std::exception {
    std::string msg;
public:
    ATMExeption(const std::string& m) : msg(m) {}
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

#endif //MYEXEPTIONS_HPP