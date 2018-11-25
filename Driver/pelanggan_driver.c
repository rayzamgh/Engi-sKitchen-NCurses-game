#include "pelanggan.h"
#include <stdio.h>

int main(){
    // Kamus
    PELANGGAN P;
    int noRuangan;
    int X,Y;
    int banyak;    
    JAM waktuCabut;
    char ord[15];
    Kata orderan;
    int isStarPelanggan;
    int sudahOrder;
    // Algoritma
    printf("Masukan nomor ruangan : ");
    scanf("%d", &noRuangan);
    printf("Masukan posisi X : ");
    scanf("%d", &X);
    printf("Masukan posisi Y : ");
    scanf("%d", &Y);
    printf("Masukan banyak pelanggan : ");
    scanf("%d", &banyak);
    printf("Masukan waktu cabut dengan format \"HH MM SS\" tanpa \" (Contoh : 22 33 44) :\n");
	BacaJAM(&waktuCabut);
    printf("Masukan orderan : ");
    scanf("%s", ord);
    STARTKATAA(ord);
    orderan = CKataA;
    printf("Apakah pelanggan star (1 = true, 0 = false) : ");
    scanf("%d", &isStarPelanggan);
    printf("Apakah pelanggan sudah order (1 = true, 0 = false) : ");
    scanf("%d", &sudahOrder);
    Ruangan(P) = noRuangan;
    Pos(P) = MakePOINT(X,Y);
    Banyak(P) = banyak;
    WaktuCabut(P) = waktuCabut;
    Orderan(P) = orderan;
    if (isStarPelanggan == 1){
        IsStar(P) = true;
    }
    else{
        IsStar(P) = false;
    }
    if (sudahOrder == 1){
        SudahOrder(P) = true;
    }
    else{
        SudahOrder(P) = false;
    }
    printf("Pelanggan berada di ruangan : %d\n", Ruangan(P));
    printf("Pelanggan berada di posisi : (%d,%d)\n",Absis(Pos(P)), Ordinat(Pos(P)));
    printf("Pelanggan berada di ruangan : %d\n", Ruangan(P));
    printf("Pelanggan akan pergi pada jam : ");
    TulisJAM(WaktuCabut(P));
    printf("\n");
    if (IsStar(P)){
        printf("Pelanggan merupakan star\n");
    }
    else{
        printf("Pelanggan bukan star\n");
    }
    if (SudahOrder(P)){
        printf("Pelanggan sudah mengorder\n");
    }
    else{
        printf("Pelanggan belum mengorder");
    }
    return 0;
}