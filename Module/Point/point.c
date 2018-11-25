#include "point.h"
#include <stdio.h>

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT(int X, int Y)
{
	POINT P;
	Absis(P) = X;
	Ordinat(P) = Y;
	return P;
}
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean PointEQ(POINT P1, POINT P2)
{
	return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX(POINT P)
{
	Absis(P) += 1;
	return P;
}
/* Mengirim salinan P dengan absis ditambah satu */
POINT NextY(POINT P)
{
	Ordinat(P) += 1;
	return P;
}
/* Mengirim salinan P dengan ordinat ditambah satu */
POINT PrevX(POINT P)
{
	Absis(P) -= 1;
	return P;
}
/* Mengirim salinan P dengan absis dikurang satu */
POINT PrevY(POINT P)
{
	Ordinat(P) -= 1;
	return P;
}
/* Mengirim salinan P dengan ordinat dikurang satu */
