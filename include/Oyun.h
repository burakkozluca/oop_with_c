#ifndef OYUN_H
# define OYUN_H

# include "Koloni.h"
# include "ATaktik.h"
# include "BTaktik.h"
# include "Taktik.h"
# include "Uretim.h"
# include <stdio.h>
# include <unistd.h>

struct OYUN
{
    Koloni koloni[50];
    int tur;
};
typedef struct OYUN* Oyun;

char	**ft_split(char const *str, char c);
void    screen(int tur, int i, Oyun yeniOyun);
void    yenioyun(char **token);
int check(Oyun oyun, char **token);
int countAliveColonies(Oyun yeniOyun, char **token);

#endif