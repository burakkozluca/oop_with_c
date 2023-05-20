// Oyun.c
#include "../include/Oyun.h"
#include <stdlib.h>
#include <stdio.h>
#include "../include/Koloni.h"

void yenioyun(char **token)
{
    Oyun yeniOyun = (Oyun)malloc(sizeof(struct OYUN));
    yeniOyun->tur = 0;
    int i = 0;
    int sayi = 0;

    while (token[i]) {
        sayi = atoi(token[i]);
        yeniOyun->koloni[i] = YeniKoloni(sayi); //koloni oluşturma
        i++;
    }
    screen(yeniOyun->tur, i, yeniOyun);
    yeniOyun->tur++;
    i = 0;
    while (token[i])
    {
        if(yeniOyun->koloni[i]->dead > 0)
        {
            //uret function
            Durumguncelle(yeniOyun->koloni[i],yeniOyun->koloni[i]->populasyon, yeniOyun->koloni[i++]->yemek);
        }
    }
    i = 0;
    //mucadele while
    int j = 1;
    while(token[i]) //i -1 dememiz gerekebilir cünkü mücadele olacak
    {
        while(token[j])
        {
            if(yeniOyun->koloni[j]->dead > 0 && yeniOyun->koloni[j]->yemek > 0 && yeniOyun->koloni[i]->dead > 0 && yeniOyun->koloni[i]->yemek > 0)
            {
                ATaktik a =  
            }
            j++;
        }
        i++;
    }
    screen(yeniOyun->tur, i, yeniOyun);
}

void screen(int tur, int i, Oyun yeniOyun)
{
    printf("-------------------------------------------------------------\n");
    printf("Tur Sayisi: %d\n", tur);
    printf("Koloni    Populasyon     Yemek Stogu    Kazanma    Kaybetme\n");
    int j = 0;
    while(j < i)
    {
        if(yeniOyun->koloni[j]->dead == 1)
            printf("%4d %11d %15d %11d %10d\n",yeniOyun->koloni[j]->sembol, yeniOyun->koloni[j]->populasyon, yeniOyun->koloni[j]->yemek, yeniOyun->koloni[j]->kazanma, yeniOyun->koloni[j]->kaybetme);
        else
            printf("--    --    --      --     --    --"); //düzelt
        j++;
    }
}