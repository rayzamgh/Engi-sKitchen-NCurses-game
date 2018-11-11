/* NIM/Nama  : 13517013 / Aditya Putra Santosa
   Nama File : array.c
   Topik     : ADT ARRAY
   Tanggal   : 11 September 2018
   Deskripsi : implementasi arrray.h */

#include<stdio.h>
#include <stdlib.h>
#include "array.h"
#include "boolean.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyArray (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
  Neff(*T) = 0;
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
  return Neff(T);
}
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
  return IdxMax-IdxMin+1;
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
  return IdxMin;
}
IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
  return Neff(T)+IdxMin-1;
}
/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  return (i>=GetFirstIdx(T) && i<=MaxNbEl(T));
}
boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
  return (i>=GetFirstIdx(T) && i<=GetLastIdx(T));
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArray (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
  return (Neff(T) == 0);
}
/* *** Test tabel penuh *** */
boolean IsFullArray (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
  return (Neff(T) == MaxNbEl(T));
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T) Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
  int n;
  do {
  scanf("%d",&n);
  } while(!(n>=0 && n<=MaxNbEl(*T) ));
  int i;//iterator
  MakeEmptyArray(T);
  for(i=0;i<n;i++){
    int temp;
    scanf("%d",&temp);
    Elmt(*T,IdxMin+i) = temp;
    Neff(*T)++;
  }
}
void BacaIsiTab (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
{
  int i = IdxMin;//Index
  //baca input
  int temp;
  MakeEmptyArray(T);
  scanf("%d",&temp);
  while(temp != -9999 && i<=MaxNbEl(*T)){
    Elmt(*T,i) = temp;
    Neff(*T) = i;
    i++;
    scanf("%d",&temp);
  }
}
void TulisIsi (TabInt T)
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
       printf("[%d]%d\n",i,Elmt(T,i));
     }
  }
}
void TulisIsiTab (TabInt T)
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
      printf("%d,",Elmt(T,i));
    }
    //print elemen terakhir dan siku tutup
    printf("%d]",Elmt(T,Neff(T)));
  }
}
/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
{
  TabInt temp;
  Neff(temp) = Neff(T1);
  int i;//iterator
  for(i=GetFirstIdx(T1);i<=GetLastIdx(T1);i++){
    Elmt(temp,i) = Elmt(T1,i) + Elmt(T2,i);
  }
  return temp;
}
TabInt MinusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
  TabInt temp;
  Neff(temp) = Neff(T1);
  int i;//iterator
  for(i=GetFirstIdx(T1);i<=GetLastIdx(T1);i++){
    Elmt(temp,i) = Elmt(T1,i) - Elmt(T2,i);
  }
  return temp;
}
TabInt KaliTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
{
  TabInt temp;
  Neff(temp) = Neff(T1);
  int i;//iterator
  for(i=GetFirstIdx(T1);i<=GetLastIdx(T1);i++){
    Elmt(temp,i) = Elmt(T1,i) * Elmt(T2,i);
  }
  return temp;
}
TabInt KaliKons (TabInt Tin, ElType c)
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
{
  TabInt temp;
  Neff(temp) = Neff(Tin);
  int i;//iterator
  for(i=GetFirstIdx(Tin);i<=GetLastIdx(Tin);i++){
    Elmt(temp,i) = Elmt(Tin,i) * c;
  }
  return temp;
}
/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQArray (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
  //cek ukuran
  if(Neff(T1)==Neff(T2)){
    //cek elemen
    int i;//iterator
    for(i=GetFirstIdx(T1);i<=GetLastIdx(T1);i++){
      if(Elmt(T1,i)!=Elmt(T2,i)){
        return false;
      }
    }
    //jika sama semua, maka tidak akan pernah dijalankan bagian return falsenya
    //karena berhasil sampai sini, berarti semuanya sama
    return true;
  }else{
    return false;
  }
}
boolean IsLessArray (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */
{
  if(Neff(T1)<Neff(T2)){
    return true;
  }else{
    if(Array(T1,T2)){
      return false;
    }else{
      //iterasi semua
      IdxType i = GetFirstIdx(T2);
      while(Elmt(T1,i)==Elmt(T2,i) && i<=GetLastIdx(T2)){
        i++;
      }
      if(Elmt(T1,i)<Elmt(T2,i)){
        return true;
      }else{
        return false;
      }
    }
  }
}
/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
{
  IdxType i = GetFirstIdx(T);//iterator
  while(i<=GetLastIdx(T) && Elmt(T,i)!=X){
    i++;
  }
  //ketika berhenti, cek apakah berhenti karena habis, atau karena ketemu yang sama
  if(Elmt(T,i)==X && Neff(T)!=0){
    return i;
  }else{
    return IdxUndef;
  }
}
IdxType Search2 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
{
  boolean Found = false;
  IdxType i = GetFirstIdx(T);//iterator
  while(i<=GetLastIdx(T) && !(Found)){
    if(Elmt(T,i)==X){
      Found = true;
    }else{
      i++;
    }
  }
  if(Found){
    return i;
  }else{
    return IdxUndef;
  }
}
boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
{
  boolean Found = false;
  IdxType i = GetFirstIdx(T);//iterator
  while(i<=GetLastIdx(T) && !(Found)){
    if(Elmt(T,i)==X){
      Found = true;
    }else{
      i++;
    }
  }
  return Found;
}
boolean SearchSentinel (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C
   yang tidak dipakai dalam definisi tabel */
{
  boolean ketemu = false;
  IdxType i = GetLastIdx(T);//iterator
  //set sentinel
  Elmt(T,0) = X;
  //cari mundur dari belakang
  while(!ketemu){
    if(Elmt(T,i)==X){
      //ketemu
      ketemu = true;
    }else{
      //cari lagi
      i--;
    }
  }
  if(i==0){
    return false;
  }else{
    return true;
  }
}
/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
  IdxType i;//iterator
  ElType maxi = Elmt(T,GetFirstIdx(T));//pasang elemen paling awal sebagai acuan
  //cek elemen ke 2 hingga akhir
  for(i=GetFirstIdx(T)+1;i<=GetLastIdx(T);i++){
    if(Elmt(T,i)>maxi){
      maxi = Elmt(T,i);
    }
  }
  return maxi;
}
ElType ValMin (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
{
  IdxType i;//iterator
  ElType mini = Elmt(T,GetFirstIdx(T));//pasang elemen paling awal sebagai acuan
  //cek elemen ke 2 hingga akhir
  for(i=GetFirstIdx(T)+1;i<=GetLastIdx(T);i++){
    if(Elmt(T,i)<mini){
      mini = Elmt(T,i);
    }
  }
  return mini;
}
IdxType IdxMaxTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
{
  IdxType i;//iterator
  ElType maxi = Elmt(T,GetFirstIdx(T));//pasang elemen paling awal sebagai acuan
  IdxType idxMax = GetFirstIdx(T);
  //cek elemen ke 2 hingga akhir
  for(i=GetFirstIdx(T)+1;i<=GetLastIdx(T);i++){
    if(Elmt(T,i)>maxi){
      maxi = Elmt(T,i);
      idxMax = i;
    }
  }
  return idxMax;
  return 0;
}
IdxType IdxMinTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */
{
  IdxType i;//iterator
  ElType mini = Elmt(T,GetFirstIdx(T));//pasang elemen paling awal sebagai acuan
  IdxType idxMin = GetFirstIdx(T);
  //cek elemen ke 2 hingga akhir
  for(i=GetFirstIdx(T)+1;i<=GetLastIdx(T);i++){
    if(Elmt(T,i)<mini){
      mini = Elmt(T,i);
      idxMin = i;
    }
  }
  return idxMin;
  return 0;
}
/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout)
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
TabInt InverseTab (TabInt T)
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
  TabInt temp;
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
boolean IsSimetris (TabInt T)
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
{
  //cek KOSONG
  if(Neff(T)==0){
    return true;
  }else{
    TabInt putar = InverseTab(T);
    return Array(T,putar);
  }
}
/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
{
  //cek kosong
  if(Neff(*T)!=0){
    //tidak kosong
    IdxType i;//iterator
    for(i=GetFirstIdx(*T);i<=GetLastIdx(*T);i++){
      //cari nilai maksimum dari indeks i hingga terakhir
      IdxType j;//iterator
      IdxType idxMax = i;
      for(j=i;j<=GetLastIdx(*T);j++){
        if(Elmt(*T,j)>Elmt(*T,idxMax)){
          idxMax = j;
        }
      }
      //swap idxMax dengan i
      ElType temp = Elmt(*T,i);
      Elmt(*T,i) = Elmt(*T,idxMax);
      Elmt(*T,idxMax) = temp;
    }
  }
}
void InsSortAsc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */
{
  //cek KOSONG
  if(Neff(*T)!=0){
    IdxType i;//iterator
    //cek semua elemen dari ke 2 hingga akhir
    //anggap elemen ke 1 sudah benar
    for(i=GetFirstIdx(*T)+1;i<=GetLastIdx(*T);i++){
      IdxType j = i-1;
      ElType temp = Elmt(*T,i);//acuan
      //geser semua elemen dibawah indeks i yang lebih besar daripada Elmt(T,i)
      while(j>=GetFirstIdx(*T) && Elmt(*T,j)>temp){
        Elmt(*T,j+1) = Elmt(*T,j);
        j--;
      }
      //taruh elemen indeks i / acuan tadi di paling kiri setelah geser
      Elmt(*T,j+1) = temp;
    }
  }
}
/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
  Neff(*T)++;
  Elmt(*T,GetLastIdx(*T)) = X;
}
void AddEli (TabInt * T, ElType X, IdxType i)
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
void DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
  if (!Array(*T))
  {
    *X = Elmt(*T, GetLastIdx(*T));
    Neff(*T) -= 1;
  }
}
void DelEli (TabInt * T, IdxType i, ElType * X)
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
/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X)
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T,
        jika belum ada elemen yang bernilai X.
		Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S.
		dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */
{
  //mengunakkan SearchSentinel
  if(!Array(*T)){
    if(SearchSentinel(*T,X)){
      //sudah ada
      printf("nilai sudah ada\n");
    }else{
      AddAsLastEl(T,X);
    }
  }
}
/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X)
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
{
  InsSortAsc(&T);
  return Search1(T,X);
}
ElType MaxUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
{
  InsSortAsc(&T);
  return Elmt(T,GetLastIdx(T));
}
ElType MinUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
{
  InsSortAsc(&T);
  return Elmt(T,GetFirstIdx(T));
}
void MaxMinUrut (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
  *Max = MaxUrut(T);
  *Min = MinUrut(T);
}
void Add1Urut (TabInt * T, ElType X)
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
{
  if(Neff(*T)<MaxNbEl(*T)){
    AddAsLastEl(T,X);
    InsSortAsc(T);
  }
}
void Del1Urut (TabInt * T, ElType X)
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
{
  int posX = Search1(*T,X);
  if(posX!=IdxUndef){
    //ada
    DelEli(T,posX,&Elmt(*T,posX));
    InsSortAsc(T);
  }
}
