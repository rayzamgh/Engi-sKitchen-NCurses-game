#include "include/point.h"
#include "include/graph.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
    Graph G;
    CreateGraph(1,&G);
    CreatePintu(&G,1,2,MakePOINT(3,5),MakePOINT(4,2));
    CreatePintu(&G,1,3,MakePOINT(1,2),MakePOINT(4,5));
    CreatePintu(&G,2,4,MakePOINT(7,2),MakePOINT(4,7));
    CreatePintu(&G,3,4,MakePOINT(3,1),MakePOINT(4,9));
    return 0;
}