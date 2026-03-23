# Gruppe55 - Utleiesystem for Fornøyelsespark

## 📋 Prosjektbeskrivelse
OOP-prosjekt våren 2026: System for utleie av gjenstander (traller, sykler, elsparkesykler) i en fornøyelsespark.

## Gruppemedlemmer
- Phong Nguyen - phong@student.ntnu.no - 134599

## 📁 Filstruktur

### Header-filer (.h):
1. `Conster.h` - Alle konstanter (priser, filnavn, etc.)
2. `Enums.h` - Enum for GjenstandType
3. `Funksjoner.h` - Deklarasjoner av globale funksjoner
4. `Gjenstand.h` - Baseklasse Gjenstand
5. `Tralle.h` - Subklasse Tralle
6. `Sykkel.h` - Subklasse Sykkel  
7. `Elsparkesykkel.h` - Subklasse Elsparkesykkel
8. `Kunde.h` - Klasse Kunde
9. `Kunder.h` - Klasse Kunder (container)
10. `Sted.h` - Klasse Sted
11. `Utleiesteder.h` - Klasse Utleiesteder (container)
12. `LesData3.h` - Hjelpefunksjoner for input

### Implementasjonsfiler (.cpp):
1. `main.cpp` - Hovedprogram med main()
2. `Funksjoner.cpp` - Implementasjon av globale funksjoner
3. `Gjenstand.cpp` - Implementasjon av Gjenstand
4. `Tralle.cpp` - Implementasjon av Tralle
5. `Sykkel.cpp` - Implementasjon av Sykkel
6. `Elsparkesykkel.cpp` - Implementasjon av Elsparkesykkel
7. `Kunde.cpp` - Implementasjon av Kunde
8. `Kunder.cpp` - Implementasjon av Kunder
9. `Sted.cpp` - Implementasjon av Sted
10. `Utleiesteder.cpp` - Implementasjon av Utleiesteder
11. `LesData3.cpp` - Implementasjon av hjelpefunksjoner

### Datafiler:
- `KUNDER.DTA` - Lagring av kundedata
- `STEDER.DTA` - Lagring av steddata

## Kompilering

### Windows (MinGW):
```bash
g++ -o prosjekt main.cpp Funksjoner.cpp Gjenstand.cpp Tralle.cpp Sykkel.cpp Elsparkesykkel.cpp Kunde.cpp Kunder.cpp Sted.cpp Utleiesteder.cpp LesData3.cpp -std=c++11
prosjekt.exe
```

### Mac/Linux:
```bash
g++ -o prosjekt main.cpp Funksjoner.cpp Gjenstand.cpp Tralle.cpp Sykkel.cpp Elsparkesykkel.cpp Kunde.cpp Kunder.cpp Sted.cpp Utleiesteder.cpp LesData3.cpp -std=c++11
./prosjekt
```

### Med Makefile:
```bash
make
./prosjekt
```

## Kommandoer

### Kunde-kommandoer:
- `K N` - Ny kunde
- `K A` - Alle kunder
- `K 1 <knr>` - Skriv kunde
- `K H <knr>` - Hente gjenstander
- `K L <knr>` - Levere gjenstander
- `K S <knr>` - Slett kunde

### Sted-kommandoer:
- `S N` - Nytt sted
- `S A` - Alle steder
- `S 1 <ID>` - Skriv sted
- `S T` - Tjent (inntjening)
- `S I` - Igjen (lager)
- `S O` - Overfør mellom steder
- `S S <ID>` - Slett sted

### Gjenstand-kommandoer:
- `G N` - Ny gjenstand
- `G F <gnr>` - Finn gjenstand
- `G S <gnr>` - Slett gjenstand

### System:
- `Q` - Quit (avslutt og lagre)

## Priser

| Gjenstand | Basispris | Med tillegg |
|-----------|-----------|-------------|
| Tralle | 50 kr | 75 kr (m/sele) |
| Sykkel | 100 kr | 150 kr (m/tilhenger) |
| Elsparkesykkel | 120 kr (100W) | 180 kr (200W) |

## Datastruktur

```
Kunder (global)
├── sisteNr: int
└── list<Kunde*> (sortert på kundenr)
    └── Kunde
        ├── kundeNr: int
        ├── navn: string
        ├── mobil: int
        └── vector<Gjenstand*> (usortert)

Utleiesteder (global)
├── sisteNr: int  
└── map<string, Sted*>
    └── Sted
        ├── stedID: string
        ├── beskrivelse: string
        ├── telefon: int
        ├── inntjent: int
        ├── vector<Tralle*>
        ├── vector<Sykkel*>
        └── vector<Elsparkesykkel*>
```

## Testdata

Programmet kommer med obligatoriske testdata:

### KUNDER.DTA:
- **Kunde 1 (Anne)**: 1 tralle, 1 sykkel, 1 elsparkesykkel
- **Kunde 2 (Bent)**: 2 traller, 2 sykler, 2 elsparkesykler

### STEDER.DTA:
- **Bod1**: 2 av hver type (6 gjenstander totalt)
- **Bod2**: 4 av hver type (12 gjenstander totalt)

## Tidsplan

- [x] Oppsett av repository
- [ ] Grunnleggende klasser (Gjenstand, Tralle, Sykkel, Elsparkesykkel)
- [ ] Kunde og Kunder
- [ ] Sted og Utleiesteder
- [ ] Globale funksjoner
- [ ] Fil I/O
- [ ] Testing
- [ ] Dokumentasjon
- [ ] Innlevering (7. april 2026 kl. 11:00)

## Viktig

- Alt må ligge i samme katalog på GitHub
- Lever SSH-adresse i Blackboard
- Test ved å clone til ny katalog
- Følg norske klassenavn (Gjenstand, ikke Item)

## Referanser

- Oppgavetekst: `prosjektV26.pdf`
- Datastruktur: `datastruktur.pdf`
- Testdata: `testdata.pdf`
- Sjekkliste: `sjekkliste.pdf`


