/**
 *   Fil: GJENSTAND.H
 *
 *   Gjenstand (baseklasse).
 */

#ifndef GJENSTAND_H
#define GJENSTAND_H

#include <fstream>
#include "Enums.h"

class Gjenstand {
protected:
    int gjenstandsNr;
    GjenstandType type;

public:
    Gjenstand(int nr, GjenstandType t);
    Gjenstand(std::ifstream& inn, GjenstandType t);
    virtual ~Gjenstand();

    int hentNr() const;
    GjenstandType hentType() const;

    virtual int beregnPris() const = 0;
    virtual void lesData() = 0;
    virtual void skrivData() const;
    virtual void skrivTilFil(std::ofstream& ut) const;
    virtual void nullstill() = 0;
};

#endif
