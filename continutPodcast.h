#include "continutMelodie.h"
#include "continutFilm.h"
class Podcast : public continutMelodie, public continutFilm {
private:
    std::string subiect;
    std::string invitat;
public:
    Podcast(std::string t, std::string a, int d, std::string g, int b, bool av, std::string rez, std::string fr, double r, std::string s, std::string i);
    Podcast(const Podcast& altul);
    Podcast& operator=(const Podcast& altul);
    ~Podcast();
    void afisare() const override;
};