#include "../include/Koloni.h"
#include <stdlib.h>

// Koloni oluşturucu fonksiyon
Koloni YeniKoloni(int populasyon)
{
    Koloni this = (Koloni) malloc(sizeof(struct KOLONI));
    this->populasyon = populasyon;
    this->yemek = populasyon * populasyon; // başlangıç yemek stoğu popülasyonun karesi
    this->sembol = 33 + (rand() % 94);
    this->dead = 1;
    this->kazanma = 0;
    this->kaybetme = 0;
    return this;
}
