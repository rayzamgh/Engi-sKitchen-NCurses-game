#include "../include/listdp.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L){
    return ((First(L) == Nil) && (Last(L) ==Nil));
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L){
    First(*L) = Nil;
    Last(*L) = Nil;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
    address P = malloc (sizeof(infotype));
    if (P != Nil){
        Info(P) = X;
        Next(P) = Nil;
        Prev(P) = Nil;
    }
    return P;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi (address P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
    address P;
    boolean found;
    P = First(L);
    if (!IsEmptyList(L)){
        found = (Info(P) == X);
        while ((!found) && (Next(P) != Nil)){
            P = Next(P);
            if (Info(P) == X){
                found = true;
            }
        }
        if (!found){
            P = Nil;
        }
    }
    return P;
}
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
    address P;
    P = Alokasi(X);
    if (P != Nil){
        if (IsEmptyList(*L)){
            First(*L) = P;
            Last(*L) = P;
        }
        else{
            Next(P) = First(*L);
            Prev(First(*L)) = P;
            First(*L) = P;
        }
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
    address P;
    P = Alokasi(X);
    if (P != Nil){
        if (IsEmptyList(*L)){
            First(*L) = P;
            Last(*L) = P;
        }
        else{
            Next(Last(*L)) = P;
            Prev(P) = Last(*L);
            Last(*L) = P;
        }
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
    address P;
    P = First(*L);
    First(*L) = Next(P);
    if (First(*L) == Nil){
        Last(*L) = Nil;
    }
    else{
        Prev(First(*L)) = Nil;
        Next(P) = Nil;
    }
    *X = Info(P);
    Dealokasi(P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
    address P;
    P = Last(*L);
    Last(*L) = Prev(P);
    if (Last(*L) == Nil){
        First(*L) = Nil;
    }
    else{
        Next(Last(*L)) = Nil;
        Prev(P) = Nil;
    }
    *X = Info(P);
    Dealokasi(P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    if (IsEmptyList(*L)){
        First(*L) = P;
        Last(*L) = P;
    }
    else{
        Next(P) = First(*L);
        Prev(First(*L)) = P;
        First(*L) = P;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P){
    if (IsEmptyList(*L)){
        First(*L) = P;
        Last(*L) = P;
    }
    else{
        Next(Last(*L)) = P;
        Prev(P) = Last(*L);
        Last(*L) = P;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec){
    if (Prec == Last(*L)){
        InsertLast(L, P);
    }
    else{
        Next(P) = Next(Prec);
        Prev(P) = Prec;
        Next(Prec) = P;
        Prev(Next(P)) = P;
    }
}
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore (List *L, address P, address Succ){
    if (Succ == First(*L)){
        InsertFirst(L, P);
    }
    else{
        Prev(P) = Prev(Succ);
        Next(P) = Succ;
        Prev(Succ) = P;
        Next(Prev(P)) = P;
    }
}
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    *P = First(*L);
    First(*L) = Next(*P);
    if (First(*L) == Nil){
        Last(*L) = Nil;
    }
    else{
        Prev(First(*L)) = Nil;
        Next(*P) = Nil;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P){
    *P = Last(*L);
    Last(*L) = Prev(*P);
    if (Last(*L) == Nil){
        First(*L) = Nil;
    }
    else{
        Next(Last(*L)) = Nil;
        Prev(*P) = Nil;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelP (List *L, infotype X){
    //kamus
    address Pdel, P;
    //algoritma
    if (Search(*L, X) != Nil){
        if (First(*L) == Search(*L,X)){
            DelFirst(L, &Pdel);
        }
        else{
            P = First(*L);
            while(Next(P) != Search(*L,X)){
                P = Next(P);
            }
            DelAfter(L, &Pdel, P);
        }
        Dealokasi(Pdel);
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    if (Next(Prec) != Nil){
        if (*Pdel == Last(*L)){
            DelLast(L, Pdel);
        }
        else{
            Next(Prec) = Next(*Pdel);
            Next(*Pdel) = Nil;
            Prev(Next(Prec)) = Prec;
            Prev(*Pdel) = Nil;
        }
    }
}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBefore (List *L, address *Pdel, address Succ){
    *Pdel = Prev(Succ);
    if (Prev(Succ) != Nil){
        if (*Pdel == First(*L)){
            DelFirst(L, Pdel);
        }
        else{
            Prev(Succ) = Prev(*Pdel);
            Prev(*Pdel) = Nil;
            Next(Prev(Succ)) = Succ;
            Next(*Pdel) = Nil;
        }
    }
}
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L){
    address P;
    printf("[");
    if (!IsEmptyList(L)){
        P = First(L);
        while (Next(P) != Nil){
            printf("%d,", Info(P));
            P = Next(P);
        }
        printf("%d", Info(P));
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackward (List L){
    address P;
    printf("[");
    if (!IsEmptyList(L)){
        P = Last(L);
        while (Prev(P) != Nil){
            printf("%d,", Info(P));
            P = Prev(P);
        }
        printf("%d", Info(P));
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
