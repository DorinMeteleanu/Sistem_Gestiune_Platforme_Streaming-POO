#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Abonament.h"
#include "continutMedia.h"
#include "playlist.h"

class Utilizator {
private:
    std::string nume;
    Abonament* abonamentCurent;
    std::vector<continutMedia*> continutVizionat;
    std::vector<Playlist*> playlisturi;
public:
    Utilizator(std::string n, Abonament* ab = nullptr);
    Utilizator(const Utilizator& altul);
    Utilizator& operator=(const Utilizator& altul);
    ~Utilizator();

    void setAbonament(Abonament* abNou);
    void adaugaContinut(continutMedia* cont);
    void afisareDetalii() const;
    void adaugaPlaylistNou(Playlist* p);
};