#include <stdlib.h>
#include "Taktik.h"

int Savas() 
{
    // rand() fonksiyonu 0 ile RAND_MAX arasında bir sayı döndürür.
    // Bu nedenle, 0-1000 arasında bir sayı elde etmek için rand()'ın sonucunu 1001'e böleriz.
    return rand() % 1001;
}