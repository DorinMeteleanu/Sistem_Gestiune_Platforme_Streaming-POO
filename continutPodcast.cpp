#include <iostream>
#include <string>
#include "continutPodcast.h"

Podcast::Podcast(std::string t, std::string a, int d, std::string g, int b, bool av, std::string rez, std::string fr, double r, std::string s, std::string i) 
    : continutMedia(t, a, d), continutMelodie(t, a, d, g, b, av), continutFilm(t, a, d, rez, fr, r), subiect(s), invitat(i) {};

void Podcast::afisare() const {
    std::cout << "ID PODCAST: " << ID << "\n" << "Titlu: " << titlu << "\n"
                <<"Autor: " <<autor << "\n" << "Durata: " << durata << " secunde\n" << "Gen: " << gen << "\n" << "Bitrate: " << bitrate << " kbps\n"
                << "Are videoclip: " << (areVideoclip ? "Da" : "Nu") << "\n" 
                << "Rezolutie: " << rezolutie << "\n" << "Format Ratio: " << formatRatio << "\n" << "Rating: " << rating << "\n"
                << "Subiect: " << subiect << "\n" << "Invitat: " << invitat << "\n";
};