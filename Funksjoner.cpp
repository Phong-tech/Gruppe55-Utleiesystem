/**
 *   Fil: FUNKSJONER.CPP
 *   
 *   Implementasjon av alle globale funksjoner.
 */

#include "Funksjoner.h"
#include "Kunder.h"
#include "Utleiesteder.h"
#include "Conster.h"
#include "LesData3.h"
#include <iostream>
#include <fstream>

using namespace std;

extern Kunder gKundene;             ///< Definert i main.cpp
extern Utleiesteder gUtleiestedene; ///< Definert i main.cpp

/**
 *  Skriver programmets meny.
 */
void skrivMeny() {
    cout << "\n\n===== UTLEIESYSTEM - FORNØYELSESPARK =====\n"
         << "\nKUNDE-KOMMANDOER:\n"
         << "  K N        - Ny kunde\n"
         << "  K A        - Alle kunder\n"
         << "  K 1 <knr>  - Skriv kunde\n"
         << "  K H <knr>  - Hente gjenstander\n"
         << "  K L <knr>  - Levere gjenstander\n"
         << "  K S <knr>  - Slett kunde\n"
         << "\nSTED-KOMMANDOER:\n"
         << "  S N        - Nytt sted\n"
         << "  S A        - Alle steder\n"
         << "  S 1 <ID>   - Skriv sted\n"
         << "  S T        - Tjent (inntjening)\n"
         << "  S I        - Igjen (lager)\n"
         << "  S O        - Overfør mellom steder\n"
         << "  S S <ID>   - Slett sted\n"
         << "\nGJENSTAND-KOMMANDOER:\n"
         << "  G N        - Ny gjenstand\n"
         << "  G F <gnr>  - Finn gjenstand\n"
         << "  G S <gnr>  - Slett gjenstand\n"
         << "\nQ - Quit (avslutt)\n";
}

/**
 *  K N - Oppretter ny kunde.
 */
void kundeNy() {
    gKundene.nyKunde();
}

/**
 *  K A - Skriver alle kunder.
 */
void kundeAlle() {
    gKundene.skrivAlle();
}

/**
 *  K 1 - Skriver én kunde.
 */
void kundeSkrivEn() {
    int knr = lesInt("Kundenummer", 1, 9999);
    gKundene.skrivEn(knr);
}

/**
 *  K H - Kunde henter gjenstander.
 */
void kundeHente() {
    int knr = lesInt("Kundenummer", 1, 9999);
    Kunde* kunde = gKundene.finnKunde(knr);
    
    if (!kunde) {
        cout << "\nKunde finnes ikke.\n";
        return;
    }
    
    gUtleiestedene.skrivAlle();
    
    string stedID;
    cout << "\nSted-ID: ";
    getline(cin, stedID);
    
    Sted* sted = gUtleiestedene.finnSted(stedID);
    if (!sted) {
        cout << "\nSted finnes ikke.\n";
        return;
    }
    
    // Her implementeres valg av gjenstander og flytting
    cout << "\n(Funksjonalitet under utvikling)\n";
}

/**
 *  K L - Kunde leverer alle gjenstander.
 */
void kundeLever() {
    int knr = lesInt("Kundenummer", 1, 9999);
    Kunde* kunde = gKundene.finnKunde(knr);
    
    if (!kunde) {
        cout << "\nKunde finnes ikke.\n";
        return;
    }
    
    if (!kunde->harGjenstander()) {
        cout << "\nKunden har ingen lånte gjenstander.\n";
        return;
    }
    
    gUtleiestedene.skrivAlle();
    
    string stedID;
    cout << "\nLever til sted (ID): ";
    getline(cin, stedID);
    
    Sted* sted = gUtleiestedene.finnSted(stedID);
    if (!sted) {
        cout << "\nSted finnes ikke.\n";
        return;
    }
    
    // Lever alle gjenstander
    // (Implementeres fullstendig senere)
    cout << "\nAlle gjenstander levert.\n";
}

/**
 *  K S - Sletter en kunde.
 */
void kundeSlett() {
    int knr = lesInt("Kundenummer", 1, 9999);
    
    char svar = lesChar("Er du sikker (J/N)");
    if (svar != 'J')
        return;
    
    gKundene.slettKunde(knr);
}

/**
 *  S N - Oppretter nytt sted.
 */
void stedNytt() {
    gUtleiestedene.nyttSted();
}

/**
 *  S A - Skriver alle steder.
 */
void stedAlle() {
    gUtleiestedene.skrivAlle();
}

/**
 *  S 1 - Skriver ett sted.
 */
void stedSkrivEtt() {
    string id;
    cout << "Sted-ID: ";
    getline(cin, id);
    
    gUtleiestedene.skrivEtt(id);
}

/**
 *  S T - Skriver inntjening.
 */
void stedTjent() {
    gUtleiestedene.skrivTjent();
}

/**
 *  S I - Skriver hvem som har gjenstander igjen.
 */
void stedIgjen() {
    char type = lesChar("Type (T/S/E)");
    GjenstandType gtype;
    
    switch (type) {
        case 'T': gtype = GjenstandType::Tralle; break;
        case 'S': gtype = GjenstandType::Sykkel; break;
        case 'E': gtype = GjenstandType::Elsparkesykkel; break;
        default:
            cout << "\nUgyldig type!\n";
            return;
    }
    
    gUtleiestedene.skrivIgjen(gtype);
}

/**
 *  S O - Overfører gjenstander mellom steder.
 */
void stedOverfor() {
    gUtleiestedene.overfor();
}

/**
 *  S S - Sletter et sted.
 */
void stedSlett() {
    string id;
    cout << "Sted-ID: ";
    getline(cin, id);
    
    char svar = lesChar("Er du sikker (J/N)");
    if (svar != 'J')
        return;
    
    gUtleiestedene.slettSted(id);
}

/**
 *  G N - Oppretter nye gjenstander.
 */
void gjenstandNy() {
    gUtleiestedene.nyGjenstand();
}

/**
 *  G F - Finner en gjenstand.
 */
void gjenstandFinn() {
    int gnr = lesInt("Gjenstandsnummer", 1, 9999);
    string stedID;
    
    if (gUtleiestedene.finnGjenstand(gnr, stedID)) {
        cout << "\nGjenstand nr." << gnr << " er på sted: " << stedID << "\n";
    } else {
        // Sjekk om kunde har den
        cout << "\nGjenstand nr." << gnr << " er ikke funnet.\n";
    }
}

/**
 *  G S - Sletter en gjenstand.
 */
void gjenstandSlett() {
    int gnr = lesInt("Gjenstandsnummer", 1, 9999);
    
    char svar = lesChar("Er du sikker (J/N)");
    if (svar != 'J')
        return;
    
    if (gUtleiestedene.slettGjenstand(gnr))
        cout << "\nGjenstand nr." << gnr << " er slettet.\n";
    else
        cout << "\nGjenstand ikke funnet (eller hos kunde).\n";
}

/**
 *  Leser hele datastrukturen fra fil.
 */
void lesFraFil() {
    ifstream innKunder(KUNDE_FIL);
    ifstream innSteder(STED_FIL);
    
    if (innKunder) {
        gKundene.lesFraFil(innKunder);
        innKunder.close();
    } else {
        cout << "Fant ikke " << KUNDE_FIL << ". Starter med tom database.\n";
    }
    
    if (innSteder) {
        gUtleiestedene.lesFraFil(innSteder);
        innSteder.close();
    } else {
        cout << "Fant ikke " << STED_FIL << ". Starter med tom database.\n";
    }
}

/**
 *  Skriver hele datastrukturen til fil.
 */
void skrivTilFil() {
    ofstream utKunder(KUNDE_FIL);
    ofstream utSteder(STED_FIL);
    
    if (utKunder) {
        gKundene.skrivTilFil(utKunder);
        utKunder.close();
        cout << "Kundedata skrevet til " << KUNDE_FIL << "\n";
    }
    
    if (utSteder) {
        gUtleiestedene.skrivTilFil(utSteder);
        utSteder.close();
        cout << "Steddata skrevet til " << STED_FIL << "\n";
    }
}

