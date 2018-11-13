#include "../include/mesinkarkomparasi.h"
#include <stdio.h>

char CCA;
boolean EOPA;
char stringKarakterA[MaxLengthString];
int posisiA;

char CCB;
boolean EOPB;
char stringKarakterB[MaxLengthString];
int posisiB;

void SETSTRINGA(char s[MaxLengthString]){
/* Load string s untuk dibaca oleh mesinkar */
      int i = 0;
      while(s[i] != '\000')
      {
            stringKarakterA[i] = s[i];
            i++;
      }
      posisiA = 0;
}
void STARTA() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
      posisiA = 0;
	CCA = stringKarakterA[posisiA];
	ADVA();
}

void ADVA() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = 
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARK.
		  Jika  CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	CCA = stringKarakterA[posisiA];
      posisiA++;
	EOPA = (CCA == MARK);
}


void SETSTRINGB(char s[MaxLengthString]){
/* Load string s untuk dibaca oleh mesinkar */
      int i = 0;
      while(s[i] != '\000')
      {
            stringKarakterB[i] = s[i];
            i++;
      }
      posisiB = 0;
}
void STARTB() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
      posisiB = 0;
	CCB = stringKarakterB[posisiB];
	ADVB();
}

void ADVB() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = 
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARK.
		  Jika  CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	CCB = stringKarakterB[posisiB];
      posisiB++;
	EOPB = (CCB == MARK);
}

