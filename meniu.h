#pragma once
#include "continutMedia.h"
#include "utilizator.h"
#include "playlist.h"
#include <vector>

class Meniu {
private:
    std::vector<continutMedia*> continuturi;
    std::vector<Utilizator*> utilizatori;
    static int sesiuniActive;
    std::vector<Playlist*> playlisturiPlatforma;
public:
    Meniu();
    ~Meniu();
    static void afisareStatusPlatforma();
    void rulareMeniu();
    void adaugaContinut();
    void afiseazaContinut();
    void stergeContinut();
    void adaugaUtilizator();
    void stergeFisierDupaID();
    void afiseazaUtilizatori();
    void crearePlaylistPlatforma();
    void afiseazaPlaylisturiPlatforma();
    void modificaAbonamentUtilizator();
    
};