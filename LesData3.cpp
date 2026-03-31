/**
 *   Enkel verktøykasse for å lese: tegn og tall.
 *
 *   @file     LesData3.CPP
 *   @author   Frode Haug, NTNU
 */

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include "LesData3.h"

char lesChar(const char* t) {
    char tegn;
    std::cout << t << ":  ";
    std::cin >> tegn;
    std::cin.ignore(MAXCHAR, '\n');
    return static_cast<char>(std::toupper(static_cast<unsigned char>(tegn)));
}

float lesFloat(const char* t, const float min, const float max) {
    char buffer[MAXCHAR] = "";
    float tall = 0.0F;
    bool feil = false;

    do {
        feil = false;
        std::cout << std::fixed << std::showpoint << std::setprecision(2);
        std::cout << t << " (" << min << " - " << max << "):  ";
        std::cin.getline(buffer, MAXCHAR);
        tall = static_cast<float>(atof(buffer));

        if (tall == 0.0F && buffer[0] != '0') {
            feil = true;
            std::cout << "\nERROR: Not a float\n\n";
        }
    } while (feil || tall < min || tall > max);

    return tall;
}

int lesInt(const char* t, const int min, const int max) {
    char buffer[MAXCHAR] = "";
    int tall = 0;
    bool feil = false;

    do {
        feil = false;
        std::cout << t << " (" << min << " - " << max << "):  ";
        std::cin.getline(buffer, MAXCHAR);
        tall = atoi(buffer);

        if (tall == 0 && buffer[0] != '0') {
            feil = true;
            std::cout << "\nERROR: Not an integer\n\n";
        }
    } while (feil || tall < min || tall > max);

    return tall;
}
