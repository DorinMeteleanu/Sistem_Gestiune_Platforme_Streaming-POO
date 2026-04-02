#pragma once
#include "continutMedia.h"
class continutMelodie : virtual public continutMedia {
protected:
    std::string gen;
    int bitrate;
    bool areVideoclip;
public:
    continutMelodie(std::string t, std::string a, int d, std::string g, int b, bool av);
    continutMelodie(const continutMelodie& altul);
    continutMelodie& operator=(const continutMelodie& altul);
    ~continutMelodie();
    void afisare() const override;

};