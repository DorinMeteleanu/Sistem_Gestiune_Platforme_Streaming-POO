#include <iostream>
#include "Meniu.h"
#include "continutFilm.h"
#include "clasaexceptie.h"

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
    int optiune;
    do {
        std::cout << "\n=== PANOU DE GESTIUNE PLATFORMA ===\n";
        std::cout << "--- Management Continut ---\n";
        std::cout << "1. Incarca Continut Nou pe Server\n";
        std::cout << "2. Vizualizeaza Baza de Date Continut\n";
        std::cout << "3. Sterge tot Continutul (Reset Server)\n";
        std::cout << "--- Management Clienti ---\n";
        std::cout << "4. Inregistreaza Utilizator Nou in Sistem\n";
        std::cout << "0. Inchidere Platforma\n";
        std::cout << "===================================\n";
        std::cout << "Selecteaza o actiune de gestiune: ";
        std::cin >> optiune;

        try {
            switch (optiune) {
                case 1:
                    adaugaContinut();
                    break;
                case 2:
                    afiseazaContinut();
                    break;
                case 3:
                    stergeContinut();
                    break;
                case 4:
                    adaugaUtilizator();
                    break;
                case 0:
                    std::cout << "Se opresc serverele. Iesire din sistemul de gestiune...\n";
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
    std::cout << "Adauga continut nou (ex: melodie, film, podcast)...\n";
    std::string titlu, autor;
    int durata;
    
    std::cout << "Titlu film: "; std::cin >> titlu;
    std::cout << "Autor: "; std::cin >> autor;
    std::cout << "Durata (secunde): "; std::cin >> durata;

    if(durata <= 0) {
        throw ExceptiePlatforma("Eroare: Durata filmului trebuie sa fie pozitiva!");
    }

    continutMedia* filmNou = new continutFilm(titlu, autor, durata, "1080p", "16:9", 8.5);
    continuturi.push_back(filmNou);
    std::cout << "Film adaugat cu succes!\n";
}

void Meniu::afiseazaContinut() {
    if(continuturi.empty()) {
        std::cout << "Baza de date este goala.\n";
        return;
    }
    for(size_t i = 0; i < continuturi.size(); i++) {
        continuturi[i]->afisare(); // Aici intra in actiune polimorfismul!
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