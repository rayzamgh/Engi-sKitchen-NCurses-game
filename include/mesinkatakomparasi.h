/* File: mesinkatakomparasi.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATAKOMPARASI_H__
#define __MESINKATAKOMPARASI_H__

#include "boolean.h"
#include "mesinkarkomparasi.h"

#define NMax 500
#define NStringMax 200
#define BLANK ' '

typedef struct {
	char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKataB;
extern Kata CKataA;

extern boolean EndKataB;
extern Kata CKataB;

void IgnoreBlankA();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
void RESETKATAA();
void STARTKATAA(char s[MaxLengthString]);
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATAA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKataA();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

          
void IgnoreBlankB();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
void RESETKATAB();
void STARTKATAB(char s[MaxLengthString]);
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATAB();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKataB();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

boolean IsSameString(char sA[MaxLengthString], char sB[MaxLengthString]);

boolean IsSameKata(Kata KataA, Kata KataB);

#endif
