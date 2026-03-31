/**
 *   Fil: GJENSTAND.CPP
 *
 *   Implementasjon av Gjenstand-klassen (baseklasse).
 */

#include "Gjenstand.h"
#include <iostream>

using namespace std;

Gjenstand::Gjenstand(int nr, GjenstandType t) {
    gjenstandsNr = nr;
    type = t;
}

Gjenstand::Gjenstand(std::ifstream& inn, GjenstandType t) {
    inn >> gjenstandsNr;
    type = t;
}

Gjenstand::~Gjenstand() {}

int Gjenstand::hentNr() const {
    return gjenstandsNr;
}

GjenstandType Gjenstand::hentType() const {
    return type;
}

void Gjenstand::skrivData() const {
    cout << "Gjenstand nr. " << gjenstandsNr;

    switch (type) {
        case TRALLE:
            cout << " (Tralle)";
            break;
        case SYKKEL:
            cout << " (Sykkel)";
            break;
        case ELSPARKESYKKEL:
            cout << " (Elsparkesykkel)";
            break;
        default:
            cout << " (Ukjent type)";
            break;
    }
}

void Gjenstand::skrivTilFil(std::ofstream& ut) const {
    ut << gjenstandsNr << '\n';
}
