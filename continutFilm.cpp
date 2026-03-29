#include <iostream>
#include <string>
#include "continutFilm.h"

continutFilm::continutFilm(std::string t, std::string a, int d, std::string rez, std::string fr, double r) 
    : continutMedia(t, a, d), rezolutie(rez), formatRatio(fr), rating(r) {}

void continutFilm::afisare() const {
    std::cout << "ID FILM: " << ID << "\n" << "Titlu: " << titlu << "\n"
                <<"Autor: " <<autor << "\n" << "Durata: " << durata << " secunde\n" << "Rezolutie: " << rezolutie << "\n" << "Format Ratio: " << formatRatio << "\n" << "Rating: " << rating << "\n";
}

continutFilm::continutFilm(const continutFilm& altul) 
    : continutMedia(altul), rezolutie(altul.rezolutie), formatRatio(altul.formatRatio), rating(altul.rating) {}

continutFilm& continutFilm::operator=(const continutFilm& altul) {
    if(this != &altul) {
        titlu = altul.titlu;
        autor = altul.autor;
        durata = altul.durata;
        rezolutie = altul.rezolutie;
        formatRatio = altul.formatRatio;
        rating = altul.rating;
    }
    return *this;
}

continutFilm::~continutFilm() {
    std::cout << "Fisierul film " << titlu << "a fost sters\n";
}