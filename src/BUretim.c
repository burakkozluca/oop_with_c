#include "../include/BUretim.h"

//Buretim constructor
Buretim bubelirle(int populasyon, int yemek)
{
    Buretim this;
    this = (Buretim)malloc(sizeof(struct BURETIM));
    this->super = uconstructor();
    this->pop = populasyon;
    this->yemek = yemek;
    this->destructor = &budestructor;
}

//Buretim destructor
void budestructor(Buretim this)
{
    free(this);
}
