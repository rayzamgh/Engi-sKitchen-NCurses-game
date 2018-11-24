#include "include/filemanager.h"
#include "include/mesinkarkomparasi.h"
#include "include/array.h"
#include<stdio.h>

int main()
{
    TabKata T = BacaArray("save/Aditya/config.txt");
    TulisIsi(T);
    STARTKATAA("Nyawa");
    STARTKATAB("EndNyawa");
    Kata Nyawa = CKataA;
    Kata EndNyawa = CKataB;
    int idx1 = Search1(T,Nyawa);
    int idxNyawa = idx1+1;
    long int NyawaBrp = StringToLongInt(Elmt(T,idxNyawa).TabKata);
    printf("%ld\n",NyawaBrp+1);
    return 0;
}