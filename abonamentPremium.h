#include "Abonament.h"
class AbonamentPremium : public Abonament {
public:
    AbonamentPremium(std::string nume, double pret, int durata) 
        : Abonament(nume, "Premium", pret, durata) {}
    void afisare() const override {
        std::cout << "[Abonament PREMIUM] ID: " << idAbonament 
                  << " | Client: " << numeClient << " | Pret: " << pretLunar << " RON\n";
    }
};