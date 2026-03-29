#include <iostream>
#include <string>
#include "continutMedia.h"

int continutMedia::generator_ID = 0;

continutMedia::continutMedia(std::string t, std::string a, int d) : titlu(t), autor(a), durata(d) {
    generator_ID++;
    ID = generator_ID;

}

continutMedia::continutMedia(const continutMedia& altul) : titlu(altul.titlu), autor(altul.autor), durata(altul.durata){
    generator_ID++;
    ID = generator_ID;
}

continutMedia& continutMedia::operator=(const continutMedia& altul) {
    if(this != &altul) {
        titlu = altul.titlu;
        autor = altul.autor;
        durata = altul.durata;
    }
    return *this;
}

continutMedia::~continutMedia() {
    std::cout << "Fisierul " << titlu << "a fost sters\n";
}