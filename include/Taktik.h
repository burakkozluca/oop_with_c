#ifndef TAKTIK_H
# define TAKTIK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

struct TAKTIK
{
    int (*Savas)(); //0-1000 arası değer döndüreceği için int tanımladık.
    int savasdegeri;
};
typedef struct TAKTIK* Taktik;
Taktik constructor();

#endif