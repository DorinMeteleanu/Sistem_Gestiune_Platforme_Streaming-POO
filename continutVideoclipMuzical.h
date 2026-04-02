#pragma once
#include "continutMelodie.h"
#include "continutFilm.h"
class VideoclipMuzical : public continutMelodie, public continutFilm {
private:
    std::string album;
    std::string regizor;
public:
    VideoclipMuzical(std::string t, std::string a, int d, std::string g, int b, std::string rez, std::string fr, double r, std::string alb, std::string reg);
    VideoclipMuzical(const VideoclipMuzical& altul);
    VideoclipMuzical& operator=(const VideoclipMuzical& altul);
    ~VideoclipMuzical();
    void afisare() const override;
};