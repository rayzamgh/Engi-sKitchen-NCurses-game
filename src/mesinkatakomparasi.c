#include "../include/mesinkatakomparasi.h"
#include <stdio.h>
/* State Mesin Kata */
boolean EndKataA;
Kata CKataA;

boolean EndKataB;
Kata CKataB;

void IgnoreBlankA()
{
	while ((CCA == BLANK) && (CCA != MARK))
	{
		ADVA();
	}
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void RESETKATAA()
{
	int i = 0;
	while(CKataA.TabKata[i] != '\000')
	{
		CKataA.TabKata[i] = '\000';
		i += 1;
	}
}

void STARTKATAA(char s[MaxLengthString])
{
	RESETKATAA();
	SETSTRINGA(s);
	STARTA();
	IgnoreBlankA();
	if (CCA == MARK)
	{
		EndKataA = true;
	}
	else
	{
		SalinKataA();
		EndKataA = false;
	}
}
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATAA()
{
	IgnoreBlankA();
	if (CCA == MARK)
	{
		EndKataA = true;
	}
	else
	{
		SalinKataA();
		IgnoreBlankA();
	}
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKataA()
{

	CKataA.Length = 0;
	do
	{
		if (CKataA.Length < NMax)
		{
			CKataA.TabKata[CKataA.Length] = CCA;
			CKataA.Length++;
		}
		ADVA();
	} while ((CCA != BLANK) && (CCA != MARK));
}
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void IgnoreBlankB()
{
	while ((CCB == BLANK) && (CCB != MARK))
	{
		ADVB();
	}
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void RESETKATAB()
{
	int i = 0;
	while (CKataB.TabKata[i] != '\000')
	{
		CKataB.TabKata[i] = '\000';
		i += 1;
	}
}

void STARTKATAB(char s[MaxLengthString])
{
	RESETKATAB();
	SETSTRINGB(s);
	STARTB();
	IgnoreBlankB();
	if (CCB == MARK)
	{
		EndKataB = true;
	}
	else
	{
		SalinKataB();
		EndKataB = false;
	}
}
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATAB()
{
	IgnoreBlankB();
	if (CCB == MARK)
	{
		EndKataB = true;
	}
	else
	{
		SalinKataB();
		IgnoreBlankB();
	}
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKataB()
{

	CKataB.Length = 0;
	do
	{
		if (CKataB.Length < NMax)
		{
			CKataB.TabKata[CKataB.Length] = CCB;
			CKataB.Length++;
		}
		ADVB();
	} while ((CCB != BLANK) && (CCB != MARK));
}
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

boolean IsSameString(char sA[MaxLengthString], char sB[MaxLengthString])
{
	boolean same = true;
	STARTKATAA(sA);
	STARTKATAB(sB);
	while ((!EndKataA) && (!EndKataB) && same)
	{
		if (!IsSameKata(CKataA, CKataB))
		{
			same = false;
		}
		else
		{
			ADVKATAA();
			ADVKATAB();
		}
	}
	if ((!EndKataA) || (!EndKataB))
	{
		same = false;
	}
	return same;
}

boolean IsSameKata(Kata KataA, Kata KataB)
{
	boolean same = true;
	if (KataA.Length != KataB.Length)
	{
		same = false;
	}
	else
	{
		for (int i = 0; (i <= KataA.Length) && (same); i++)
		{
			if (CKataA.TabKata[i] != CKataB.TabKata[i])
			{
				same = false;
			}
		}
	}
	return same;
}
