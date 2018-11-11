#include "../include/mesinkar.h"
#include <stdio.h>

char CC;
boolean EOP;
char stringKarakter[MaxLengthString];
int posisi;

void SETSTRING(char s[MaxLengthString]){
/* Load string s untuk dibaca oleh mesinkar */
      int i = 0;
      while(s[i] != '\000')
      {
            stringKarakter[i] = s[i];
            i++;
      }
      posisi = 0;
}
void START() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
      posisi = 0;
	CC = stringKarakter[posisi];
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
	CC = stringKarakter[posisi];
      posisi++;
	EOP = (CC == MARK);
}
