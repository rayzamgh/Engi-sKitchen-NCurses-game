//ADT STAGE GAME
#include "matriks.h"
#include "boolean.h"
#include "stage.h"
#include <stdio.h>

#define BLANK ' '

#define Neff(Tst) (Tst).Neff
#define Stage(Tst,i) (Tst).Meme[(i)]
#define StageElmt(Tst,num,i,j) (Tst).Meme[(num)].Mem[(i)][(j)]

void CreateEmpty(TabSTAGE *Tst,int Nb,int Nk,int StageNum)
//inisiasi stage menjadi matriks char BLANK
//stage yang di inisiasi berjumlah StageNum
//Nb, Nk adalah baris dan kolom area, (seluruh area baris dan kolomnya sama)
{
  Neff(Tst) = StageNum;
  for (int i = 0; i < StageNum; ++i)
  {
  	CreateEmpty(MakeMatriks(Nb, Nk, Stage(*Tst,i)));
  }
}

void PlayerWhere(TabSTAGE Tst, POINT *P, int *StageNo)
//Finalnya :
//P = Posisi char 'P'
//StageNo = Nomor stage yg ada 'P'nya
{
	for (int count = 0; count < Neff(Tst); ++i)
	{
		for (int i = 0; i < NBrsEff(Stage(Tst,count)); ++i)
		{
			for (int j = 0; i < NKolEff(Stage(Tst,count)); ++j)
			{
				if(StageElmt(Tst,Stage(Tst,count),i,j) == 'P'){
					*StageNo 	= Stage(Tst,count);
					Absis(*P)	= i;
					Ordinat(*P) = j;
				}
			}
		}
	}
}

