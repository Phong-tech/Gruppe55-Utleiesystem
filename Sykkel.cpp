/**
 *   Fil: SYKKEL.CPP
 *
 *   Implementasjon av Sykkel-klassen.
 */

#include "Sykkel.h"
#include "Conster.h"
#include "LesData3.h"
#include <iostream>

using namespace std;

Sykkel::Sykkel(int nr) : Gjenstand(nr, SYKKEL) {
    harTilhenger = false;
}

Sykkel::Sykkel(ifstream& inn) : Gjenstand(inn, SYKKEL) {
    inn >> harTilhenger;
}

int Sykkel::beregnPris() const {
    return harTilhenger ? PRIS_SYKKEL_MED_TILHENGER : PRIS_SYKKEL;
}

void Sykkel::lesData() {
    char svar = lesChar("Har tilhenger (J/N)");
    harTilhenger = (svar == 'J');
}

void Sykkel::skrivData() const {
    Gjenstand::skrivData();
    if (harTilhenger)
        cout << " (med tilhenger)";
}

void Sykkel::skrivTilFil(ofstream& ut) const {
    ut << "S\n";
    Gjenstand::skrivTilFil(ut);
    ut << harTilhenger << '\n';
}

void Sykkel::nullstill() {
    harTilhenger = false;
}
