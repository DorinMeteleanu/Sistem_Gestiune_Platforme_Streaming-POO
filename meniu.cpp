#include <iostream>
#include "meniu.h"
#include "continutFilm.h"
#include "clasaexceptie.h"
#include "continutMelodie.h"
#include "continutVideoclipMuzical.h"
#include "abonament.h" 
#include "abonamentStandard.h"
#include "abonamentPremium.h"
#include "playlist.h"

int Meniu::sesiuniActive = 0;

Meniu::Meniu() {
    sesiuniActive++;
    std::cout << "Bine ati venit la platforma noastra de streaming! Sesiuni active: " << sesiuniActive << "\n";
}

Meniu::~Meniu() {
    sesiuniActive--;
    std::cout << "La revedere! Sesiuni active: " << sesiuniActive << "\n";
}

void Meniu::afisareStatusPlatforma() {
    std::cout << "Sesiuni active pe platforma: " << sesiuniActive << "\n";
}

void Meniu::rulareMeniu() {
    int optiune = 0;
    do {
        std::cout << "\n=== PANOU DE GESTIUNE PLATFORMA ===\n";
        std::cout << "--- Management Continut ---\n";
        std::cout << "1. Incarca Continut Nou pe Server\n";
        std::cout << "2. Vizualizeaza Baza de Date Continut\n";
        std::cout << "3. Sterge un anumit Fisier (dupa ID)\n";
        std::cout << "4. Sterge tot Continutul (Reset Server)\n";
        std::cout << "--- Management Clienti ---\n";
        std::cout << "5. Inregistreaza Utilizator Nou in Sistem\n";
        std::cout << "6. Vizualizeaza toti Clientii\n";
        std::cout << "--- Colectii Platforma (Playlisturi) ---\n";
        std::cout << "7. Creeaza un playlist\n"; 
        std::cout << "8. Afiseaza playlisturile platformei\n";
        std::cout << "0. Inchidere Platforma\n";
        std::cout << "===================================\n";
        std::cout << "Selecteaza o actiune de gestiune: ";
        if (!(std::cin >> optiune)) {
            break;
        }

        try {
            switch (optiune) {
                case 1:
                    adaugaContinut();
                    break;
                case 2:
                    afiseazaContinut();
                    break;
                case 3:
                    stergeFisierDupaID();
                    break;
                case 4:
                    stergeContinut();
                    break;
                case 5:
                    adaugaUtilizator();
                    break;
                case 6:
                    afiseazaUtilizatori();
                    break;
                case 7:
                    crearePlaylistPlatforma();
                    break;
                case 8:
                    afiseazaPlaylisturiPlatforma();
                    break;
                case 0:
                    std::cout << "Iesire din sistemul de gestiune...\n";
                    break;
                default:
                    std::cout << "Eroare: Comanda de gestiune invalida!\n";
            }
        } catch (const ExceptiePlatforma& e) {
            std::cout << "\n[ALERTA SISTEM]: " << e.what() << "\n";
        }

    } while (optiune != 0);
}

void Meniu::adaugaContinut() {
    std::cout << "\n--- INCARCARE CONTINUT NOU ---\n";
    std::cout << "Ce tip de continut doriti sa adaugati?\n";
    std::cout << "1. Film\n";
    std::cout << "2. Melodie\n";
    std::cout << "3. Videoclip Muzical (Fuziune Video-Audio)\n";
    std::cout << "Alegerea dvs: ";
    
    int tipContinut;
    std::cin >> tipContinut;
    std::string titlu, autor;
    int durata;
    
    std::cout << "\n[Detalii Generale]\n";
    std::cout << "Titlu: "; std::getline(std::cin >> std::ws, titlu);
    std::cout << "Autor/Artist: "; std::getline(std::cin >> std::ws, autor);
    std::cout << "Durata (secunde): "; std::cin >> durata;

    if(durata <= 0) {
        throw ExceptiePlatforma("Eroare: Durata trebuie sa fie pozitiva!");
    }

    continutMedia* fisierNou = nullptr;

    if (tipContinut == 1) {
        std::string formatRatio, calitate;
        double rating;
        std::cout << "\n[Detalii Video]\n";
        std::cout << "Format Ratio: "; std::getline(std::cin >> std::ws, formatRatio);
        std::cout << "Calitate: "; std::getline(std::cin >> std::ws, calitate);
        std::cout << "Rating: "; std::cin >> rating;
        
        fisierNou = new continutFilm(titlu, autor, durata, calitate, formatRatio, rating);
    } 
    else if (tipContinut == 2) {
        std::string genMuzical;
        int bitrate, areVideoOpt;
        bool areVideo;
        std::cout << "\n[Detalii Audio]\n";
        std::cout << "Gen Muzical: "; std::getline(std::cin >> std::ws, genMuzical);
        std::cout << "Bitrate Audio (ex: 320): "; std::cin >> bitrate;
        std::cout << "Are Videoclip? (1/0): "; std::cin >> areVideoOpt;
        areVideo = (areVideoOpt == 1); 
        fisierNou = new continutMelodie(titlu, autor, durata, genMuzical, bitrate, areVideo);
    }
    else if (tipContinut == 3) {
        std::string calitate, genMuzical, album, regizor, formatRatio;
        int bitrate;
        double rating;
        std::cout << "\n[Detalii Audio]\n";
        std::cout << "Gen Muzical: "; std::getline(std::cin >> std::ws, genMuzical);
        std::cout << "Bitrate Audio: "; std::cin >> bitrate;

        std::cout << "\n[Detalii Video]\n";
        std::cout << "Calitate: "; std::getline(std::cin >> std::ws, calitate);
        std::cout << "Format Ratio: "; std::getline(std::cin >> std::ws, formatRatio);
        std::cout << "Rating: "; std::cin >> rating;

        std::cout << "\n[Detalii Videoclip]\n";
        std::cout << "Album asociat: "; std::getline(std::cin >> std::ws, album);
        std::cout << "Regizor videoclip: "; std::getline(std::cin >> std::ws, regizor);
        
        fisierNou = new VideoclipMuzical(titlu, autor, durata, genMuzical, bitrate, calitate, formatRatio, rating, album, regizor);
    } 
    else {
        std::cout << "Eroare: Tip de continut invalid!\n";
        return; 
    }

    continuturi.push_back(fisierNou);
    std::cout << "\nSucces! Fisierul a fost incarcat pe server.\n";
}

void Meniu::afiseazaContinut() {
    if(continuturi.empty()) {
        std::cout << "Baza de date este goala.\n";
        return;
    }
    for(size_t i = 0; i < continuturi.size(); i++) {
        continuturi[i]->afisare(); 
        std::cout << "--------------------\n";
    }
}

void Meniu::stergeContinut() {
    for(auto cont : continuturi) {
        delete cont;
    }
    continuturi.clear();
    std::cout << "Tot continutul a fost sters.\n";
}

void Meniu::stergeFisierDupaID() {
    std::cout << "\n--- STERGE FISIER MEDIA ---\n";
    if (continuturi.empty()) {
        std::cout << "Baza de date este goala. Nu aveti ce sterge.\n";
        return;
    }

    int idCautat;
    std::cout << "Introduceti ID-ul fisierului pe care doriti sa-l stergeti: ";
    std::cin >> idCautat;

    bool gasit = false;
    
    for (auto it = continuturi.begin(); it != continuturi.end(); ++it) {
        if ((*it)->getId() == idCautat) { 
            delete *it;
            continuturi.erase(it); 
            gasit = true;
            break; 
        }
    }

    if (!gasit) {
        std::cout << "Eroare: Nu a fost gasit niciun fisier cu ID-ul " << idCautat << "!\n";
    }
}

void Meniu::adaugaUtilizator() {
    std::string nume;
    std::cout << "\n--- ADAUGARE CLIENT NOU ---\n";
    std::cout << "Introduceti numele noului client: ";
    std::getline(std::cin >> std::ws, nume);

    Utilizator* uNou = new Utilizator(nume);

    std::cout << "Ce tip de abonament doriti sa ii atribuiti?\n";
    std::cout << "1. Standard\n";
    std::cout << "2. Premium\n";
    std::cout << "3. Fara abonament\n";
    std::cout << "Alegerea dvs: ";
    
    int alegereAb;
    std::cin >> alegereAb;

    if (alegereAb == 1) {
        uNou->setAbonament(new AbonamentStandard(nume, 29.99, 1)); 
    } 
    else if (alegereAb == 2) {
        uNou->setAbonament(new AbonamentPremium(nume, 49.99, 1));
    }
    else {
        std::cout << "Clientul a fost inregistrat fara abonament momentan.\n";
    }

    utilizatori.push_back(uNou);
    
    std::cout << "\nClientul '" << nume << "' a fost inregistrat cu succes!\n";
}

void Meniu::afiseazaUtilizatori() {
    std::cout << "\n--- LISTA CLIENTI INREGISTRATI ---\n";
    if (utilizatori.empty()) {
        std::cout << "Nu exista clienti in sistem momentan.\n";
        return;
    }

    for (size_t i = 0; i < utilizatori.size(); i++) {
        std::cout << "Clientul " << i + 1 << ": " << utilizatori[i]->getNume() << "\n";
        utilizatori[i]->afisareDetalii(); 
        std::cout << "\n";
    }
    std::cout << "----------------------------------\n";
}

void Meniu::crearePlaylistPlatforma() {
    std::cout << "\n--- CREARE PLAYLIST --- \n";
    if (continuturi.empty()) {
        std::cout << "Eroare: Baza de date media este goala. Incarcati fisiere pe server mai intai.\n";
        return;
    }
    std::string numePlaylist;
    std::cout << "Numele noului Plyalist: ";
    std::getline(std::cin >> std::ws, numePlaylist);
    
    Playlist* playlistNou = new Playlist(numePlaylist);
    int idCautat;
    char continua;
    do {
        std::cout << "Introduceti ID-ul fisierului media pe care vreti sa il adaugati: ";
        std::cin >> idCautat;

        bool fisierGasit = false;
        for (auto cont : continuturi) {
            if (cont->getId() == idCautat) {
                playlistNou->adaugaInPlaylist(cont); // Sau cum se numeste metoda din Playlist.h
                std::cout << "Fisierul a fost adaugat cu succes in colectie!\n";
                fisierGasit = true;
                break;
            }
        }

        if (!fisierGasit) {
            std::cout << "Eroare: Fisierul cu ID-ul " << idCautat << " nu exista pe server.\n";
        }

        std::cout << "Mai adaugati fisiere in '" << numePlaylist << "'? (D/N): ";
        std::cin >> continua;
    } while (continua == 'D' || continua == 'd');

    playlisturiPlatforma.push_back(playlistNou);
    std::cout << "\nColectia '" << numePlaylist << "' a fost publicata pe platforma!\n";
}

void Meniu::afiseazaPlaylisturiPlatforma() {
    std::cout << "\n--- COLECTIILE PUBLICE ALE PLATFORMEI ---\n";
    if (playlisturiPlatforma.empty()) {
        std::cout << "Nu exista nicio colectie creata momentan.\n";
        return;
    }

    for (auto p : playlisturiPlatforma) {
        p->afisarePlaylist(); 
    }
}