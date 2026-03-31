/**
 *   Fil: KUNDE.CPP
 *
 *   Implementasjon av Kunde-klassen.
 */

#include "Kunde.h"
#include "Gjenstand.h"
#include "Tralle.h"
#include "Sykkel.h"
#include "Elsparkesykkel.h"
#include "LesData3.h"
#include <iostream>
#include <limits>

using namespace std;

Kunde::Kunde(int nr) {
    kundeNr = nr;
    mobil = 0;
    navn = "";
}

Kunde::Kunde(ifstream& inn) {
    char type;
    int antall;

    inn >> kundeNr >> mobil;
    inn.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(inn, navn);
    inn >> antall;

    for (int i = 0; i < antall; i++) {
        inn >> type;

        if (type == 'T')
            gjenstandene.push_back(new Tralle(inn));
        else if (type == 'S')
            gjenstandene.push_back(new Sykkel(inn));
        else if (type == 'E')
            gjenstandene.push_back(new Elsparkesykkel(inn));
    }
}

Kunde::~Kunde() {
    for (auto g : gjenstandene)
        delete g;
    gjenstandene.clear();
}

int Kunde::hentNr() const {
    return kundeNr;
}

bool Kunde::harGjenstander() const {
    return !gjenstandene.empty();
}

void Kunde::lesData() {
    cout << "Navn: ";
    cin >> ws;
    getline(cin, navn);
    mobil = lesInt("Mobilnummer", 10000000, 99999999);
}

void Kunde::skrivData() const {
    cout << "  Kunde nr. " << kundeNr << ": " << navn
         << " - " << gjenstandene.size() << " gjenstander\n";
}

void Kunde::skrivAlt() const {
    cout << "\nKunde nr. " << kundeNr << ":\n"
         << "  Navn: " << navn << "\n"
         << "  Mobil: " << mobil << "\n"
         << "  Antall gjenstander: " << gjenstandene.size() << "\n";

    if (!gjenstandene.empty()) {
        cout << "\n  Lante gjenstander:\n";
        for (const auto g : gjenstandene) {
            g->skrivData();
            cout << " - " << g->beregnPris() << " kr\n";
        }
    }
}

void Kunde::skrivTilFil(ofstream& ut) const {
    ut << kundeNr << '\n'
       << mobil << '\n'
       << navn << '\n'
       << gjenstandene.size() << '\n';

    for (const auto g : gjenstandene)
        g->skrivTilFil(ut);
}

void Kunde::leggTilGjenstand(Gjenstand* g) {
    gjenstandene.push_back(g);
}

void Kunde::leverAlleGjenstander(vector<Gjenstand*>& gjenstander) {
    for (auto g : gjenstandene) {
        g->nullstill();
        gjenstander.push_back(g);
    }
    gjenstandene.clear();
}
