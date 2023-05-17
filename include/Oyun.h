#ifndef OYUN_H
#define OYUN_H

#include "Koloni.h"

typedef struct Oyun {
    Koloni* koloniler;
    int tur;
} Oyun;

#endif