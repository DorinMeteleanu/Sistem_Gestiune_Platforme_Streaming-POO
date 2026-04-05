#include "utilizator.h"

Utilizator::Utilizator(const std::string& n, Abonament* ab) : nume(n), abonamentCurent(ab) {}

Utilizator::Utilizator(const Utilizator& altul) : nume(altul.nume), abonamentCurent(altul.abonamentCurent), continutVizionat(altul.continutVizionat) {}

Utilizator& Utilizator::operator=(const Utilizator& altul) {
    if (this != &altul) {
        nume = altul.nume;
        abonamentCurent = altul.abonamentCurent; 
        continutVizionat = altul.continutVizionat; 
    }
    return *this;
}

Utilizator::~Utilizator() {
    if (abonamentCurent != nullptr) {
        delete abonamentCurent;
    }
    for(auto p : playlisturi) {
        delete p;
    }
    std::cout << "Utilizatorul " << nume << " a fost sters.\n";
}

void Utilizator::setAbonament(Abonament* abNou) {
    if (abonamentCurent != nullptr) {
        delete abonamentCurent;
    }
    abonamentCurent = abNou;
    std::cout << nume << " si-a actualizat abonamentul!\n";
}

void Utilizator::adaugaContinut(continutMedia* cont) {
    continutVizionat.push_back(cont);
    std::cout << nume << " a adaugat un nou continut vizionat: " << "\n";
}

void Utilizator::afisareDetalii() const {
    std::cout << "Nume Utilizator: " << nume << "\n";
    if (abonamentCurent) {
        std::cout << "Abonament Curent:\n";
        abonamentCurent->afisare();
    } else {
        std::cout << "Nu are abonament curent.\n";
    }
}
