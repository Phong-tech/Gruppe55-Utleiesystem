/**
 *   Fil: SYKKEL.H
 *
 *   Sykkel - subklasse av Gjenstand.
 */

#ifndef SYKKEL_H
#define SYKKEL_H

#include <fstream>
#include "Gjenstand.h"

class Sykkel : public Gjenstand {
private:
    bool harTilhenger;

public:
    Sykkel(int nr);
    Sykkel(std::ifstream& inn);

    int beregnPris() const override;
    void lesData() override;
    void skrivData() const override;
    void skrivTilFil(std::ofstream& ut) const override;
    void nullstill() override;
};

#endif
