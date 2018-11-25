#include<stdio.h>
#include <stdlib.h>
#include "array.h"
#include "../boolean.h"
#include "../MesinKomparasi/mesinkatakomparasi.h"
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyArray (TabKata * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
  Neff(*T) = 0;
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabKata T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
  return Neff(T);
}
int MaxNbEl (TabKata T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
  return IdxMax-IdxMin+1;
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabKata T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
  return IdxMin;
}
IdxType GetLastIdx (TabKata T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
  return Neff(T)+IdxMin-1;
}
/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabKata T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  return (i>=GetFirstIdx(T) && i<=MaxNbEl(T));
}
boolean IsIdxEff (TabKata T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
  return (i>=GetFirstIdx(T) && i<=GetLastIdx(T));
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArray (TabKata T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
  return (Neff(T) == 0);
}
/* *** Test tabel penuh *** */
boolean IsFullArray (TabKata T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
  return (Neff(T) == MaxNbEl(T));
}
/* ********** TULIS dengan INPUT/OUTPUT device ********** */

void TulisIsi (TabKata T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
{
  //cek KOSONG
  if(Neff(T)==0){
    printf("Tabel kosong\n");
  }else{
    //ada isinya
    int i;//iterator
     for(i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
       printf("[%d]%s\n",i,Elmt(T,i).TabKata);
     }
  }
}
void TulisIsiTab (TabKata T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
  //cek KOSONG
  if(Neff(T)==0){
    printf("[]");
  }else{
    //tidak kosong
    //print siku buka
    printf("[");
    //print elemen ke 1 hingga terakhir-1
    int i;//iterator
    for(i=GetFirstIdx(T);i<GetLastIdx(T);i++){
      printf("%s,",Elmt(T,i).TabKata);
    }
    //print elemen terakhir dan siku tutup
    printf("%s]",Elmt(T,Neff(T)).TabKata);
  }
}
/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabKata T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
{
  IdxType i = GetFirstIdx(T);//iterator
  while(i<=GetLastIdx(T) && !IsSameKata(Elmt(T,i),X)){
    i++;
  }
  //ketika berhenti, cek apakah berhenti karena habis, atau karena ketemu yang sama
  if(IsSameKata(Elmt(T,i),X) && Neff(T)!=0){
    return i;
  }else{
    return IdxUndef;
  }
}
/* ********** OPERASI LAIN ********** */
void CopyTab (TabKata Tin, TabKata * Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
  Neff(*Tout) = Neff(Tin);
  IdxType i;//Iterator
  for(i=GetFirstIdx(Tin);i<=GetLastIdx(Tin);i++){
    Elmt(*Tout,i) = Elmt(Tin,i);
  }
}
TabKata InverseTab (TabKata T)
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
  TabKata temp;
  Neff(temp) = Neff(T);
  //cek KOSONG
  if(Neff(T)==0){
    return temp;//karena temp adalah tabel kosong
  }else{
    //isi temp secara terbalik
    IdxType i;//iterator
    for(i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
      Elmt(temp,Neff(temp)-i+GetFirstIdx(T)) = Elmt(T,i);
    }
    //selesai mengisi
    return temp;
  }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabKata * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
  Neff(*T)++;
  Elmt(*T,GetLastIdx(*T)) = X;
}
void AddEli (TabKata * T, ElType X, IdxType i)
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{
  IdxType j;
  Neff(*T) ++;
  j = GetLastIdx(*T)-1;
  while(j >= i)
  {
    Elmt(*T, j+1) = Elmt(*T, j);
    j -= 1;
  }

  Elmt(*T, i) = X;
}
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabKata * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
  if (!IsEmptyArray(*T))
  {
    *X = Elmt(*T, GetLastIdx(*T));
    Neff(*T) -= 1;
  }
}
void DelEli (TabKata * T, IdxType i, ElType * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
  if (IsIdxEff(*T, i))
  {
    *X = Elmt(*T, i);
    IdxType j;//iterator
    for (j=i; j <= GetLastIdx(*T); j++)
    {
      Elmt(*T, j) = Elmt(*T, j+1);
    }
    Neff(*T) -= 1;
  }
}
