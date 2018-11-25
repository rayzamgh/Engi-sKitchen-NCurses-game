#include "bintree.h"
#include <stdio.h>

int main(){
    // kamus
    BinTree P1,P2,P3;
    infotypeLR X;
    char s[500];
    int pos = 0;
    // algoritma
    printf("Masukan Akar P1 : ");
    scanf("%s", s);
    STARTKATAA(s);
    printf("Masukan Akar P2 : ");
    scanf("%s",s);
    STARTKATAB(s);
    MakeTree(CKataA, Nil, Nil, &P1);
    P2 = Tree(CKataB, Nil, Nil);
    DealokNode(P1);
    DealokNode(P2);
    scanf("%s", s);
    P3 = PreOrderToTree(s, &pos);
    if (IsTreeEmpty(P3)){
        printf("Pohon Kosong\n");
    }
    else if(IsTreeOneElmt(P3)){
        printf("Pohon satu elemen\n");
    }
    else if(IsUnerLeft(P3)){
        printf("Pohon hanya punya anak kiri\n");
    }
    else if(IsUnerRight(P3)){
        printf("Pohon hanya punya anak kanan\n");   
    }
    else if(IsBiner(P3)){
        printf("jumlah daun dari pohon adalah %d\n", NbDaun(P3));
        printf("Pohon punya anak kiri dan kanan\n");
    }
    printf("Jumlah elemen dari pohon adalah %d\n", NbElmtTree(P3));
    printf("Masukan suatu kata : ");
    scanf("%s", s);
    STARTKATAA(s);
    if (SearchTree(P3,CKataA)){
        printf("Level dari kata tersebut di pohon adalah %d\n", Level(P3,CKataA));
    }
    printf("Berikut pohon tersebut :\n");
    PrintPreorder(P3);
    printf("\n");
    PrintTree(P3,2);
    return 0;
}