// Oyun.c
#include "../include/Oyun.h"
#include <stdlib.h>
#include <stdio.h>
#include "../include/Koloni.h"
#include "../include/ATaktik.h"
#include "../include/BTaktik.h"

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
                ATaktik ataktik = atbelirle(yeniOyun->koloni[i]->populasyon, yeniOyun->koloni[i]->yemek);
                BTaktik btaktik = btbelirle(yeniOyun->koloni[i]->populasyon, yeniOyun->koloni[i]->yemek);
                ATaktik ataktik1 = atbelirle(yeniOyun->koloni[j]->populasyon, yeniOyun->koloni[j]->yemek);
                BTaktik btaktik1 = btbelirle(yeniOyun->koloni[j]->populasyon, yeniOyun->koloni[j]->yemek);
                int a = asavas();
                int b = bsavas();
                
                // if(rand() % 2 == 0)
                // {
                //     ataktik->super->savasdegeri = a;
                //     btaktik->super->savasdegeri = b;
                // }
                // else
                // {
                //     ataktik1->super->savasdegeri = a;
                //     btaktik1->super->savasdegeri = b;
                // }
                if(a > b)
                {
                    yeniOyun->koloni[i]->yemek += yeniOyun->koloni[j]->yemek * 0.1;
                    yeniOyun->koloni[i]->kazanma += 1;
                    yeniOyun->koloni[j]->yemek -= yeniOyun->koloni[j]->yemek * (a - b) / 1000;
                    yeniOyun->koloni[j]->kaybetme += 1;
                    yeniOyun->koloni[j]->populasyon -= yeniOyun->koloni[j]->populasyon * (a - b) / 1000;
                }
                if(b > a)
                {
                    yeniOyun->koloni[i]->yemek += yeniOyun->koloni[j]->yemek * 0.1;
                    yeniOyun->koloni[i]->kazanma += 1;
                    yeniOyun->koloni[j]->yemek -= yeniOyun->koloni[j]->yemek * (b - a) / 1000;
                    yeniOyun->koloni[j]->kaybetme += 1;
                    yeniOyun->koloni[j]->populasyon -= yeniOyun->koloni[j]->populasyon * (b - a) / 1000;
                }
            }
            j++;
        }
        i++;
        if(token[i] == NULL)
        {
            i = 0;
            int hayattaKalanKoloniSayisi = 0;
            while (token[i])
            {
                printf("%d",i);

                int boolhayat = 0;
                if (yeniOyun->koloni[i]->dead > 0)
                {
                    printf("burak");
                    boolhayat = 1;
                    break;
                }
                if (!boolhayat)
                {
                    hayattaKalanKoloniSayisi++;
                    if (hayattaKalanKoloniSayisi > 1)
                    {
                        printf("yarıs bitmedi\n");
                        // Birden fazla koloni hayatta kalamaz, istenilen durum sağlanmadı.
                        break;
                    }
                }
                i++;
            }

            if (hayattaKalanKoloniSayisi == 1)
            {
            // Sadece bir koloni hayatta kaldı.
            // İstenilen durum sağlandı.
            }
            else
            {
                // Birden fazla koloni hayatta kaldı veya hiç koloni hayatta kalmadı.
                // İstenilen durum sağlanmadı.
            }
        }
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
            printf("%4c %11d %15d %11d %10d %5d\n",yeniOyun->koloni[j]->sembol, yeniOyun->koloni[j]->populasyon, yeniOyun->koloni[j]->yemek, yeniOyun->koloni[j]->kazanma, yeniOyun->koloni[j]->kaybetme, yeniOyun->koloni[j]->dead);
        else
            printf("--    --    --      --     --    --"); //düzelt
        j++;
    }
}