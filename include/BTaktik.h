#ifndef BTAKTIK_H
# define BTAKTIK_H

# include "Taktik.h"
# include <stdio.h>
# include <unistd.h>

struct BTAKTIK
{
    Taktik super; //taktik sınıfından kalıtım
    int pop;
    int yemek;
    void (*destructor)(struct BTAKTIK*);
};
typedef struct BTAKTIK* BTaktik;
void bdestructor(BTaktik this);
BTaktik btbelirle(int populasyon, int yemek);
int bsavas();

#endif