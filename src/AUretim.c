#include "../include/AUretim.h"

//Auretim constructor
Auretim aubelirle(int populasyon, int yemek)
{
    Auretim this;
    this = (Auretim)malloc(sizeof(struct AURETIM));
    this->super = uconstructor();
    this->pop = populasyon;
    this->yemek = yemek;
    this->destructor = &audestructor;
}

//Auretim destructor
void audestructor(Auretim this)
{
    free(this);
}