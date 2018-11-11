//ADT STAGE GAME
#include "../include/matriks.h"
#include "../include/boolean.h"
#include "../include/stage.h"
#include <stdio.h>

void CreateEmptyStage(TabSTAGE *Tst, int Nb, int Nk, int StageNum)
//inisiasi stage menjadi matriks char BLANK
//stage yang di inisiasi berjumlah StageNum
//Nb, Nk adalah baris dan kolom area, (seluruh area baris dan kolomnya sama)
{
	Neff(*Tst) = StageNum;
	for(int i = 0; i < StageNum; i++)
	{
		MakeMATRIKS(Nb,Nk,&Stage(*Tst,i));
	}
	
}

void PlayerWhere(TabSTAGE Tst, POINT *P, int *StageNo)
//Finalnya :
//P = Posisi char 'P'
//StageNo = Nomor stage yg ada 'P'nya
//kalo ga ketemu, P = (-1,-1)
{
	boolean ketemu = false;
	int count = 0;
	while(count < Neff(Tst) && !ketemu)
	{
		int i = 0;
		while(i < NBrsEff(Stage(Tst,count)) && !ketemu)
		{
			int j = 0;
			while(j < NKolEff(Stage(Tst,count)) && !ketemu)
			{
				if(StageElmt(Tst,count,i,j) == 'P')
				{
					Absis(*P) = i;
					Ordinat(*P) = j;
					ketemu = true;
				}else{
					j++;
				}
			}
			i++;
		}
		count++;
	}
	if(!ketemu)
	{
		//Kalo ga ketemu
		Absis(*P) = -1;
		Ordinat(*P) = -1;
	}
}
