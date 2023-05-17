#ifndef KOLONI_H
#define KOLONI_H

#include "Taktik.h"
#include "Uretim.h"

typedef struct Koloni {
    Taktik* taktik;
    Uretim* uretim;
    int popülasyon;
    int yemek;
    char sembol;
} Koloni;


#endif