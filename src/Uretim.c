#include "../include/Uretim.h"

//Uretim constructor
Uretim uconstructor()
{
    Uretim this;
    this = (Uretim)malloc(sizeof(struct URETIM));
    return this;
}

