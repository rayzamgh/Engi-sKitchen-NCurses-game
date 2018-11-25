/* File: listRekrek.h */
/* ADT listRek linier dengan representasi pointer */
/* Implementasi listRek linier secara rekursif */

#ifndef _LISTREK_H_
#define _LISTREK_H_

#include "boolean.h"
#include "mesinkatakomparasi.h"

#define Nil NULL

/* Definisi Type */
typedef Kata infotypeLR;
typedef struct tElmtlistRek *addressListRek;
typedef struct tElmtlistRek { 
	infotypeLR info;
	addressListRek next;
} ElmtListRek;

/* Definisi listRek : */
/* ListRek kosong : L = Nil */
typedef addressListRek ListRek;

/* Deklarasi  nama untuk variabel kerja */ 
/*  	L : ListRek */
/*  	P : addressListRek 	*/
/* Maka penulisan First(L) menjadi L */
/*                P.info menjadi Info(P); P.next menjadi Next(P) */

/* Selektor */
#define InfoListRek(P) (P)->info
#define NextListRek(P) (P)->next

/* *** Manajemen Memori *** */
addressListRek AlokasiListRek (infotypeLR X);
/* Mengirimkan addressListRek hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressListRek tidak Nil, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokasiListRek (addressListRek P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressListRek P */

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi ListRek */
int IsEmptyListRek(ListRek L);
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
int IsOneElmtListRek(ListRek L);
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */

/* *** Selektor *** */
infotypeLR FirstElmtListRek (ListRek L);
/* Mengirimkan elemen pertama sebuah listRek L yang tidak kosong */
ListRek TailListRek(ListRek L);
/* Mengirimkan listRek L tanpa elemen pertamanya, mungkin menjadi listRek kosong */

/* *** Konstruktor *** */
ListRek KonsoListRek(infotypeLR e, ListRek L);
/* Mengirimkan listRek L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
ListRek KonsBListRek(ListRek L, infotypeLR e);
/* Mengirimkan listRek L dengan tambahan e sebagai elemen pertamanya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 

/* *** Operasi Lain *** */
ListRek CopyListRek (ListRek L);
/* Mengirimkan salinan listRek L (menjadi listRek baru) */
/* Jika ada alokasi gagal, mengirimkan L */ 
void MCopyListRek (ListRek Lin, ListRek *Lout);
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
ListRek ConcatListRek (ListRek L1, ListRek L2);
/* Mengirimkan salinan hasil konkatenasi listRek L1 dan L2 (menjadi listRek baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */
void MConcatListRek (ListRek L1, ListRek L2, ListRek *LHsl);
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi listRek L1 dan L2 */
void PrintListRek (ListRek L);
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen listRek dicetak. */
int NbElmtListRek (ListRek L);
/* Mengirimkan banyaknya elemen listRek L, Nol jika L kosong */
boolean SearchListRek (ListRek L, infotypeLR X);
/* Mengirim true jika X adalah anggota listRek, false jika tidak */

#endif