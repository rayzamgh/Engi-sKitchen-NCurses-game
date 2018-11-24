#include "../include/point.h"
#include "../include/filemanager.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
    Graph G = BacaGraphPintu("../Default Save/pintu.txt");
    adrNode P = First(G);
    while(P != Nil)
    {
        printf("Id Node : %d\n",Id(P));
        printf("NPred : %d\n",NPred(P));
        adrSuccNode Pn = Trail(P);
        printf("Trail : \n");
        while(Pn != Nil)
        {
            printf("    Pintu Asal : %d, %d\n",Asal(Pn).X,Asal(Pn).Y);
            printf("    Pintu Tujuan : %d, %d\n",Tujuan(Pn).X,Tujuan(Pn).Y);
            printf("    Succ : %d\n",Id(Succ(Pn)));
            Pn = Next(Pn);
        }
        P = Next(P);
    }
    printf("----------------------------\n");
    //Cari Pintu dari posisi 4,8
    POINT asal = MakePOINT(4,8);
    POINT tujuan;
    int roomTujuan;
    CariEdgePintu(G,asal,1,&roomTujuan,&tujuan);
    if(roomTujuan!=-1)
    {
        printf("    Pintu Asal : %d, %d\n",Absis(asal),Ordinat(asal));
        printf("    Pintu Tujuan : %d, %d\n",Absis(tujuan),Ordinat(tujuan));
        printf("    Stage Tujuan : %d\n",roomTujuan);
    }
    return 0;
}