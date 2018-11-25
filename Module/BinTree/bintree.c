
#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "../MesinKomparasi/mesinkatakomparasi.h"


/* *** Konstruktor *** */
BinTree Tree(infotypeLR Akar, BinTree L, BinTree R)
{
  addrNode P = AlokNode(Akar);
  if (P != Nil)
  {
    BinTree T = P;
    Left(P) = L;
    Right(P) = R;
    return T;
  }
  else
  {
    return Nil;
  }
}
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
void MakeTree(infotypeLR Akar, BinTree L, BinTree R, BinTree *P)
{
  BinTree T = Tree(Akar, L, R);
  *P = T;
}
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = Nil jika alokasi gagal. */

/* Manajemen Memory */
addrNode AlokNode(infotypeLR X)
{
  addrNode P = (addrNode)malloc(sizeof(Node));
  if (P != Nil)
  {
    Akar(P) = X;
    Left(P) = Nil;
    Right(P) = Nil;
    return P;
  }
  else
  {
    return Nil;
  }
}
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokNode(addrNode P)
{
  free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P)
{
  return P == Nil;
}
/* Mengirimkan true jika P adalah pohon biner kosong */
boolean IsTreeOneElmt(BinTree P)
{
  return (P != Nil) && (Left(P) == Nil && Right(P) == Nil);
}
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
boolean IsUnerLeft(BinTree P)
{
  return (P != Nil) && (Left(P) != Nil && Right(P) == Nil);
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
boolean IsUnerRight(BinTree P)
{
  return (P != Nil) && (Left(P) == Nil && Right(P) != Nil);
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
boolean IsBiner(BinTree P)
{
  return (P != Nil) && (Left(P) != Nil && Right(P) != Nil);
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
BinTree PreOrderToTree(char s[500], int *pos)
{
  /* CTH : A(B()())(C()()) */
  /* CFG :
   *  S -> R(S)(S) | R()() | R(S)() | R()(S)
   */
  BinTree Hasil;
  /* Salin Nama Root */
  char namaRoot[50] = "";
  int i = 0;
  while (s[*pos] != '(' && s[*pos] != ')')
  {
    namaRoot[i] = s[*pos];
    i += 1;
    *pos += 1;
  }
  STARTKATAA(namaRoot); //Input namaRoot ke CKataA
  Hasil = Tree(CKataA, Nil, Nil);
  if (s[*pos + 1] == ')')
  {
    // R()() | R()(S)
    *pos += 2;
    if (s[*pos + 1] == ')')
    {
      // R()()
      *pos += 2;
      return Hasil;
    }
    else
    {
      // R()(S)
      *pos += 1;
      Right(Hasil) = PreOrderToTree(s, pos);
      *pos += 1;
      return Hasil;
    }
  }
  else
  {
    // R(S)(S) | R(S)()
    *pos += 1;
    Left(Hasil) = PreOrderToTree(s, pos);
    *pos += 1;
    if (s[*pos + 1] == ')')
    {
      // R(S)()
      *pos += 2;
      return Hasil;
    }
    else
    {
      // R(S)(S)
      *pos += 1;
      Right(Hasil) = PreOrderToTree(s, pos);
      *pos += 1;
      return Hasil;
    }
  }
}
/* Membuat pohon dari representasi preorder tree */
/* *** Traversal *** */
void PrintPreorder(BinTree P)
{
  printf("(");
  if (!IsTreeEmpty(P))
  {
    int i = 0;
    printf("%s", Akar(P).TabKata);
    PrintPreorder(Left(P));
    PrintPreorder(Right(P));
  }
  printf(")");
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
void PrintTree(BinTree P, int h)
{
  if (!IsTreeEmpty(P))
  {
    printf("%s\n", Akar(P).TabKata);
    if (Left(P) != Nil)
    {
      for (int i = 0; i < h; i++)
      {
        printf(" ");
      }
      PrintTree(Left(P), h + h / 2);
    }
    if (Right(P) != Nil)
    {
      for (int i = 0; i < h; i++)
      {
        printf(" ");
      }
      PrintTree(Right(P), h + h / 2);
    }
  }
}
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/

/* *** Searching *** */
boolean SearchTree(BinTree P, infotypeLR X)
{
  if (!IsTreeEmpty(P))
  {
    if (IsSameString(Akar(P).TabKata, X.TabKata))
    {
      return true;
    }
    else
    {
      return SearchTree(Left(P), X) || SearchTree(Right(P), X);
    }
  }
  else
  {
    return false;
  }
}
/* Mengirimkan true jika ada node dari P yang bernilai X */

/* *** Fungsi-Fungsi Lain *** */
int NbElmtTree(BinTree P)
{
  if (IsTreeEmpty(P))
  {
    return 0;
  }
  else
  {
    return 1 + NbElmtTree(Left(P)) + NbElmtTree(Right(P));
  }
}
/* Mengirimkan banyaknya elemen (node) pohon biner P */
int NbDaun(BinTree P)
{
  if (IsTreeOneElmt(P))
  {
    return 1;
  }
  else
  {
    if (IsUnerLeft(P))
    {
      return NbDaun(Left(P));
    }
    else if (IsUnerRight(P))
    {
      return NbDaun(Right(P));
    }
    else if (IsBiner(P))
    {
      return NbDaun(Left(P)) + NbDaun(Right(P));
    }
  }
}
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
int Level(BinTree P, infotypeLR X)
{
  if (IsTreeOneElmt(P) || IsSameString(Akar(P).TabKata, X.TabKata))
  {
    return 1;
  }
  else
  {
    if (SearchTree(Left(P), X))
    {
      return 1 + Level(Left(P), X);
    }
    else if (SearchTree(Right(P), X))
    {
      return 1 + Level(Right(P), X);
    }
  }
}
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. 
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
infotypeLR GetDaunAcak(BinTree P)
{
  if (IsTreeOneElmt(P))
  {
    return Akar(P);
  }
  else
  {
    int num = (rand() % 2);
    if (num == 1)
    {
      if (Right(P) != Nil)
      {
        return GetDaunAcak(Right(P));
      }
      else
      {
        return GetDaunAcak(Left(P));
      }
    }
    if (num == 0)
    {
      if (Left(P) != Nil)
      {
        return GetDaunAcak(Left(P));
      }
      else
      {
        return GetDaunAcak(Right(P));
      }
    }
  }
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P 
   yang levelnya=N, jika semua alokasi berhasil. 
   Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */