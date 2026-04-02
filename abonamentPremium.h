#include "abonament.h"
class AbonamentPremium : public Abonament {
private:
    bool are4K;
    int nrDispozitiveConectate;
    std::string accesPremiere;
public:
    AbonamentPremium(std::string nume, double pret, int durata) 
        : Abonament(nume, "Premium", pret, durata), are4K(true), nrDispozitiveConectate(4), accesPremiere("Acces exclusiv la avanpremiere"){}
    void afisare() const override {
        std::cout << "[Abonament PREMIUM] ID: " << idAbonament 
                  << " | Client: " << numeClient << " | Pret: " << pretLunar << " RON\n" << "   -> Facilitati: Calitate 4K, " << nrDispozitiveConectate 
                  << " dispozitive, " << accesPremiere << "\n";
    }
};