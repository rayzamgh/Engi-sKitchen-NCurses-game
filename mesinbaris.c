
#include "mesinbaris.h"

/* State Mesin Baris */
boolean EndBaris;
Baris CBaris;

void IgnoreNewline(){
	while ((CC == NEWLINE) && (CC != MARK)){
		ADV();
	} 
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTBARIS(char filename[20]){
	START(filename);
	IgnoreNewline();
	if (CC == MARK){
		EndBaris = true;
	}
	else{
		SalinBaris();
		EndBaris = false;
	}
}
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVBARIS(){
	IgnoreNewline();
	if (CC == MARK){
		EndBaris = true;
	}
	else{
		SalinBaris();
	}
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinBaris(){
	CBaris.Length = 0;
	do{
		if (CBaris.Length < NMax){
			CBaris.TabBaris[CBaris.Length + 1] = CC;
			CBaris.Length++;
		}
		ADV();
	} while ((CC != NEWLINE) && (CC != MARK));
}
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
