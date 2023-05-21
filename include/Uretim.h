#ifndef URETIM_H
# define URETIM_H

# include <unistd.h>
# include <stdlib.h>

struct URETIM 
{
    int (*Uret)();
};
typedef struct URETIM* Uretim;
Uretim uconstructor();

#endif