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
    continutMedia(std::string t, std::string a, int d);
    continutMedia(const continutMedia& altul);
    continutMedia& operator=(const continutMedia& altul);
    ~continutMedia();
    virtual void afisare() = 0; //o sa pun pentru fiecare clasa copil functie personalzata de afisare 
};