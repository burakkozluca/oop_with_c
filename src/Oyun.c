// Oyun.c
#include "Oyun.h"
#include <stdlib.h>

// Oyun başlatma fonksiyonu
Oyun* OyunBaslat(Koloni* koloniler, int koloniSayisi) {
    Oyun* yeniOyun = (Oyun*) malloc(sizeof(Oyun));
    yeniOyun->koloniler = koloniler;
    yeniOyun->tur = 0;
    return yeniOyun;
}

// Oyunun bitip bitmediğini kontrol eden fonksiyon
int OyunBittiMi(Oyun* oyun, int koloniSayisi) {
    int aktifKoloniSayisi = 0;
    for (int i = 0; i < koloniSayisi; i++) {
        if (oyun->koloniler[i].popülasyon > 0) {
            aktifKoloniSayisi++;
        }
    }
    // Aktif koloni sayısı 1 veya daha az ise oyun biter.
    return aktifKoloniSayisi <= 1;
}

// Bir tur oynatma fonksiyonu
void TurOyna(Oyun* oyun, int koloniSayisi) {
    oyun->tur++;

    // Her koloni için popülasyon artışı ve yemek azalışı
    for (int i = 0; i < koloniSayisi; i++) {
        if (oyun->koloniler[i].popülasyon > 0) {
            PopülasyonGüncelle(&oyun->koloniler[i], oyun->koloniler[i].popülasyon * 0.2); // Popülasyon %20 artar
            YemekGüncelle(&oyun->koloniler[i], -oyun->koloniler[i].popülasyon * 2); // Yemek stoğu (GüncelPopülasyon x 2) oranında azalır
            oyun->koloniler[i].yemek += oyun->koloniler[i].uretim->Uret(); // Uret fonksiyonunu çağırarak yemek ekler
        }
    }

    // Savaşlar
    for (int i = 0; i < koloniSayisi; i++) {
        for (int j = i + 1; j < koloniSayisi; j++) {
            if (oyun->koloniler[i].popülasyon > 0 && oyun->koloniler[j].popülasyon > 0) {
                // i. ve j. koloniler arasında savaş
                // Savaş fonksiyonu ve sonuç işlemleri burada yapılmalı
            }
        }
    }
}
