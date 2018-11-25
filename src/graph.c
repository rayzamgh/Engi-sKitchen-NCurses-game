#include "../include/graph.h"
#include<stdlib.h>

//Konstruktor
void CreateGraph(int X, Graph* G)
{
    First(*G) = Nil;
    adrNode temp;
    InsertNode(G,X,&temp);
}

//Manajemen Memory
adrNode AlokNodeGraph(int X)
{
    adrNode P = (adrNode)malloc(sizeof(NodeGraph));
    if(P != Nil)
    {
        Id(P) = X;
        NPred(P) = 0;
        Trail(P) = Nil;
        Next(P) = Nil;
    }else{
        return Nil;
    }
}
void DealokNodeGraph(adrNode P)
{
    free(P);
}
adrSuccNode AlokSuccNode(adrNode Pn, POINT asal, POINT tujuan)
{
    adrSuccNode P = (adrSuccNode)malloc(sizeof(SuccNode));
    if(P != Nil)
    {
        Asal(P) = asal;
        Tujuan(P) = tujuan;
        Succ(P) = Pn;
        Next(P) = Nil;
    }else{
        return Nil;
    }
}
void DealokSuccNode(adrSuccNode P)
{
    free(P);
}

adrNode SearchNode(Graph G, int X)
{
    adrNode P = First(G);
    while(P != Nil && Id(P) != X)
    {
        P = Next(P);
    }
    return P;
}
adrSuccNode SearchEdge(Graph G, int prec, int succ)
{
    adrNode PPrec = SearchNode(G,prec);
    adrNode PSucc = SearchNode(G,succ);
    if(PPrec != Nil && PSucc != Nil){
        adrSuccNode Pn = Trail(PPrec);
        while(Pn != Nil && Succ(Pn)!=PSucc)
        {
            Pn = Next(Pn);
        }
        return Pn;
    }else{
        return Nil;
    }
}
void InsertNode(Graph* G, int X, adrNode* Pn)
{
    adrNode prevP = Nil;
    *Pn = First(*G);
    while(*Pn != Nil)
    {
        prevP = *Pn;
        *Pn = Next(*Pn);
    }
    *Pn = AlokNodeGraph(X);
    if(*Pn != Nil)
    {
        if(prevP == Nil)
        {
            First(*G) = *Pn;
        }else{
            Next(prevP) = *Pn;
        }
    }
}
void InsertEdge(Graph* G, int prec, int succ, POINT asal, POINT tujuan)
{
    adrNode PPrec,PSucc;
    if(SearchNode(*G,prec) == Nil)
    {
        InsertNode(G,prec,&PPrec);
    }else{
        PPrec = SearchNode(*G,prec);
    }
    if(SearchNode(*G,succ) == Nil)
    {
        InsertNode(G,succ,&PSucc);
    }else{
        PSucc = SearchNode(*G,succ);
    }
    if(SearchEdge(*G,Id(PPrec),Id(PSucc)) == Nil)
    {
        adrSuccNode prevPn = Nil;
        adrSuccNode Pn = Trail(PPrec);
        while(Pn != Nil)
        {
            prevPn = Pn;
            Pn = Next(Pn);
        }
        if(prevPn == Nil)
        {
            Trail(PPrec) = AlokSuccNode(PSucc,asal,tujuan);
        }else{
            Next(prevPn) = AlokSuccNode(PSucc,asal,tujuan);
        }
        NPred(PSucc) += 1;
    }

}

void CreatePintu(Graph* G, int room1, int room2, POINT pintuRoom1, POINT pintuRoom2)
{
    InsertEdge(G,room1,room2,pintuRoom1,pintuRoom2);
    InsertEdge(G,room2,room1,pintuRoom2,pintuRoom1);
}

void CariEdgePintu(Graph G,POINT asal,int roomAsal,int* roomTujuan,POINT* tujuan)
{
    adrNode roomA = SearchNode(G,roomAsal);
    adrSuccNode Pn = Trail(roomA);
    boolean ketemu = false;
    *roomTujuan = -1;
    *tujuan = MakePOINT(-1,-1);
    while(Pn != Nil && !ketemu)
    {
        if(PointEQ(Asal(Pn),asal))
        {
            ketemu = true;
            *roomTujuan = Id(Succ(Pn));
            *tujuan = MakePOINT(Absis(Tujuan(Pn)),Ordinat(Tujuan(Pn)));
        }else{
            Pn = Next(Pn);
        }
    }
    
}