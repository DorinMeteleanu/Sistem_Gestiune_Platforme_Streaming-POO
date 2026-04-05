#include "abonament.h"
class AbonamentStandard : public Abonament {
public:
    AbonamentStandard(const std::string& nume, double pret, int durata) 
        : Abonament(nume, "Standard", pret, durata) {}
    void afisare() const override {
        std::cout << "[Abonament STANDARD] ID: " << idAbonament 
                  << " | Client: " << numeClient << " | Pret: " << pretLunar << " RON\n";
    }
};