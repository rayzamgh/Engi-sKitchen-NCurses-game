/* File: mesinkar.h */
/* Definisi Mesin Karakter */

#ifndef __MESINKARKOMPARASI_H_
#define __MESINKARKOMPARASI_H_

#include "boolean.h"

#define MARK '\000'
#define MaxLengthString 100

/* State Mesin */
extern char CCA;
extern boolean EOPA;
extern char stringKarakterA[MaxLengthString];
extern int posisiA;

extern char CCB;
extern boolean EOPB;
extern char stringKarakterB[MaxLengthString];
extern int posisiB;

void SETSTRINGA(char s[MaxLengthString]);
/* Load string s untuk dibaca oleh mesinkar */

void STARTA();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK maka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */

void ADVA();
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARK
          Jika  CC = MARK maka EOP akan menyala (true) */

void SETSTRINGB(char s[MaxLengthString]);
/* Load string s untuk dibaca oleh mesinkar */

void STARTB();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK maka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */

void ADVB();
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARK
          Jika  CC = MARK maka EOP akan menyala (true) */

#endif
