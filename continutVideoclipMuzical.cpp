#include <iostream>
#include <string>
#include "continutVideoclipMuzical.h"

VideoclipMuzical::VideoclipMuzical(const std::string& t, const std::string& a, int d, const std::string& g, int b, const std::string& rez, const std::string& fr, double r, const std::string& alb, const std::string& reg) 
    : continutMedia(t, a, d), continutMelodie(t, a, d, g, b, true), continutFilm(t, a, d, rez, fr, r), album(alb), regizor(reg) {}

VideoclipMuzical::VideoclipMuzical(const VideoclipMuzical& altul) 
    : continutMedia(altul), continutMelodie(altul), continutFilm(altul), 
      album(altul.album), regizor(altul.regizor) {}

VideoclipMuzical& VideoclipMuzical::operator=(const VideoclipMuzical& altul) {
    if(this != &altul) {
        continutMedia::operator=(altul);
        gen = altul.gen;
        bitrate = altul.bitrate;
        rezolutie = altul.rezolutie;
        formatRatio = altul.formatRatio;
        rating = altul.rating;
        album = altul.album;
        regizor = altul.regizor;
    }
    return *this;
}

VideoclipMuzical::~VideoclipMuzical() {
    std::cout << "Videoclipul muzical " << titlu << " a fost sters.\n";
}

void VideoclipMuzical::afisare() const {
    std::cout << "ID VIDEOCLIP MUZICAL: " << ID << "\n" << "Titlu: " << titlu << "\n"
                <<"Autor: " <<autor << "\n" << "Durata: " << durata << " secunde\n" << "Gen: " << gen << "\n" << "Bitrate: " << bitrate << " kbps\n"
                << "Are videoclip: " << (areVideoclip ? "Da" : "Nu") << "\n" 
                << "Rezolutie: " << rezolutie << "\n" << "Format Ratio: " << formatRatio << "\n" << "Rating: " << rating << "\n"
                << "Album: " << album << "\n" << "Regizor: " << regizor << "\n";
};