#include "../include/mesinkarinput.h"
#include <stdio.h>

char CCInput;

void STARTINPUT(){
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita.  */

    /* Algoritma */
	scanf("%c",&CCInput);
}

void ADVINPUT() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = 
          CC
   F.S. : CC adalah karakter berikutnya dari CC yang lama */

	/* Algoritma */
	scanf("%c",&CCInput);
}
