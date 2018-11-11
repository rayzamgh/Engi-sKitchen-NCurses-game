#include "../include/queue.h"
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmptyQueue (Queue Q){
	return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullQueue (Queue Q){
	return (NBElmt(Q) == MaxEl(Q));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (Queue Q){
	if (IsEmptyQueue(Q)){
		return 0;
	}
	else if (Head(Q) > Tail(Q)){
		return (Tail(Q) - Head(Q) + MaxEl(Q) + 1);
	}
	else{
		return (Tail(Q) - Head(Q) + 1);
	}
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmptyQueue (Queue * Q, int Max){
	(*Q).T = (infotype *) malloc ((Max + 1) * sizeof(infotype));
	if ((*Q).T != NULL){
		MaxEl(*Q) = Max;
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
	}
	else{
		MaxEl(*Q) = 0;
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
	}
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(Queue * Q){
	free((*Q).T);
	MaxEl(*Q) = 0;
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X){
	if (IsEmptyQueue(*Q)){
		Head(*Q) = 1;
		Tail(*Q) = 1;
		InfoTail(*Q) = X;
	}
	else if (Tail(*Q) == MaxEl(*Q)){
		Tail(*Q) = 1;
		InfoTail(*Q) = X;
	}
	else{
		Tail(*Q)++;
		InfoTail(*Q) = X;
	}
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
void Del (Queue * Q, infotype * X){
	if (NBElmt(*Q) == 1){
		*X = InfoHead(*Q);
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
	}
	else if (Head(*Q) == MaxEl(*Q)){
		*X = InfoHead(*Q);
		Head(*Q) = 1;
	}
	else{
		*X = InfoHead(*Q);
		Head(*Q)++;
	}
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
