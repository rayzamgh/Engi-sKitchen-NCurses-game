#include "jam.h"
#include <stdio.h>

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M, int S){
	return ((H>=0)&&(H<=23)&&(M>=0)&&(M<=59)&&(S>=0)&&(S<=59));
}
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS){
	JAM J;
	Hour(J) = HH;
	Minute(J) = MM;
	Second(J) = SS;
	return J;
}
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J){
	boolean TidakValid = true;
	do{
		scanf("%d %d %d", &Hour(*J), &Minute(*J), &Second(*J));
		if (IsJAMValid(Hour(*J), Minute(*J), Second(*J))){
			TidakValid = false;
		}
		else{
			printf("Jam tidak valid\n");
		}
	}while(TidakValid);
}
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */

void TulisJAM (JAM J){
	printf("%d:%d:%d", Hour(J), Minute(J), Second(J));
}
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik (JAM J){
	return (3600*Hour(J) + 60*Minute(J) + Second(J));
}
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */

JAM DetikToJAM (long N){
	JAM J;
	N = N % 86400;
	Hour(J) = N / 3600;
	Minute(J) = (N % 3600) / 60;
	Second(J) = (N % 3600) % 60;
	return J;
}
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2){
	return ((Hour(J1)==Hour(J2))&&(Minute(J1)==Minute(J2))&&(Second(J1)==Second(J2)));
}
/* Mengirimkan true jika J1=J2, false jika tidak */
boolean JNEQ (JAM J1, JAM J2){
	return !((Hour(J1)==Hour(J2))&&(Minute(J1)==Minute(J2))&&(Second(J1)==Second(J2)));
}
/* Mengirimkan true jika J1 tidak sama dengan J2 */
boolean JLT (JAM J1, JAM J2){
	if (Hour(J1) == Hour(J2)){
		if(Minute(J1) == Minute(J2)){
			return (Second(J1)<Second(J2));
		}
		else{
			return (Minute(J1)<Minute(J2));
		}
	}
	else{
		return (Hour(J1)<Hour(J2));
	}
}
/* Mengirimkan true jika J1<J2, false jika tidak */
boolean JGT (JAM J1, JAM J2){
	if (Hour(J1) == Hour(J2)){
		if(Minute(J1) == Minute(J2)){
			return (Second(J1)>Second(J2));
		}
		else{
			return (Minute(J1)>Minute(J2));
		}
	}
	else{
		return (Hour(J1)>Hour(J2));
	}
}
/* Mengirimkan true jika J1>J2, false jika tidak */
/* *** Operator aritmatika JAM *** */
JAM NextDetik (JAM J){
	if (Second(J) == 59){
		Second(J) = 0;
		if (Minute(J) == 59){
			Minute(J) = 0;
			if (Hour(J) == 23){
				Hour(J) = 0;
			}
			else{
				Hour(J) += 1;
			}
		}
		else{
			Minute(J) += 1;
		}
	}
	else{
		Second(J) += 1;
	}
	return J;
}
/* Mengirim 1 detik setelah J dalam bentuk JAM */
JAM NextNDetik (JAM J, int N){
	int i;
	for (i=1; i<=N; i++){
		J = NextDetik(J);
	}
	return J;
}
/* Mengirim N detik setelah J dalam bentuk JAM */
JAM PrevDetik (JAM J){
	if (Second(J) == 0){
		Second(J) = 59;

		if (Minute(J) == 0){
			Minute(J) = 59;
			if (Hour(J) == 0){
				Hour(J) = 23;
			}
			else{
				Hour(J) -= 1;
			}
		}
		else{
			Minute(J) -= 1;
		}
	}
	else{
		Second(J) -= 1;
	}
	return J;
}
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
JAM PrevNDetik (JAM J, int N){
	int i;
	for (i=1; i<=N; i++){
		J = PrevDetik(J);
	}
	return J;
}
/* Mengirim N detik sebelum J dalam bentuk JAM */
/* *** Kelompok Operator Aritmetika *** */
long Durasi (JAM JAw, JAM JAkh){
	if (JGT(JAw, JAkh)){
		return(86400 + JAMToDetik(JAkh) - JAMToDetik(JAw));
	}
	else{
		return(JAMToDetik(JAkh) - JAMToDetik(JAw));
	}
}
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
