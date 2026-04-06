#pragma once
#include <iostream>
#include <string>

class Abonament {
protected:
    static int generator_ID_Abonament;
    int idAbonament;
    std::string numeClient;
    std::string tipAbonament; 
    double pretLunar;
    int durataLuni;
public:
    Abonament(const std::string& nume, const std::string& tip, double pret, int durata);
    Abonament(const Abonament& altul);
    Abonament& operator=(const Abonament& altul);
    virtual ~Abonament();
    virtual void afisare() const = 0;
    virtual int getNumarEcrane() const = 0;
};