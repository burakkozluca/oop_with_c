#include "../include/Oyun.h"

void yenioyun(char **token)
{
    Oyun yeniOyun = (Oyun)malloc(sizeof(struct OYUN)); //simulasyon icin yer acildi.
    yeniOyun->tur = 0;
    int i = 0;
    int sayi = 0;

    while (token[i]) //girilen sayi kadar koloni olusturma
    {
        sayi = atoi(token[i]); //girilen sayilari int'e cevirme
        yeniOyun->koloni[i] = YeniKoloni(sayi); //koloni olusturma
        i++;
    }
    screen(yeniOyun->tur, i, yeniOyun); //0. tu ekrana yazdirildi.
    i = 0;
    
    do //sona bir tane koloni kalana kadar devam eden do-while dongusu
    {
        while (token[i])
        {
            if(yeniOyun->koloni[i]->dead > 0)
            {
                //uretim fonskiyonu
                Durumguncelle(yeniOyun->koloni[i],yeniOyun->koloni[i]->populasyon, yeniOyun->koloni[i++]->yemek);
            }
        }
        i = 0;
        int j = 1;

        while(token[i])
        {

            j = i + 1;
            while(token[j])
            {
                //koloni hayattaysa ve yemekleri bitmediyse
                if(yeniOyun->koloni[j]->dead > 0 && yeniOyun->koloni[j]->yemek > 0 && yeniOyun->koloni[i]->dead > 0 && yeniOyun->koloni[i]->yemek > 0)
                {
                    //taktik olusturma
                    ATaktik ataktik = atbelirle(yeniOyun->koloni[i]->populasyon, yeniOyun->koloni[i]->yemek);
                    BTaktik btaktik = btbelirle(yeniOyun->koloni[i]->populasyon, yeniOyun->koloni[i]->yemek);
                    ATaktik ataktik1 = atbelirle(yeniOyun->koloni[j]->populasyon, yeniOyun->koloni[j]->yemek);
                    BTaktik btaktik1 = btbelirle(yeniOyun->koloni[j]->populasyon, yeniOyun->koloni[j]->yemek);
                    //savas fonksiyonlari cagirildi.
                    int a = asavas();
                    int b = bsavas();

                    //savas degeri kimin buyukse ona gore degerleri guncellendi.
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
                    //yemekleri ve populasyonlari bittiyse koloni oluyor.
                    if(yeniOyun->koloni[i]->populasyon <= 1 || yeniOyun->koloni[i]->yemek <= 1)
                        yeniOyun->koloni[i]->dead = 0;
                    if(yeniOyun->koloni[j]->populasyon <= 1 || yeniOyun->koloni[j]->yemek <= 1)
                        yeniOyun->koloni[j]->dead = 0;
                }
                j++;
            }
            i++;
        } 
        yeniOyun->tur++;
        screen(yeniOyun->tur, i, yeniOyun); //ekrana bilgileri yazdir.
        if (!check(yeniOyun, token) || countAliveColonies(yeniOyun, token) <= 1) //1 tane koloni kaldiyse donguyu sonlandir.
        {    
            printf("-------------------------------------------------------------\n");
            break;
        }
    } while (1);
    
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
            printf("%4c %11d %15d %11d %10d \n",yeniOyun->koloni[j]->sembol, yeniOyun->koloni[j]->populasyon, yeniOyun->koloni[j]->yemek, yeniOyun->koloni[j]->kazanma, yeniOyun->koloni[j]->kaybetme);
        else
            printf("%4s %11s %15s %11s %10s \n","--","--","--","--","--");
        j++;
    }
}

int check(Oyun yeniOyun, char **token)
{
        int i = 0;
        int hayattaKalanKoloniSayisi = 0;
        int boolhayat = 0;
        int returnvalue = 0;
        while (token[i])
        {
            
            if (yeniOyun->koloni[i]->dead > 0)
                boolhayat = 1;
            if (boolhayat)
            {
                hayattaKalanKoloniSayisi++;
                if (hayattaKalanKoloniSayisi > 1)
                {
                    boolhayat = 0;
                    returnvalue = 1;
                    break;
                }
                else
                {
                    returnvalue = 0;
                }
            }
            i++;
        }
        return(returnvalue);
}

int countAliveColonies(Oyun yeniOyun,char **token)
{
    int count = 0;
    for (int i = 0; token[i]; i++) {
        if (yeniOyun->koloni[i]->dead > 0) {
            count++;
        }
    }
    return count;
}