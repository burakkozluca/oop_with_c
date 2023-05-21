#ifndef ATAKTIK_H
# define ATAKTIK_H

# include "Taktik.h"
# include <stdio.h>
# include <unistd.h>

struct ATAKTIK 
{
    Taktik super; //taktik sınıfından kalıtım
    int pop;
    int yemek;
    void (*destructor)(struct ATAKTIK*);
};
typedef struct ATAKTIK* ATaktik;

void adestructor(ATaktik this);
ATaktik atbelirle(int populasyon, int yemek);
int asavas();

#endif