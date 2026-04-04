#include <iostream>
#include <string>
#include "abonament.h"

int Abonament::generator_ID_Abonament = 1;

Abonament::Abonament(std::string nume, std::string tip, double pret, int durata) 
    : numeClient(nume), tipAbonament(tip), pretLunar(pret), durataLuni(durata) {
    generator_ID_Abonament++;
    idAbonament = generator_ID_Abonament;
}

Abonament::Abonament(const Abonament& altul) {
    numeClient = altul.numeClient;
    tipAbonament = altul.tipAbonament;
    pretLunar = altul.pretLunar;
    durataLuni = altul.durataLuni;
    generator_ID_Abonament++;
    idAbonament = generator_ID_Abonament;

}

Abonament& Abonament::operator=(const Abonament& altul) {
    if (this != &altul) {
        numeClient = altul.numeClient;
        tipAbonament = altul.tipAbonament;
        pretLunar = altul.pretLunar;
        durataLuni = altul.durataLuni;
    }
    return *this;
}

Abonament::~Abonament() {
    std::cout << "Abonamentul cu ID-ul " << idAbonament << " (" << numeClient << ") a fost sters.\n";
}

void Abonament::afisare() const {
    std::cout << "ID Abonament: " << idAbonament << "\nNume Client: " << numeClient << "\nTip Abonament: " << tipAbonament
              << "\nPret Lunar: " << pretLunar << "\nDurata (luni): " << durataLuni << "\n";
};
