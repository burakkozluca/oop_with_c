#include <stdlib.h>
#include "../include/Taktik.h"

Taktik constructor()
{
    Taktik this;
    this = (Taktik)malloc(sizeof(struct TAKTIK));
    return this;
}
