#include "../include/filemanager.h"
#include "../include/mesinkarkomparasi.h"
#include "../include/queue.h"
#include<stdio.h>

int main()
{
    Queue Q = BacaQueuePelanggan("../Default Save/antrianPelanggan.txt");
    Queue QMeja = BacaQueueMejaPelanggan("../Default Save/pelangganDiMeja.txt");
    while(!IsEmptyQueue(Q))
    {
        PELANGGAN temp;
        Del(&Q,&temp);
        printf("Pos : %d,%d\n",Pos(temp).X,Pos(temp).Y);
        printf("Banyak orang : %d\n",Banyak(temp));
        printf("Waktu cabut : %ld\n",JAMToDetik(WaktuCabut(temp)));
        printf("Nama orderan : %s\n",Orderan(temp).TabKata);
        if(IsStar(temp))
        {
            printf("Merupakan star customer\n");
        }else{
            printf("Bukan star customer\n");
        }
        printf("\n");
    }
    printf("------------------------\n");
    //Tambahin pelanggan Baru
    PELANGGAN baru;
    Ruangan(baru) = 2;
    Pos(baru) = MakePOINT(1,2);
    Banyak(baru) = 4;
    WaktuCabut(baru) = DetikToJAM(10);
    IsStar(baru) = true;
    Add(&QMeja,baru);
    while(!IsEmptyQueue(QMeja))
    {
        PELANGGAN temp2;
        Del(&QMeja,&temp2);
        printf("No Ruangan : %d\n",Ruangan(temp2));
        printf("Pos : %d,%d\n",Pos(temp2).X,Pos(temp2).Y);
        printf("Banyak orang : %d\n",Banyak(temp2));
        printf("Waktu cabut : %ld\n",JAMToDetik(WaktuCabut(temp2)));
        printf("Nama orderan : %s\n",Orderan(temp2).TabKata);
        if(IsStar(temp2))
        {
            printf("Merupakan star customer\n");
        }else{
            printf("Bukan star customer\n");
        }
        printf("\n");
    }
    return 0;
}