#include "../include/mesinkatakomparasi.h"
#include <stdio.h>

int main (){
    // kamus
    char s1[100];
    char s2[100];
    // algoritma
    scanf("%s %s", s1, s2);
    if (IsSameString(s1,s2)){
        printf("kedua string sama\n");
    }
    else{
        printf("kedua string tidak sama\n");
    }
    return 0;
}