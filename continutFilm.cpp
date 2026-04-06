#include <iostream>
#include <string>
#include "continutFilm.h"

continutFilm::continutFilm(const std::string& t, const std::string& a, int d, const std::string& rez, const std::string& fr, double r) 
    : continutMedia(t, a, d), rezolutie(rez), formatRatio(fr), rating(r) {}

void continutFilm::afisare() const {
    std::cout << "ID FILM: " << ID << "\n" << "Titlu: " << titlu << "\n"
                <<"Autor: " <<autor << "\n" << "Durata: " << durata << " secunde\n" << "Rezolutie: " << rezolutie << "\n" << "Format Ratio: " << formatRatio << "\n" << "Rating: " << rating << "\n";
}

void continutFilm::redaContinut() const {
    std::cout << "[PLAYER VIDEO] Rulare film: '" << titlu << "' la rezolutia " << rezolutie << "...\n";
}

int continutFilm::calculeazaNumarReclame() const {
    return durata / 1800; 
}

continutFilm::continutFilm(const continutFilm& altul) 
    : continutMedia(altul), rezolutie(altul.rezolutie), formatRatio(altul.formatRatio), rating(altul.rating) {}

continutFilm& continutFilm::operator=(const continutFilm& altul) {
    if(this != &altul) {
        continutMedia::operator=(altul);
        rezolutie = altul.rezolutie;
        formatRatio = altul.formatRatio;
        rating = altul.rating;
    }
    return *this;
}

continutFilm::~continutFilm() {
    std::cout << "Fisierul film " << titlu << "a fost sters\n";
}