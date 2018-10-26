#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"
#include "array.h"
#define BLANK ' '

void GU(MATRIKS *M, Point *P){
	int i = Absis(*P);
	int j = Ordinat(*P);
	if(i != 1){
		if(Elmt(*M, i-1, j) == BLANK){
			Elmt(*M, i, j) = BLANK;
			Elmt(*M, i-1, j) = 'P';
			Absis(*P) = i-1;
		}
	}
}
void GD(MATRIKS *M, Point *P){
	int i = Absis(*P);
	int j = Ordinat(*P);
	if(i != NBrsEff(*M)){
		if(Elmt(*M, i+1, j) == BLANK){
			Elmt(*M, i, j) = BLANK;
			Elmt(*M, i+1, j) = 'P';
			Absis(*P) = i+1;
		}
	}
}

void GL(MATRIKS *M, Point *P){
	int i = Absis(*P);
	int j = Ordinat(*P);
	if(j != 1){
		if(Elmt(*M, i, j-1) == BLANK){
			Elmt(*M, i, j) = BLANK;
			Elmt(*M, i, j-1) = 'P';
			Ordinat(*P) = j-1;
		}
	}
}
void GR(MATRIKS *M, Point *P){
	int i = Absis(*P);
	int j = Ordinat(*P);
	if(j != NKolEff(*M)){
		if(Elmt(*M, i, j+1) == BLANK){
			Elmt(*M, i, j) = BLANK;
			Elmt(*M, i, j+1) = 'P';
			Ordinat(*P) = j+1;
		}
	}
}