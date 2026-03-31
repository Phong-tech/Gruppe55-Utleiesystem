/**
 *   Fil: UTLEIESTEDER.CPP
 *
 *   Midlertidig implementasjon av Utleiesteder-klassen.
 */

#include "Utleiesteder.h"
#include "Sted.h"
#include <iostream>

using namespace std;

Utleiesteder::Utleiesteder() {}

Utleiesteder::~Utleiesteder() {}

void Utleiesteder::nyttSted() {
    cout << "\nnyttSted() er ikke ferdig implementert ennå.\n";
}

void Utleiesteder::skrivAlle() const {
    cout << "\nskrivAlle() for steder er ikke ferdig implementert ennå.\n";
}

void Utleiesteder::skrivEtt(const string& id) const {
    cout << "\nskrivEtt(" << id << ") er ikke ferdig implementert ennå.\n";
}

void Utleiesteder::skrivTjent() const {
    cout << "\nskrivTjent() er ikke ferdig implementert ennå.\n";
}

void Utleiesteder::skrivIgjen(GjenstandType) const {
    cout << "\nskrivIgjen() er ikke ferdig implementert ennå.\n";
}

void Utleiesteder::overfor() {
    cout << "\noverfor() er ikke ferdig implementert ennå.\n";
}

void Utleiesteder::slettSted(const string& id) {
    cout << "\nslettSted(" << id << ") er ikke ferdig implementert ennå.\n";
}

void Utleiesteder::nyGjenstand() {
    cout << "\nnyGjenstand() er ikke ferdig implementert ennå.\n";
}

bool Utleiesteder::finnGjenstand(int, string& stedID) const {
    stedID = "";
    return false;
}

bool Utleiesteder::slettGjenstand(int) {
    return false;
}

Sted* Utleiesteder::finnSted(const string&) const {
    return nullptr;
}

void Utleiesteder::lesFraFil(ifstream&) {
}

void Utleiesteder::skrivTilFil(ofstream&) const {
}
