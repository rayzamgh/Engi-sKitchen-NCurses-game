#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"
#include "array.h"
#define BLANK ' '

//VARIABEL GLOBAL
//J

void GU(MATRIKS *M, Point *P, JAM *J){
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
void GD(MATRIKS *M, Point *P, JAM *J){
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

void GL(MATRIKS *M, Point *P, JAM *J){
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
void GR(MATRIKS *M, Point *P, JAM *J){
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