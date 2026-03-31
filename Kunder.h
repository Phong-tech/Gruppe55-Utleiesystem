/**
 *   Fil: KUNDER.H
 *
 *   Kunder - inneholder alle kundene i systemet.
 */

#ifndef KUNDER_H
#define KUNDER_H

#include <list>
#include <fstream>
#include "Kunde.h"

class Kunder {
private:
    int sisteNr;
    std::list<Kunde*> kundene;

public:
    Kunder();
    ~Kunder();

    void nyKunde();
    void skrivAlle() const;
    void skrivEn(int nr) const;
    Kunde* finnKunde(int nr) const;
    void slettKunde(int nr);
    void lesFraFil(std::ifstream& inn);
    void skrivTilFil(std::ofstream& ut) const;
};

#endif
