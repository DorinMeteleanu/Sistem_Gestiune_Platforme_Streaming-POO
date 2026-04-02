#pragma once
#include <iostream>
#include <string>

class Abonament {
private:
    static int generator_ID_Abonament;
    int idAbonament;
    std::string numeClient;
    std::string tipAbonament; 
    double pretLunar;
    int durataLuni;
public:
    Abonament(std::string nume, std::string tip, double pret, int durata);
    Abonament(const Abonament& altul);
    Abonament& operator=(const Abonament& altul);
    ~Abonament();
    void afisare() const;
    std::string getTipAbonament() const {return tipAbonament;}
};