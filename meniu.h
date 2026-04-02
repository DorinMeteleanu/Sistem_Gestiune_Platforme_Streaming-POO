#pragma once
#include "continutMedia.h"
#include "Utilizator.h"
#include <vector>

class Meniu {
private:
    std::vector<continutMedia*> continuturi;
    std::vector<Utilizator*> utilizatori;
    static int sesiuniActive;
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
    
};