/**
 *   Fil: ELSPARKESYKKEL.H
 *
 *   Elsparkesykkel - subklasse av Gjenstand.
 */

#ifndef ELSPARKESYKKEL_H
#define ELSPARKESYKKEL_H

#include <fstream>
#include "Gjenstand.h"

class Elsparkesykkel : public Gjenstand {
private:
    int watt;

public:
    Elsparkesykkel(int nr);
    Elsparkesykkel(std::ifstream& inn);

    int beregnPris() const override;
    void lesData() override;
    void skrivData() const override;
    void skrivTilFil(std::ofstream& ut) const override;
    void nullstill() override;
};

#endif
