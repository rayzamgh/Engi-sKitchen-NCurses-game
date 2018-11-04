//ADT STAGE GAME
#ifndef MATRIKS_H
#define MATRIKS_H

#include "point.h"
#include "matriks.h"
#include "boolean.h"
#include <stdio.h>

#define BLANK ' '

typedef struct {
	MATRIKS Meme[100];/ //Yang dipake dari STAGE[0], Eg: Stage 0 = kitchen, Stage 1 = Area1 etc.
	int Neff;
}TabSTAGE;

#define Neff(Tst) (Tst).Neff
#define Stage(Tst,i) (Tst).Meme[(i)]
#define StageElmt(Tst,num,i,j) (Tst).Meme[(num)].Mem[(i)][(j)]

void CreateEmpty(TabSTAGE *Tst, int Nb, int Nk, int StageNum);
//inisiasi stage menjadi matriks char BLANK 8x8 di semua area 

void PlayerWhere(TabSTAGE Tst, POINT *P, int *StageNo);
#endif