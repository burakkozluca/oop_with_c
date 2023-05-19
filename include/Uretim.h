#ifndef URETIM_H
# define URETIM_H

# include <unistd.h>

struct URETIM 
{
    int (*Uret)();
};
typedef struct URETIM* Uretim;

#endif