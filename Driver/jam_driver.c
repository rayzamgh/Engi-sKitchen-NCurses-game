/* 	NIM/Nama : 13517040/Ariel Ansa Razumardi
	Nama file : jam_driver.c
	Topik : Pra Praktikum 02
	Tanggal : 6 September 2018
	Deskripsi : Mengetes semua fungsi dan proseur yang ada pada file jam.h dan jam.c  */

/* Program DriverJam */
/* Mengetes semua fungsi dan proseur yang ada pada file jam.h dan jam.c  */

#include "jam.h"
#include <stdio.h>

int main(){
	// Kamus
	long D;
	int H, M, S, N;
	JAM J1, J2;
	boolean TidakValid = true;
	// Algoritma
	// Pengetesan IsJAMValid, MakeJAM, dan BacaJAM
	printf("Masukan Jam J1 dengan format \"HH MM SS\" tanpa \" (Contoh : 22 33 44) :\n");
	do{
		scanf("%d %d %d", &H, &M, &S);
		if (IsJAMValid(H, M, S)){
			TidakValid = false;
			J1 = MakeJAM(H, M, S);
		}
		else{
			printf("Jam Tidak Valid\n");
		}
	}while(TidakValid);
	printf("Masukan Jam J2 dengan format \"HH MM SS\" tanpa \" (Contoh : 22 33 44) :\n");
	BacaJAM(&J2);
	// Pengetesan TulisJAM
	printf("J1 adalah : ");
	TulisJAM(J1);
	printf("\nJ2 adalah : ");
	TulisJAM(J2);
	// Pengetesan JAMToDetik dan DetikToJAM
	printf("\nJumlah detik dari J1 adalah %ld\n", JAMToDetik(J1));
	printf("Masukan detik D: ");
	scanf("%ld", &D);
	printf("Detik D jika diconvert menjadi jam adalah ");
	TulisJAM(DetikToJAM(D));
	// Pengetesan JEQ, JNEQ, JLT, dan JGT
	if (JEQ(J1,J2)){
		printf("\nJ1 dan J2 merupakan Jam yang sama\n");
	}
	else if(JNEQ(J1,J2)){
		if (JGT(J1,J2)){
			printf("\nJ1 lebih besar daripada J2\n");
		}
		else if(JLT(J1,J2)){
			printf("\nJ2 lebih besar daripada J1\n");
		}
	}
	// Pengetesan NextDetik, NextNDetik, PrevDetik, dan PrevNDetik
	printf("1 detik setelah J1 adalah ");
	TulisJAM(NextDetik(J1));
	printf("\n1 detik sebelum J1 adalah ");
	TulisJAM(PrevDetik(J1));
	printf("\nMasukan N : ");
	scanf("%d", &N);
	printf("%d detik setelah J1 adalah ", N);
	TulisJAM(NextNDetik(J1, N));
	printf("\n%d detik sebelum J1 adalah ", N);
	TulisJAM(PrevNDetik(J1, N));
	// Pengetesan Durasi
	printf("\nDurasi dari J1 ke J2 adalah %ld detik\n", Durasi(J1,J2));
	return 0;
}
