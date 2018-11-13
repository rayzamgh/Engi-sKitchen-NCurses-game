#include "../include/mesincommand.h"
#include "../include/mesinkatakomparasi.h"

/* State Mesin Kata */
Command CCommand;

void IgnoreBlankInput(){
	while ((CCInput == BLANK) && (CCInput != NEWLINE)){
		ADVINPUT();
	}
}

void IgnoreBlankNewlineInput(){
	while ((CCInput == BLANK) || (CCInput == NEWLINE)){
		ADVINPUT();
	}
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTCOMMAND(){
	STARTINPUT();
	IgnoreBlankNewlineInput();
	SalinCommand();
	IgnoreBlankInput();
}

void ADVCOMMAND(){
	IgnoreBlankNewlineInput();
	SalinCommand();
	IgnoreBlankInput();
}

void SalinCommand(){
	CCommand.Length = 0;
	do{
		if (CCommand.Length < NMax){
			CCommand.TabCommand[CCommand.Length+1] = CCInput;
			CCommand.Length++;
		}
		ADVINPUT();
	} while ((CCInput != BLANK) && (CCInput != NEWLINE));
}
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

boolean CommandIs(char s[10]){
	boolean same = true;
	int i;
	SETSTRINGA(s);
	STARTA();
	if (CKataA.Length != CCommand.Length){
		same = false;
	}
	else{
		i = 1;
		while ((i <= CCommand.Length) && (same)){
			if (CCommand.TabCommand[i] != CKataA.TabKata[i]){
				same = false;
			}
			else{
				i++;
			}
		}
	}
	return same;
}