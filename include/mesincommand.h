/* File: mesincommand.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINCOMMAND_H__
#define __MESINCOMMAND_H__

#include "boolean.h"
#include "mesinkarinput.h"

#define NMax 10
#define BLANK ' '
#define NEWLINE '\n'

typedef struct {
	char TabCommand[NMax];
    int Length; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
} Command;

/* State Mesin Kata */
extern Command CCommand;

void IgnoreBlankInput();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
   
void IgnoreBlankNewlineInput();

void STARTCOMMAND();

void ADVCOMMAND();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */


void SalinCommand();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
boolean CommandIs(char s[]);

#endif
