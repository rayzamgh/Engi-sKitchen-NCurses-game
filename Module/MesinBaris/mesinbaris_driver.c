#include "mesinbaris.h"
#include "matriks.h"
#include <stdio.h>

int main (){
    // Kamus
    MATRIKS M;
    // Algoritma
    STARTBARIS("matriks.txt");
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
    NBrsEff(M) = i - 1;
    NKolEff(M) = CBaris.Length - 1;
    TulisMATRIKS(M);
    printf("\n");
}