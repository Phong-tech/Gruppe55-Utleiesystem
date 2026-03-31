/**
 *   Fil: TRALLE.CPP
 *
 *   Implementasjon av Tralle-klassen.
 */

#include "Tralle.h"
#include "Conster.h"
#include "LesData3.h"
#include <iostream>

using namespace std;

Tralle::Tralle(int nr) : Gjenstand(nr, TRALLE) {
    harSele = false;
}

Tralle::Tralle(ifstream& inn) : Gjenstand(inn, TRALLE) {
    inn >> harSele;
}

int Tralle::beregnPris() const {
    return harSele ? PRIS_TRALLE_MED_SELE : PRIS_TRALLE;
}

void Tralle::lesData() {
    char svar = lesChar("Har sele (J/N)");
    harSele = (svar == 'J');
}

void Tralle::skrivData() const {
    Gjenstand::skrivData();
    if (harSele)
        cout << " (med sele)";
}

void Tralle::skrivTilFil(ofstream& ut) const {
    ut << "T\n";
    Gjenstand::skrivTilFil(ut);
    ut << harSele << '\n';
}

void Tralle::nullstill() {
    harSele = false;
}
