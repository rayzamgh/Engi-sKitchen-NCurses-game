#include "graph.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
    Graph G;
    CreateGraph(1,&G);
    //Alokasi sudah ada didalam fungsi ini
    CreatePintu(&G, 1,2, MakePOINT(4,7), MakePOINT(5, 0));
    CreatePintu(&G, 2,4, MakePOINT(7,4), MakePOINT(0, 5));
    CreatePintu(&G, 4,3, MakePOINT(4,0), MakePOINT(6, 7));
    CreatePintu(&G, 3,1, MakePOINT(0,4), MakePOINT(7, 4));
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
    //Cari Pintu dari posisi 4,7 di room 1
    POINT asal = MakePOINT(4,7);
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