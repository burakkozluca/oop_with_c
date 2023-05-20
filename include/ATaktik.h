#ifndef ATAKTIK_H
# define ATAKTIK_H

# include "Taktik.h"
# include <stdio.h>
# include <unistd.h>

struct ATAKTIK 
{
    Taktik taktik; //taktik sınıfından kalıtım
    int a;
    void (*destructor)(struct ATAKTIK);
};
typedef struct ATAKTIK* ATaktik;

#endif