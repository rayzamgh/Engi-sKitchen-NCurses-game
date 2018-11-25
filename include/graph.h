#include "point.h"

#define Nil NULL

typedef struct tNodeGraph* adrNode;
typedef struct tSuccNode* adrSuccNode;
typedef struct tNodeGraph
{
    int Id;
    int NPred;
    adrSuccNode Trail;
    adrNode Next;
} NodeGraph;
typedef struct tSuccNode
{
    POINT asal;
    POINT tujuan;
    adrNode Succ;
    adrSuccNode Next;
} SuccNode;

typedef struct
{
    adrNode First;
} Graph;

//Selektor
#define First(G) (G).First
#define Id(Pn) (Pn)->Id
#define Trail(Pn) (Pn)->Trail
#define Asal(Pn) (Pn)->asal
#define Tujuan(Pn) (Pn)->tujuan
#define Succ(Pn) (Pn)->Succ
#define NPred(Pn) (Pn)->NPred
#define Next(Pn) (Pn)->Next

//Konstruktor
void CreateGraph(int X, Graph* G);

//Manajemen Memory
adrNode AlokNodeGraph(int X);
void DealokNodeGraph(adrNode P);
adrSuccNode AlokSuccNode(adrNode Pn, POINT asal, POINT tujuan);
void DealokSuccNode(adrSuccNode P);

adrNode SearchNode(Graph G, int X);
adrSuccNode SearchEdge(Graph G, int prec, int succ);
void InsertNode(Graph* G, int X, adrNode* Pn);
void InsertEdge(Graph* G, int prec, int succ, POINT asal, POINT tujuan);


/* Tubes */
void CreatePintu(Graph* G, int room1, int room2, POINT pintuRoom1, POINT pintuRoom2);
void CariEdgePintu(Graph G,POINT asal,int roomAsal,int* roomTujuan,POINT* tujuan);
