/* 	NIM/Nama : 13517040/Ariel Ansa Razumardi
	Nama file : point_driver.c
	Topik : Pra Praktikum 02
	Tanggal : 6 September 2018
	Deskripsi : Mengetes semua fungsi dan proseur yang ada pada file point.h dan point.c  */

/* Program DriverPoint */
/* Mengetes semua fungsi dan proseur yang ada pada file point.h dan point.c  */

#include "point.h"
#include <stdio.h>

int main(){
	// Kamus
	POINT P1, P2, Ptemp;
	float absis, ordinat, dx, dy, sudut;
	// Algoritma
	// Pengetesan MakePOINT, BacaPOINT, dan TulisPOINT
	printf("Masukan Point P1 dengan format 'Absis Ordinat' tanpa '' (Ex: 1 2) : ");
	scanf("%f %f", &absis, &ordinat);
	P1 = MakePOINT(absis, ordinat);
	printf("Masukan Point P2 dengan format 'Absis Ordinat' tanpa '' (Ex: 1 2) : ");
	BacaPOINT(&P2);
	printf("P1 adalah : ");
	TulisPOINT(P1);
	printf("\nP2 adalah : ");
	TulisPOINT(P2);
	// Pengetesan EQ dan NEQ
	if (EQ(P1,P2)){
		printf("\nP1 dan P2 merupakan titik yang sama\n");
	}
	else if (NEQ(P1,P2)){
		printf("\nP1 dan P2 bukan merupakan titik yang sama\n");
	}
	// Pengetesan IsOrigin, IsOnSbX, IsOnSbY, dan Kuadran
	if (IsOrigin(P1)){
		printf("P1 merupakan titik origin (0,0)\n");
	}
	else if(IsOnSbX(P1)){
		printf("P1 berada pada sumbu X\n");
	}
	else if(IsOnSbY(P1)){
		printf("P1 berada pada sumbu Y\n");
	}
	else{
		printf("P1 berada pada kuadran ke-%d\n", Kuadran(P1));
	}
	// Pengecekan NextX, NextY, PlusDelta, dan Geser
	printf("P1 jika absisnya ditambah 1 akan menjadi: ");
	TulisPOINT(NextX(P1));
	printf("\nP1 jika ordinatnya ditambah 1 akan menjadi: ");
	TulisPOINT(NextY(P1));
	printf("\nMasukan dx dan dy dengan format 'dx dy': ");
	scanf("%f %f", &dx, &dy);
	printf("P1 jika ditambahkan absisnya dengan %.2f dan ordinatnya dengan %.2f akan menjadi: ", dx, dy);
	TulisPOINT(PlusDelta(P1, dx, dy));
	printf("\nP1 jika ditambahkan absisnya dengan %.2f dan ordinatnya dengan %.2f akan menjadi: ", dy, dx);
	Ptemp = MakePOINT(Absis(P1), Ordinat(P1));
	Geser(&Ptemp, dy, dx);
	TulisPOINT(Ptemp);
	// Pengecekan Mirror dan MirrorOf
	printf("\nP1 jika dicerminkan terhadap sumbu x akan menjadi: ");
	TulisPOINT(MirrorOf(P1, true));
	printf("\nP1 jika dicerminkan terhadap sumbu y akan menjadi: ");
	Ptemp = MakePOINT(Absis(P1), Ordinat(P1));
	Mirror(&Ptemp, false);
	TulisPOINT(Ptemp);
	// Pengecekan Jarak0 dan Panjang
	printf("\nJarak titik P1 dan titik Origin adalah: %f\n", Jarak0(P1));
	printf("Jarak titik P1 dan titik P2 adalah: %f\n", Panjang(P1, P2));
	// Pengecekan GeserKeSbX dan GeserKeSbY
	printf("P1 jika digeser ke sumbu x akan menjadi: ");
	Ptemp = MakePOINT(Absis(P1), Ordinat(P1));
	GeserKeSbX(&Ptemp);
	TulisPOINT(Ptemp);
	printf("\nP1 jika digeser ke sumbu y akan menjadi: ");
	Ptemp = MakePOINT(Absis(P1), Ordinat(P1));
	GeserKeSbY(&Ptemp);
	TulisPOINT(Ptemp);
	// Pengecekan Putar
	printf("\nMasukan Sudut: ");
	scanf("%f", &sudut);
	printf("P1 jika diputar berlawanan arah jarum jam dengan pusat titik origin sebesar %f derajat akan menjadi: ", sudut);
	Ptemp = MakePOINT(Absis(P1), Ordinat(P1));
	Putar(&Ptemp, sudut);
	TulisPOINT(Ptemp);
	printf("\n");
	return 0;
}
