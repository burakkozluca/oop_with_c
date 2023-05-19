#ifndef KOLONI_H
# define KOLONI_H

# include "Taktik.h"
# include "Uretim.h"

struct KOLONI
{
    int populasyon;
    int yemek;
    int sembol;
    int dead;
    int kazanma;
    int kaybetme;
};
typedef struct KOLONI* Koloni;

Koloni YeniKoloni(int populasyon);

#endif