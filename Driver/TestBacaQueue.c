#include "include/filemanager.h"
#include "include/mesinkarkomparasi.h"
#include "include/queue.h"
#include<stdio.h>

int main()
{
    Queue Q = BacaQueuePelanggan("save/Aditya/pelanggan.txt");
    while(!IsEmptyQueue(Q))
    {
        PELANGGAN temp;
        Del(&Q,&temp);
        printf("Pos : %d,%d\n",Pos(temp).X,Pos(temp).Y);
        printf("Banyak orang : %d\n",Banyak(temp));
        printf("Waktu cabut : %ld\n",JAMToDetik(WaktuCabut(temp)));
        if(SudahDuduk(temp))
        {
            printf("Pelanggan sudah duduk\n");
        }else{
            printf("Pelanggan belum duduk\n");
        }
        printf("Nama orderan : %s\n",Orderan(temp).TabKata);
        if(IsStar(temp))
        {
            printf("Merupakan star customer\n");
        }else{
            printf("Bukan star customer\n");
        }
        printf("\n");
    }
    return 0;
}