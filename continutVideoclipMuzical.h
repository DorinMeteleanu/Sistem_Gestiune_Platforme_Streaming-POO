#pragma once
#include "continutMelodie.h"
#include "continutFilm.h"
class VideoclipMuzical : public continutMelodie, public continutFilm {
private:
    std::string album;
    std::string regizor;
public:
    VideoclipMuzical(const std::string& t, const std::string& a, int d, const std::string& g, int b, const std::string& rez, const std::string& fr, double r, const std::string& alb, const std::string& reg);
    VideoclipMuzical(const VideoclipMuzical& altul);
    VideoclipMuzical& operator=(const VideoclipMuzical& altul);
    ~VideoclipMuzical();
    void afisare() const override;
};