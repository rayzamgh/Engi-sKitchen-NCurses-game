#include "queue.h"
#include <stdio.h>

int main(){
    // Kamus
    Queue Q;
    int i,n,maxel;
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
    printf("Masukan max element : ");
    scanf("%d", &maxel);
    printf("Masukan n : ");
    scanf("%d", &n);
    CreateEmptyQueue(&Q,maxel);
    for (i=1;i<=n;i++){
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
        Add(&Q,P);
    }
    if(IsFullQueue(Q)){
        printf("Sekarang queue penuh\n");
    }
    else{
        printf("Sekarang queue tidak penuh\n");
    }
    printf("Sekarang isi queue ada : %d", NBElmt(Q));
    while(!IsEmptyQueue(Q)){
        Del(&Q,&P);
    }
}