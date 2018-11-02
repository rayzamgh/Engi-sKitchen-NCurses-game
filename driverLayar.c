#include "layar.h"
#include<stdio.h>

int main()
{
    LAYAR L;
    CreateEmptyLayar(&L,60,15);
    CreateTabel(&L,1,1,widthLayar(L),heightLayar(L),2,4);
    PutTextAt(&L,2,2,"abcdef");
    printLayar(L);
}