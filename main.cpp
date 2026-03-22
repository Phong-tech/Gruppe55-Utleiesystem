/**
 *   Fil: MAIN.CPP
 *   
 *   Hovedprogram for utleiesystem i fornøyelsespark.
 *   
 *   @author  Phong Nguyen - Gruppe55
 */

#include <iostream>
#include "Conster.h"
#include "Enums.h"
#include "Funksjoner.h"
#include "Kunder.h"
#include "Utleiesteder.h"
#include "LesData3.h"

using namespace std;

Kunder gKundene;              ///< ALLE kundene.
Utleiesteder gUtleiestedene;  ///< ALLE utleiestedene.

/**
 *  Hovedprogrammet.
 */
int main() {
    char kommando1, kommando2;
    
    lesFraFil();  // Leser inn datastrukturen fra fil
    
    skrivMeny();
    kommando1 = lesChar("\nKommando");
    
    while (kommando1 != 'Q') {
        switch (kommando1) {
            case 'K':  // KUNDE-kommandoer
                kommando2 = lesChar("Underkommando (N/A/1/H/L/S)");
                switch (kommando2) {
                    case 'N': kundeNy();         break;
                    case 'A': kundeAlle();       break;
                    case '1': kundeSkrivEn();    break;
                    case 'H': kundeHente();      break;
                    case 'L': kundeLever();      break;
                    case 'S': kundeSlett();      break;
                    default:  cout << "\nUgyldig underkommando!\n"; break;
                }
                break;
                
            case 'S':  // STED-kommandoer
                kommando2 = lesChar("Underkommando (N/A/1/T/I/O/S)");
                switch (kommando2) {
                    case 'N': stedNytt();        break;
                    case 'A': stedAlle();        break;
                    case '1': stedSkrivEtt();    break;
                    case 'T': stedTjent();       break;
                    case 'I': stedIgjen();       break;
                    case 'O': stedOverfor();     break;
                    case 'S': stedSlett();       break;
                    default:  cout << "\nUgyldig underkommando!\n"; break;
                }
                break;
                
            case 'G':  // GJENSTAND-kommandoer
                kommando2 = lesChar("Underkommando (N/F/S)");
                switch (kommando2) {
                    case 'N': gjenstandNy();     break;
                    case 'F': gjenstandFinn();   break;
                    case 'S': gjenstandSlett();  break;
                    default:  cout << "\nUgyldig underkommando!\n"; break;
                }
                break;
                
            default:
                cout << "\nUgyldig kommando!\n";
                skrivMeny();
                break;
        }
        
        kommando1 = lesChar("\nKommando");
    }
    
    skrivTilFil();  // Skriver datastrukturen til fil
    
    cout << "\n\nHa en fortsatt fin dag!\n\n";
    
    return 0;
}
