#ifndef ATAKTIK_H
# define ATAKTIK_H

# include "Taktik.h"

struct ATAKTIK 
{
    Taktik taktik; //taktik sınıfından kalıtım
    // ATaktik'e özel eklemeler
    //int agresiflik; mesela
};
typedef struct ATAKTIK* ATaktik;

#endif