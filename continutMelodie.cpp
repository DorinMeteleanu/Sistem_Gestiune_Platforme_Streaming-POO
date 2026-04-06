#include <iostream>
#include <string>
#include "continutMelodie.h"

continutMelodie::continutMelodie(const std::string& t, const std::string& a, int d, const std::string& g, int b, bool av) 
    : continutMedia(t, a, d), gen(g), bitrate(b), areVideoclip(av) {}

void continutMelodie::afisare() const {
    std::cout << "ID MELODIE: " << ID << "\n" << "Titlu: " << titlu << "\n"
                <<"Autor: " <<autor << "\n" << "Durata: " << durata << " secunde\n" << "Gen: " << gen << "\n" << "Bitrate: " << bitrate << " kbps\n"
                << "Are videoclip: " << (areVideoclip ? "Da" : "Nu") << "\n";
}

void continutMelodie::redaContinut() const {
    std::cout << "[PLAYER AUDIO] Redare melodie: '" << titlu << "' la claritatea " << bitrate << " kbps" << ", autor" << autor << "...\n";
}

continutMelodie::continutMelodie(const continutMelodie& altul) 
    : continutMedia(altul), gen(altul.gen), bitrate(altul.bitrate), areVideoclip(altul.areVideoclip) {}

continutMelodie& continutMelodie::operator=(const continutMelodie& altul) {
    if(this != &altul) {
        continutMedia::operator=(altul);
        gen = altul.gen;
        bitrate = altul.bitrate;
        areVideoclip = altul.areVideoclip;
    }
    return *this;
}

continutMelodie::~continutMelodie() {
    std::cout << "Fisierul audio " << titlu << " a fost sters\n";
}