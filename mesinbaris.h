
#ifndef __MESINBARIS_H__
#define __MESINBARIS_H__

#include "boolean.h"
#include "mesinkar.h"

#define NMax 50
#define BLANK ' '
#define NEWLINE '\n'

typedef struct {
	char TabBaris[NMax+1]; /* container penyimpan baris, indeks yang dipakai [1..NMax] */
    int Length;
} Baris;

/* State Mesin Baris */
extern boolean EndBaris;
extern Baris CBaris;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTBARIS(char filename[20]);
/* I.S. : CC sembarang
   F.S. : EndBaris = true, dan CC = MARK;
          atau EndBaris = false, CBaris adalah baris yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir baris */

void ADVBARIS();
/* I.S. : CC adalah karakter pertama baris yang akan diakuisisi
   F.S. : CBaris adalah baris terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari baris berikutnya, mungkin MARK
          Jika CC = MARK, EndBaris = true.
   Proses : Akuisisi baris menggunakan procedure SalinBaris */

void SalinBaris();
/* Mengakuisisi baris, menyimpan dalam  baris
   I.S. : CC adalah karakter pertama dari baris
   F.S. : CBaris berisi baris yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang baris melebihi NMax, maka sisa baris "dipotong" */

#endif
