#include "../include/queue.h"
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmptyQueue (Queue Q){
	return ((Head(Q) == NilQueue) && (Tail(Q) == NilQueue));
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullQueue (Queue Q){
	return (NBElmt(Q) == MaxElQueue(Q));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxElQueue */
int NBElmt (Queue Q){
	if (IsEmptyQueue(Q)){
		return 0;
	}
	else if (Head(Q) > Tail(Q)){
		return (Tail(Q) - Head(Q) + MaxElQueue(Q) + 1);
	}
	else{
		return (Tail(Q) - Head(Q) + 1);
	}
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmptyQueue (Queue * Q, int Max){
	(*Q).T = (infotypeQueue *) malloc ((Max + 1) * sizeof(infotypeQueue));
	if ((*Q).T != NULL){
		MaxElQueue(*Q) = Max;
		Head(*Q) = NilQueue;
		Tail(*Q) = NilQueue;
	}
	else{
		MaxElQueue(*Q) = 0;
		Head(*Q) = NilQueue;
		Tail(*Q) = NilQueue;
	}
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxElQueue=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(Queue * Q){
	free((*Q).T);
	MaxElQueue(*Q) = 0;
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxElQueue(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotypeQueue X){
	if (IsEmptyQueue(*Q)){
		Head(*Q) = 1;
		Tail(*Q) = 1;
		InfoTail(*Q) = X;
	}
	else if (Tail(*Q) == MaxElQueue(*Q)){
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
void Del (Queue * Q, infotypeQueue * X){
	if (NBElmt(*Q) == 1){
		*X = InfoHead(*Q);
		Head(*Q) = NilQueue;
		Tail(*Q) = NilQueue;
	}
	else if (Head(*Q) == MaxElQueue(*Q)){
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
/* F.S. X = NilQueueai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
