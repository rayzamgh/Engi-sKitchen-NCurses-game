#include "../include/mesinbaris.h"
#include "../include/matriks.h"
#include "../include/filemanager.h"
#include "../include/bintree.h"

MATRIKS BacaMap(char namaFile[100]){
    MATRIKS M;
    STARTBARIS(namaFile);
    int i = 0;
    while (!EndBaris){
        i++;
        for (int j = 1; j <= CBaris.Length; j++){
            ElmtMat(M, i, j) = CBaris.TabBaris[j];
        }
        ADVBARIS();
    }
    NBrsEff(M) = i;
    NKolEff(M) = CBaris.Length;
    return M;
}

BinTree BacaPohonMakanan(char namaFile[100])
{
    STARTBARIS(namaFile);
    int pos = 1;
    return PreOrderToTree(CBaris.TabBaris,&pos);
}
