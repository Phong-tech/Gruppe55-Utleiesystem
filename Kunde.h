/**
 *   Fil: KUNDE.H
 *
 *   Kunde-klassen.
 */

#ifndef KUNDE_H
#define KUNDE_H

#include <vector>
#include <string>
#include <fstream>

class Gjenstand;

class Kunde {
private:
    int kundeNr;
    int mobil;
    std::string navn;
    std::vector<Gjenstand*> gjenstandene;

public:
    Kunde(int nr);
    Kunde(std::ifstream& inn);
    ~Kunde();

    int hentNr() const;
    bool harGjenstander() const;

    void lesData();
    void skrivData() const;
    void skrivAlt() const;
    void skrivTilFil(std::ofstream& ut) const;

    void leggTilGjenstand(Gjenstand* g);
    void leverAlleGjenstander(std::vector<Gjenstand*>& gjenstander);
};

#endif
