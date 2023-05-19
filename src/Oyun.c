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
        printf("%s\n", token[i]);
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
            printf("%d %i %d %d %d\n",yeniOyun->koloni[j]->sembol, yeniOyun->koloni[j]->populasyon, yeniOyun->koloni[j]->yemek, yeniOyun->koloni[j]->kazanma, yeniOyun->koloni[j]->kaybetme);
        else
            printf("--    --    --      --     --    --");
        j++;
    }
}