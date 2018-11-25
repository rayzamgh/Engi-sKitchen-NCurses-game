/*#include "../include/mesinbaris.h"
#include "../include/matriks.h"
#include "../include/bintree.h"
#include "../include/array.h"
#include "../include/queue.h"
#include "../include/stackt.h"
#include "../include/jam.h"
#include "../include/point.h"
*/
#include "../include/filemanager.h"
#include <stdio.h>
MATRIKS BacaMap(char namaFile[100])
{
    MATRIKS M;
    STARTBARIS(namaFile);
    int i = 0;
    while (!EndBaris)
    {
        for (int j = 0; j < CBaris.Length; j++)
        {
            ElmtMat(M, i, j) = CBaris.TabBaris[j];
        }
        i++;
        ADVBARIS();
    }
    NBrsEff(M) = i-1;
    NKolEff(M) = CBaris.Length-1;
    return M;
}

BinTree BacaPohonMakanan(char namaFile[100])
{
    STARTBARIS(namaFile);
    int pos = 0;
    return PreOrderToTree(CBaris.TabBaris, &pos);
}

TabKata BacaArray(char namaFile[100])
{
    TabKata T;
    MakeEmptyArray(&T);
    STARTBARIS(namaFile);
    int i = 0;
    while (!EndBaris)
    {
        i++;
        STARTKATAA(CBaris.TabBaris);
        AddAsLastEl(&T, CKataA);
        ADVBARIS();
    }
    return T;
}

Queue BacaQueuePelanggan(char namaFile[100])
{
    Queue Q;
    CreateEmptyQueue(&Q, 100);
    STARTBARIS(namaFile);
    while (!EndBaris)
    {
        PELANGGAN P;
        //Skip string pelanggan
        ADVBARIS();
        //Ambil posisi X dan Y
        STARTKATAA(CBaris.TabBaris);
        ADVBARIS();
        STARTKATAB(CBaris.TabBaris);
        ADVBARIS();
        Pos(P) = MakePOINT(StringToLongInt(CKataA.TabKata), StringToLongInt(CKataB.TabKata));
        STARTKATAB(CBaris.TabBaris);
        ADVBARIS();
        Banyak(P) = StringToLongInt(CKataB.TabKata);
        STARTKATAB(CBaris.TabBaris);
        ADVBARIS();
        WaktuCabut(P) = DetikToJAM(StringToLongInt(CKataB.TabKata));
        STARTKATAA(CBaris.TabBaris);
        ADVBARIS();
        Kata temp = CKataA;
        IsStar(P) = IsSameString(temp.TabKata, "Yes");
        Add(&Q, P);
    }
    return Q;
}

Stack BacaStackFood(char namaFile[100])
{
    Stack Food;
    CreateEmptyStack(&Food);
    STARTBARIS(namaFile);
    boolean ketemuHand = false;
    Kata temp;
    //Skip string Food
    ADVBARIS();
    while (!EndBaris && !ketemuHand)
    {
        STARTKATAA(CBaris.TabBaris);
        temp = CKataA;
        if (IsSameString(temp.TabKata, "Hand"))
        {
            ketemuHand = true;
        }
        else
        {
            Push(&Food, temp);
            ADVBARIS();
        }
    }
    return Food;
}

Stack BacaStackHand(char namaFile[100])
{
    Stack Hand;
    CreateEmptyStack(&Hand);
    STARTBARIS(namaFile);
    //Cari string Hand
    Kata temp;
    STARTKATAA(CBaris.TabBaris);
    temp = CKataA;
    while (!EndBaris && !IsSameString(temp.TabKata, "Hand"))
    {
        ADVBARIS();
        STARTKATAA(CBaris.TabBaris);
        temp = CKataA;
    }
    //Cek apakah sudah ketemu hand
    if (!EndBaris)
    {
        ADVBARIS();
        while (!EndBaris)
        {
            STARTKATAA(CBaris.TabBaris);
            Push(&Hand, CKataA);
            ADVBARIS();
        }
    }
    return Hand;
}

Graph BacaGraphPintu(char namaFile[100])
{
    Graph G;
    First(G) = Nil;
    STARTBARIS(namaFile);
    while(!EndBaris)
    {
        STARTKATAB(CBaris.TabBaris);
        int roomA = StringToLongInt(CKataB.TabKata);
        ADVKATAB();
        int roomB = StringToLongInt(CKataB.TabKata);
        ADVKATAB();
        int XA = StringToLongInt(CKataB.TabKata);
        ADVKATAB();
        int YA = StringToLongInt(CKataB.TabKata);
        ADVKATAB();
        int XB = StringToLongInt(CKataB.TabKata);
        ADVKATAB();
        int YB = StringToLongInt(CKataB.TabKata);
        CreatePintu(&G,roomA,roomB,MakePOINT(XA,YA),MakePOINT(XB,YB));
        ADVBARIS();
    }
    return G;
}