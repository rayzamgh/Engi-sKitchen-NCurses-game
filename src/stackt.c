#include "../include/stackt.h"
#include <stdio.h>

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S){
    Top(*S) = NilStack;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElStack */
/* jadi indeksnya antara 1.. MaxElStack+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilStackai NilStack */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack (Stack S){
    return (Top(S) == NilStack);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStack (Stack S){
    return (Top(S) == MaxElStack); 
}
/* Mengirim true jika tabel penampung nilStackai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infotypeStack X){
    Top(*S)++;
    InfoTop(*S) = X; 
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infotypeStack* X){
    *X = InfoTop(*S);
    Top(*S)--; 
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilStackai elemen TOP yang lama, TOP berkurang 1 */