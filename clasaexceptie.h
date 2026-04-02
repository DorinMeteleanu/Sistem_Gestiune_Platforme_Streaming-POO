#pragma once
#include <exception>
#include <string>

class ExceptiePlatforma : public std::exception {
private:
    std::string mesaj;
public:
    ExceptiePlatforma(const std::string& msg) : mesaj(msg) {}

    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};