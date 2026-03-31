/**
 *   Fil: TRALLE.H
 *
 *   Tralle - subklasse av Gjenstand.
 */

#ifndef TRALLE_H
#define TRALLE_H

#include <fstream>
#include "Gjenstand.h"

class Tralle : public Gjenstand {
private:
    bool harSele;

public:
    Tralle(int nr);
    Tralle(std::ifstream& inn);

    int beregnPris() const override;
    void lesData() override;
    void skrivData() const override;
    void skrivTilFil(std::ofstream& ut) const override;
    void nullstill() override;
};

#endif
