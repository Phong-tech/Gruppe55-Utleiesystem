/**
 *   Fil: KUNDER.CPP
 *
 *   Implementasjon av Kunder-klassen.
 */

#include "Kunder.h"
#include <iostream>

using namespace std;

Kunder::Kunder() {
    sisteNr = 0;
}

Kunder::~Kunder() {
    for (auto k : kundene)
        delete k;
    kundene.clear();
}

void Kunder::nyKunde() {
    Kunde* ny = new Kunde(++sisteNr);
    ny->lesData();

    auto it = kundene.begin();
    while (it != kundene.end() && (*it)->hentNr() < ny->hentNr())
        ++it;

    kundene.insert(it, ny);
    cout << "\nNy kunde opprettet med kundenr: " << sisteNr << "\n";
}

void Kunder::skrivAlle() const {
    if (kundene.empty()) {
        cout << "\nIngen kunder registrert.\n";
        return;
    }

    cout << "\nAlle kunder:\n";
    for (const auto k : kundene)
        k->skrivData();
}

void Kunder::skrivEn(int nr) const {
    Kunde* k = finnKunde(nr);

    if (k)
        k->skrivAlt();
    else
        cout << "\nFant ikke kunde nr. " << nr << ".\n";
}

Kunde* Kunder::finnKunde(int nr) const {
    for (auto k : kundene) {
        if (k->hentNr() == nr)
            return k;
    }
    return nullptr;
}

void Kunder::slettKunde(int nr) {
    for (auto it = kundene.begin(); it != kundene.end(); ++it) {
        if ((*it)->hentNr() == nr) {
            if ((*it)->harGjenstander()) {
                cout << "\nKunden har fortsatt laante gjenstander og kan ikke slettes.\n";
                return;
            }

            delete *it;
            kundene.erase(it);
            cout << "\nKunde nr. " << nr << " er slettet.\n";
            return;
        }
    }

    cout << "\nFant ikke kunde nr. " << nr << ".\n";
}

void Kunder::lesFraFil(ifstream& inn) {
    int antall = 0;

    inn >> sisteNr >> antall;

    for (int i = 0; i < antall; i++) {
        Kunde* ny = new Kunde(inn);

        auto it = kundene.begin();
        while (it != kundene.end() && (*it)->hentNr() < ny->hentNr())
            ++it;

        kundene.insert(it, ny);
    }
}

void Kunder::skrivTilFil(ofstream& ut) const {
    ut << sisteNr << '\n'
       << kundene.size() << '\n';

    for (const auto k : kundene)
        k->skrivTilFil(ut);
}
