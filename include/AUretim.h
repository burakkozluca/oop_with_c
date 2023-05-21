#ifndef AURETIM_H
# define AURETIM_H

# include "Uretim.h"

struct AURETIM
{
    Uretim super; //Uretim sinifindan kalitim
    int pop;
    int yemek;
    void (*destructor)(struct AURETIM*);
};
typedef struct AURETIM* Auretim;
void audestructor(Auretim this);

#endif