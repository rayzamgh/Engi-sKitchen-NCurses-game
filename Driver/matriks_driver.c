#include "../include/matriks.h"
#include <stdio.h>

int main (){
// kamus
MATRIKS M1,M2;
int NB, NK;
indeks i, j;
//algoritma
printf("Masukan nilai-nilai efektif matriks : (format \"NB NK\")");
scanf("%d %d", &NB, &NK);
BacaMATRIKS(&M1,NB,NK);
BacaMATRIKS(&M2,NB,NK);
if (EQ(M1,M2)){
    printf("Kedua matriks sama\n");
}
else if (NEQ(M1,M2)){
    printf("Kedua matriks berbeda\n");
}
printf("Jumlah elemen kedua matriks masing-masing adalah %d\n", NBElmtMATRIKS(M1));
printf("Berikut Matriks kedua: \n");
TulisMATRIKS(M2);
printf("\n");
CopyMATRIKS(M2, &M1);
TulisMATRIKS(M1);
printf("\n");
printf("%d adalah indeks baris pertama dan %d terakhir", GetFirstIdxBrs(M1), GetLastIdxBrs(M1));
printf("%d adalah indeks kolom pertama dan %d terakhir", GetFirstIdxKol(M1), GetLastIdxKol(M1));
printf("Masukan input indeks :");
scanf("%d %d", &i, &j);
if (!IsIdxValidMat(i,j)){
    print("Indeks tersebut tidak valid\n")
}
if(!IsIdxEffMat(i,j)){
    printf("Indeks tersebut tidak efektif\n")
}
return 0;
}