#ifndef BURETIM_H
# define BURETIM_H

# include "Uretim.h"

struct BURETIM
{
    Uretim super; //Uretim sinifindan kalitim
    int pop;
    int yemek;
    void (*destructor)(struct BURETIM*);
};
typedef struct BURETIM* Buretim;
void budestructor(Buretim this);

#endif