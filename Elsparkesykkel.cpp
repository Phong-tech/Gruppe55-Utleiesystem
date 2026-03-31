/**
 *   Fil: ELSPARKESYKKEL.CPP
 *
 *   Implementasjon av Elsparkesykkel-klassen.
 */

#include "Elsparkesykkel.h"
#include "Conster.h"
#include "LesData3.h"
#include <iostream>

using namespace std;

Elsparkesykkel::Elsparkesykkel(int nr) : Gjenstand(nr, ELSPARKESYKKEL) {
    watt = STANDARD_WATT;
}

Elsparkesykkel::Elsparkesykkel(ifstream& inn) : Gjenstand(inn, ELSPARKESYKKEL) {
    inn >> watt;
}

int Elsparkesykkel::beregnPris() const {
    return (watt == HOEY_WATT) ? PRIS_ELSPARKESYKKEL_200W
                               : PRIS_ELSPARKESYKKEL_100W;
}

void Elsparkesykkel::lesData() {
    char svar = lesChar("Hoy effekt 200W (J/N)");
    watt = (svar == 'J') ? HOEY_WATT : STANDARD_WATT;
}

void Elsparkesykkel::skrivData() const {
    Gjenstand::skrivData();
    cout << " (" << watt << "W)";
}

void Elsparkesykkel::skrivTilFil(ofstream& ut) const {
    ut << "E\n";
    Gjenstand::skrivTilFil(ut);
    ut << watt << '\n';
}

void Elsparkesykkel::nullstill() {
    watt = STANDARD_WATT;
}
