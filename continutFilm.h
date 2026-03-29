#include "continutMedia.h"
class continutFilm : virtual public continutMedia {
protected:
    std::string rezolutie;
    std::string formatRatio;
    double rating;
public:
    continutFilm(std::string t, std::string a, int d, std::string rez, std::string fr, double r);
    continutFilm(const continutFilm& altul);
    continutFilm& operator=(const continutFilm& altul);
    ~continutFilm();
    void afisare() const override;

};