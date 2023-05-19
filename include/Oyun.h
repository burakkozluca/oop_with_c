#ifndef OYUN_H
# define OYUN_H

# include "Koloni.h"
# include "ATaktik.h"
# include "BTaktik.h"
# include "Taktik.h"
# include "Uretim.h"
//uretim h file ekle
# include <stdio.h>
# include <unistd.h>

struct OYUN
{
    Koloni koloni[50];
};
typedef struct OYUN* Oyun;

char	**ft_split(char const *str, char c);

#endif