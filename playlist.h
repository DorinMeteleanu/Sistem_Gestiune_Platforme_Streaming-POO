#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "continutMedia.h"

class Playlist {
private:
    std::string numePlaylist;
    std::vector<continutMedia*> listaContinut;

public:
    Playlist(const std::string& nume);
    Playlist(const Playlist& altul);
    Playlist& operator=(const Playlist& altul);
    ~Playlist();

    void adaugaInPlaylist(continutMedia* cont);
    void afisarePlaylist() const;
};