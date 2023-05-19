#ifndef TAKTIK_H
# define TAKTIK_H

# include <unistd.h>

struct TAKTIK
{
    int (*Savas)(); //0-1000 arası değer döndüreceği için int tanımladık.
};
typedef struct TAKTIK* Taktik;

#endif