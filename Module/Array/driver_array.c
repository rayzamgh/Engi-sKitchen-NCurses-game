#include "array.h"
#include <stdio.h>

int main(){
    // Kamus
    TabKata T;
    char s[100];
    IdxType i;
    int n;
    ElType E;
    // Algoritma
    // MakeEmpty
    MakeEmptyArray(&T);
    // AddAsLastEl
    printf("Masukan N : ");
    scanf("%d", &n);
    for (i = 1; i<=n; i++){
        printf("Masukan elemen ke-%d : ", i);
        scanf("%s", s);
        STARTKATAA(s);
        AddAsLastEl(&T, CKataA);
    }
    //Tulis isi
    printf("Array Sekarang :\n");
    TulisIsi(T);
    //Search1 dan DelEli
    printf("Masukan kata yang ingin di delete : ");
    scanf("%s", s);
    STARTKATAA(s);
    if (Search1(T,CKataA) != IdxUndef){
        DelEli(&T, Search1(T,CKataA), &E);
        printf("Array Sekarang :\n");
        TulisIsi(T);
    }
    else{
        printf("Kata tersebut tidak ada pada array\n");
    }
    if (IsEmptyArray(T)){
        printf("Array tersebut kosong\n");
    }
    else if (IsFullArray(T)){
        printf("Array tersebut penuh\n");
    }
    printf("Masukan indeks : ");
    scanf("%d", &i);
    if (IsIdxValid(T,i)){
        printf("Indeks tersebut valid dalam array T\n");
    }
    if (IsIdxEff(T,i)){
        printf("Indeks tersebut efektif dalam array T\n");
    }
    printf("Indeks efektif pertama dari array T adalah %d\n", GetFirstIdx(T));
    printf("Indeks efektif terakhir dari array T adalah %d\n", GetLastIdx(T));
    printf("Maximum elemen yang bisa ditampung oleh array T adalah %d\n", MaxNbEl(T));
    printf("Jumlah elemen dari array T adalah %d\n", NbElmt(T));
    return 0;
}