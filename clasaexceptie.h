#pragma once
#include <exception>
#include <string>

class ExceptiePlatforma : public std::exception {
private:
    std::string mesaj;
public:
    // Constructor care primeste mesajul de eroare
    ExceptiePlatforma(const std::string& msg) : mesaj(msg) {}

    // Suprascriem metoda what() din std::exception
    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};