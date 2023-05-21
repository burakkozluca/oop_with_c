#include "../include/ATaktik.h"

ATaktik atbelirle(int populasyon, int yemek)
{
    ATaktik this;
    this = (ATaktik)malloc(sizeof(struct ATAKTIK));
    this->super = constructor();
    this->pop = populasyon;
    this->yemek = yemek;
    this->destructor = &adestructor;
    this->super->Savas = &asavas;
}

void adestructor(ATaktik this)
{
    free(this);
}

int asavas() 
{
    return rand() % 1000 + 1; // 1-1000 arasında rastgele bir değer döndürür
}