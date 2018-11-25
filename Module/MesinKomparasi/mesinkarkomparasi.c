#include "mesinkarkomparasi.h"
#include <stdio.h>

char CCA;
boolean EOPA;
char stringKarakterA[MaxLengthString];
int posisiA;

char CCB;
boolean EOPB;
char stringKarakterB[MaxLengthString];
int posisiB;

void RESETA()
{
      int i = 0;
      while (stringKarakterA[i] != '\000')
      {
            stringKarakterA[i] = '\000';
            i += 1;
      }
}

void SETSTRINGA(char s[MaxLengthString])
{
      /* Load string s untuk dibaca oleh mesinkar */
      int i = 0;
      RESETA();
      while (s[i] != '\000')
      {
            stringKarakterA[i] = s[i];
            i++;
      }
      posisiA = 0;
}
void STARTA()
{
      /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARKKomp maka EOP akan padam (false).
          Jika CC = MARKKomp maka EOP akan menyala (true) */

      /* Algoritma */
      posisiA = 0;
      CCA = stringKarakterA[posisiA];
      ADVA();
}

void ADVA()
{
      /* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = 
          CC, CC != MARKKomp
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARKKomp.
		  Jika  CC = MARKKomp maka EOP akan menyala (true) */

      /* Algoritma */
      CCA = stringKarakterA[posisiA];
      posisiA++;
      EOPA = (CCA == MARKKomp);
}

void RESETB()
{
      int i = 0;
      while (stringKarakterB[i] != '\000')
      {
            stringKarakterB[i] = '\000';
            i += 1;
      }
}

void SETSTRINGB(char s[MaxLengthString])
{
      /* Load string s untuk dibaca oleh mesinkar */
      int i = 0;
      RESETB();
      while (s[i] != '\000')
      {
            stringKarakterB[i] = s[i];
            i++;
      }
      posisiB = 0;
}
void STARTB()
{
      /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARKKomp maka EOP akan padam (false).
          Jika CC = MARKKomp maka EOP akan menyala (true) */

      /* Algoritma */
      posisiB = 0;
      CCB = stringKarakterB[posisiB];
      ADVB();
}

void ADVB()
{
      /* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = 
          CC, CC != MARKKomp
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARKKomp.
		  Jika  CC = MARKKomp maka EOP akan menyala (true) */

      /* Algoritma */
      CCB = stringKarakterB[posisiB];
      posisiB++;
      EOPB = (CCB == MARKKomp);
}

int CharToInt(char c)
{
      if (c >= '0' && c <= '9')
      {
            return c - '0';
      }
      else
      {
            return -1;
      }
}

long int StringToLongInt(char s[10])
{
      long int hasil = 0;
      RESETA();
      SETSTRINGA(s);
      STARTA();
      while(!(EOPA))
      {
            hasil *= 10;
            int temp = CharToInt(CCA);
            if(temp == -1)
            {
                  return 0;
            }else{
                  hasil += CharToInt(CCA);
                  ADVA();
            }
      }
      return hasil;
}