#include "stackt.h"
#include <stdio.h>

int main(){
    // Kamus
    Stack S;
    int i;
    char s[20];
    infotypeStack temp;
    // Algoritma
    CreateEmptyStack(&S);
    i = 1;
    while (!IsFullStack(S)){
        printf("Masukan elemen ke-%d : ", i);
        scanf("%s", s);
        STARTKATAA(s);
        Push(&S, CKataA);
        i += 1;
    }
    while (!IsEmptyStack(S)){
        Pop(&S, &temp);
    }
    return 0;
}