#include "Uretim.h"
#include <stdlib.h> // rand ve srand için
#include <time.h> // time için

// Uret fonksiyonu, 1 ile 10 arasında rastgele bir sayı döndürür.
int Uret() {
    // Rastgele sayı üretimini daha "rastgele" hale getirmek için
    srand(time(0));
    return (rand() % 10) + 1;
}

// Uretim yapısının Uret fonksiyonunu tanımlama
Uretim YeniUretim() {
    Uretim yeniUretim;
    yeniUretim.Uret = Uret;
    return yeniUretim;
}