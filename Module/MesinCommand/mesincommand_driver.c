#include "mesincommand.h"
#include <stdio.h>

int main(){
    // kamus

    // algoritma
    STARTCOMMAND();
    while (!CommandIs("Exit")){
        ADVCOMMAND();
        if(CommandIs("Print")){
            printf("printing something...\n");
        }
    }
    return 0;   
}