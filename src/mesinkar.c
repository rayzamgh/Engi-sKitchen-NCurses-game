#include "../include/mesinkar.h"
#include <stdio.h>

char CC;
boolean EOP;
char filenameMesinKar[20];

static FILE * pita;
static int retval;

void SETFILE(char namaFile[20]){
/* Set filenameMesinKar jadi namaFile */
      for(int i = 0;i<20;i++)
      {
            filenameMesinKar[i] = namaFile[i];
      }
}

void START() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	pita = fopen(filenameMesinKar,"r");
	ADV();
}

void ADV() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = 
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARK.
		  Jika  CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	retval = fscanf(pita,"%c",&CC);
	EOP = (CC == MARK);
	if (EOP) {
       fclose(pita);
 	}
}
