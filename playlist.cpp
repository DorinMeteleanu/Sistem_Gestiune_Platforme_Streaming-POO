#include "playlist.h"

Playlist::Playlist(const std::string& nume) : numePlaylist(nume) {}

Playlist::Playlist(const Playlist& altul) : numePlaylist(altul.numePlaylist), listaContinut(altul.listaContinut) {}

Playlist& Playlist::operator=(const Playlist& altul) {
    if (this != &altul) {
        numePlaylist = altul.numePlaylist;
        listaContinut = altul.listaContinut;
    }
    return *this;
}

Playlist::~Playlist() {
    std::cout << "Playlistul " << numePlaylist << " a fost sters.\n";
}

void Playlist::adaugaInPlaylist(continutMedia* cont) {
    listaContinut.push_back(cont);
    std::cout << "Continut adaugat in playlistul " << numePlaylist << "!\n";
}

void Playlist::afisarePlaylist() const {
    std::cout << "Playlist: " << numePlaylist << "\n";
    for (const auto& cont : listaContinut) {
        cont->afisare();
        std::cout << "-------------------\n";
    }
}

