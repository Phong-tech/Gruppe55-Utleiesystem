/**
 *   Fil: UTLEIESTEDER.H
 *   
 *   Utleiesteder - container-klasse for alle steder.
 */

#ifndef __UTLEIESTEDER_H
#define __UTLEIESTEDER_H

#include <map>
#include <string>
#include <fstream>
#include "Sted.h"
#include "Enums.h"

using namespace std;

/**
 *  Utleiesteder (container med alle stedene).
 */
class Utleiesteder {
  private:
    int sisteNr;                    ///< Siste brukte gjenstandsnummer.
    map<string, Sted*> stedene;     ///< Alle stedene (map med sted-ID).
    
  public:
    Utleiesteder();
    ~Utleiesteder();
    
    int hentSisteNr() const;
    void okSisteNr();
    void nyttSted();
    void skrivAlle() const;
    void skrivEtt(const string& id) const;
    void skrivTjent() const;
    void skrivIgjen(GjenstandType type) const;
    void overfor();
    Sted* finnSted(const string& id) const;
    void slettSted(const string& id);
    void nyGjenstand();
    bool finnGjenstand(int gnr, string& stedID) const;
    bool slettGjenstand(int gnr);
    void lesFraFil(ifstream& inn);
    void skrivTilFil(ofstream& ut) const;
};

#endif

