#include "../include/BTaktik.h"

//BTaktik constructor
BTaktik btbelirle(int populasyon, int yemek)
{
    BTaktik this;
    this = (BTaktik)malloc(sizeof(struct BTAKTIK));
    this->super = constructor();
    this->pop = populasyon;
    this->yemek = yemek;
    this->destructor = &bdestructor;
    this->super->Savas = &bsavas;
}

//BTaktik destructor
void bdestructor(BTaktik this)
{
    free(this);
}

int bsavas() 
{
    return rand() % 1000 + 1; // 1-1000 arasında rastgele bir değer döndürür
}