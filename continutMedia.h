#pragma once
#include <iostream>
#include <string>

class continutMedia {
protected:
    static int generator_ID;
    std::string titlu;
    std::string autor;
    int ID;
    int durata; //durata va fi in secunde

public:
    continutMedia(const std::string& t, const std::string& a, int d);
    continutMedia(const continutMedia& altul);
    continutMedia& operator=(const continutMedia& altul);
    virtual ~continutMedia();
    virtual void afisare() const = 0; //polimorf. o sa pun pentru fiecare clasa copil functie personalzata de afisare
    virtual void redaContinut() const = 0; //polimorf.
    int getId() const { return ID; } 
};