// Koloni.c
#include "Koloni.h"
#include <stdlib.h>

// Koloni oluşturucu fonksiyon
Koloni* YeniKoloni(Taktik* taktik, Uretim* uretim, int popülasyon, char sembol) {
    Koloni* yeniKoloni = (Koloni*) malloc(sizeof(Koloni));
    yeniKoloni->taktik = taktik;
    yeniKoloni->uretim = uretim;
    yeniKoloni->popülasyon = popülasyon;
    yeniKoloni->yemek = popülasyon * popülasyon; // başlangıç yemek stoğu popülasyonun karesi
    yeniKoloni->sembol = sembol;
    return yeniKoloni;
}

// Koloni popülasyonunu güncelleme fonksiyonu
void PopülasyonGüncelle(Koloni* koloni, int miktar) {
    koloni->popülasyon += miktar;
    if (koloni->popülasyon <= 0) {
        koloni->popülasyon = 0;
    }
}

// Koloni yemek stoğunu güncelleme fonksiyonu
void YemekGüncelle(Koloni* koloni, int miktar) {
    koloni->yemek += miktar;
    if (koloni->yemek <= 0) {
        koloni->yemek = 0;
    }
}
