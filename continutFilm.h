#pragma once
#include "continutMedia.h"
class continutFilm : virtual public continutMedia {
protected:
    std::string rezolutie;
    std::string formatRatio;
    double rating;
public:
    continutFilm(const std::string& t, const std::string& a, int d, const std::string& rez, const std::string& fr, double r);
    continutFilm(const continutFilm& altul);
    continutFilm& operator=(const continutFilm& altul);
    ~continutFilm();
    void afisare() const override;

};