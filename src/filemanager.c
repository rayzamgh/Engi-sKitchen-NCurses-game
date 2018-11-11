#include "../include/mesinbaris.h"
#include "../include/matriks.h"
#include "../include/filemanager.h"


MATRIKS BacaMap(){
    MATRIKS M;
    STARTBARIS("map.txt");
    int i = 0;
    while (!EndBaris){
        i++;
        for (int j = 1; j <= CBaris.Length; j++){
            Elmt(M, i, j) = CBaris.TabBaris[j];
        }
        ADVBARIS();
    }
    NBrsEff(M) = i;
    NKolEff(M) = CBaris.Length;
    return M;
}
