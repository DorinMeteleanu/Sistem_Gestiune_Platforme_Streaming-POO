#pragma once
#include "continutMedia.h"
class continutMelodie : virtual public continutMedia {
protected:
    std::string gen;
    int bitrate;
    bool areVideoclip;
public:
    continutMelodie(const std::string& t, const std::string& a, int d, const std::string& g, int b, bool av);
    continutMelodie(const continutMelodie& altul);
    continutMelodie& operator=(const continutMelodie& altul);
    ~continutMelodie();
    void afisare() const override;
    void redaContinut() const override;

};