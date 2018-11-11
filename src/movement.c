#include <stdio.h>
#include <stdlib.h>
#include "../include/matriks.h"
#include "../include/point.h"
#include "../include/jam.h"

#define BLANK ' '

//VARIABEL GLOBAL
//J

void GoUp(MATRIKS *M, POINT *P, JAM *J){
	int i = Absis(*P);
	int j = Ordinat(*P);
	if(i != 1){
		if(Elmt(*M, i-1, j) == BLANK){
			//BEGERAK KE ATAS
			Elmt(*M, i, j) = BLANK;
			Elmt(*M, i-1, j) = 'P';
			Absis(*P) = i-1;
			*J = NextDetik(*J);
		}
	}
}
void GoDown(MATRIKS *M, POINT *P, JAM *J){
	int i = Absis(*P);
	int j = Ordinat(*P);
	if(i != NBrsEff(*M)){
		if(Elmt(*M, i+1, j) == BLANK){
			//BEGERAK KE BAWAH
			Elmt(*M, i, j) = BLANK;
			Elmt(*M, i+1, j) = 'P';
			Absis(*P) = i+1;
			*J = NextDetik(*J);
		}
	}
}

void GoLeft(MATRIKS *M, POINT *P, JAM *J){
	int i = Absis(*P);
	int j = Ordinat(*P);
	if(j != 1){
		if(Elmt(*M, i, j-1) == BLANK){
			//BEGERAK KE KIRI
			Elmt(*M, i, j) = BLANK;
			Elmt(*M, i, j-1) = 'P';
			Ordinat(*P) = j-1;
			*J = NextDetik(*J);
		}
	}
}
void GoRight(MATRIKS *M, POINT *P, JAM *J){
	int i = Absis(*P);
	int j = Ordinat(*P);
	if(j != NKolEff(*M)){
		if(Elmt(*M, i, j+1) == BLANK){
			//BEGERAK KE KANAN
			Elmt(*M, i, j) = BLANK;
			Elmt(*M, i, j+1) = 'P';
			Ordinat(*P) = j+1;
			*J = NextDetik(*J);
		}
	}
}