#include "../include/listrek.h"
#include "../include/bintree.h"
#include <stdio.h>
#include <stdlib.h>
#include "../include/boolean.h"

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
BinTree BuildBalanceTree(int n)
{
  if (n == 0)
  {
    return Nil;
  }
  else
  {
    int input;
    scanf("%d", &input);
    int nL = n / 2;
    int nR = n - nL - 1;
    BinTree L = BuildBalanceTree(nL);
    BinTree R = BuildBalanceTree(nR);
    return Tree(input, L, R);
  }
}
/* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca */

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

/* *** Traversal *** */
void PrintPreorder(BinTree P)
{
  printf("(");
  if (!IsTreeEmpty(P))
  {
    printf("%d", Akar(P));
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
void PrintInorder(BinTree P)
{
  printf("(");
  if (!IsTreeEmpty(P))
  {
    PrintInorder(Left(P));
    printf("%d", Akar(P));
    PrintInorder(Right(P));
  }
  printf(")");
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
void PrintPostorder(BinTree P)
{
  printf("(");
  if (!IsTreeEmpty(P))
  {
    PrintPostorder(Left(P));
    PrintPostorder(Right(P));
    printf("%d", Akar(P));
  }
  printf(")");
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
void PrintTree(BinTree P, int h)
{
  if (!IsTreeEmpty(P))
  {
    printf("%d\n", Akar(P));
    if (Left(P) != Nil)
    {
      for (int i = 0; i < h; i++)
      {
        printf(" ");
      }
      PrintTree(Left(P), 2 * h);
    }
    if (Right(P) != Nil)
    {
      for (int i = 0; i < h; i++)
      {
        printf(" ");
      }
      PrintTree(Right(P), 2 * h);
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
    if (Akar(P) == X)
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
boolean IsSkewLeft(BinTree P)
{
  if (IsTreeEmpty(P))
  {
    return true;
  }
  else
  {
    return (Right(P) == Nil && IsSkewLeft(Left(P)));
  }
}
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
boolean IsSkewRight(BinTree P)
{
  if (IsTreeEmpty(P))
  {
    return true;
  }
  else
  {
    return (Left(P) == Nil && IsSkewRight(Left(P)));
  }
}
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
int Level(BinTree P, infotypeLR X)
{
  if (IsTreeOneElmt(P) || Akar(P) == X)
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
int Tinggi(BinTree P)
{
  if (IsTreeEmpty(P))
  {
    return 0;
  }
  else
  {
    int L = Tinggi(Left(P));
    int R = Tinggi(Right(P));
    if (L >= R)
    {
      return 1 + L;
    }
    else
    {
      return 1 + R;
    }
  }
}
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */

/* *** Operasi lain *** */
void AddDaunTerkiri(BinTree *P, infotypeLR X)
{
  if (IsTreeEmpty(*P))
  {
    *P = AlokNode(X);
  }
  else
  {
    AddDaunTerkiri(&Left(*P), X);
  }
}
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
void AddDaun(BinTree *P, infotypeLR X, infotypeLR Y, boolean Kiri)
{
  if (IsTreeOneElmt(*P) && Akar(*P) == X)
  {
    addrNode L = AlokNode(Y);
    if (L != Nil)
    {
      if (Kiri)
      {
        Left(*P) = L;
      }
      else
      {
        Right(*P) = L;
      }
    }
  }
  else
  {
    if (SearchTree(Left(*P), X))
    {
      AddDaun(&Left(*P), X, Y, Kiri);
    }
    else
    {
      AddDaun(&Right(*P), X, Y, Kiri);
    }
  }
}
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau 
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
void DelDaunTerkiri(BinTree *P, infotypeLR *X)
{
  if (IsTreeOneElmt(*P))
  {
    *X = Akar(*P);
    DealokNode(*P);
    *P = Nil;
  }
  else
  {
    if (IsUnerRight(*P))
    {
      int R = Akar(Right(*P));
      DelDaunTerkiri(&Right(*P), X);
      if(*X == R)
      {
        Right(*P) = Nil;
      }
    }
    else
    {
      int L = Akar(Left(*P));
      DelDaunTerkiri(&Left(*P), X);
      if(*X == L)
      {
        Left(*P) = Nil;
      }
    }
  }
}
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula 
        disimpan pada daun terkiri yang dihapus */
void DelDaun(BinTree *P, infotypeLR X)
{
  if (IsTreeOneElmt(*P))
  {
    if (Akar(*P) == X)
    {
      DealokNode(*P);
    }
  }
  else
  {
    if (SearchTree(Left(*P), X))
    {
      int L = Akar(Left(*P));
      DelDaun(&Left(*P), X);
      if(X == L)
      {
        Left(*P) = Nil;
      }
    }
    if (SearchTree(Right(*P), X))
    {
      int R = Akar(Right(*P));
      DelDaun(&Right(*P), X);
      if(X == R)
      {
        Right(*P) = Nil;
      }
    }
  }
}
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
ListRek MakeListDaun(BinTree P)
{
  if (IsTreeEmpty(P))
  {
    return Nil;
  }
  else if (IsTreeOneElmt(P))
  {
    return AlokasiListRek(Akar(P));
  }
  else
  {
    return ConcatListRek(MakeListDaun(Left(P)), MakeListDaun(Right(P)));
  }
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
   jika semua alokasi list berhasil.
   Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
ListRek MakeListPreorder(BinTree P)
{
  if (IsTreeEmpty(P))
  {
    return Nil;
  }
  else
  {
    ListRek E = AlokasiListRek(Akar(P));
    if (E != Nil)
    {
      NextListRek(E) = MakeListPreorder(Left(P));
      return ConcatListRek(E, MakeListPreorder(Right(P)));
    }
    else
    {
      return Nil;
    }
  }
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P 
   dengan urutan preorder, jika semua alokasi berhasil.   
   Menghasilkan list kosong jika ada alokasi yang gagal. */
ListRek MakeListLevel(BinTree P, int N)
{
  if (IsTreeEmpty(P))
  {
    return Nil;
  }
  else
  {
    if (N == 1)
    {
      ListRek Hasil = AlokasiListRek(Akar(P));
      if (Hasil != Nil)
      {
        return Hasil;
      }
      else
      {
        return Nil;
      }
    }
    else
    {
      return ConcatListRek(MakeListLevel(Left(P), N - 1), MakeListLevel(Right(P), N - 1));
    }
  }
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P 
   yang levelnya=N, jika semua alokasi berhasil. 
   Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */

/* *** Binary  Search  Tree  *** */
boolean BSearch(BinTree P, infotypeLR X)
{
  if (IsTreeEmpty(P))
  {
    return false;
  }
  else
  {
    if (Akar(P) > X)
    {
      return BSearch(Left(P), X);
    }
    else if(Akar(P) < X)
    {
      return BSearch(Right(P), X);
    }else if(Akar(P) == X)
    {
      return true;
    }
  }
}
/* Mengirimkan true jika ada node dari P yang bernilai X */

void InsSearch(BinTree *P, infotypeLR X)
{
  if (IsTreeEmpty(*P))
  {
    MakeTree(X, Nil, Nil, P);
  }
  else
  {
    if (Akar(*P) < X)
    {
      InsSearch(&Right(*P), X);
    }
    else
    {
      InsSearch(&Left(*P), X);
    }
  }
}
/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. */

void DelBtree(BinTree *P, infotypeLR X)
{
  if (X < Akar(*P))
  {
    DelBtree(&Left(*P), X);
  }
  else if (X > Akar(*P))
  {
    DelBtree(&Right(*P), X);
  }
  else
  {
    addrNode q = *P;
    if (IsTreeOneElmt(q))
    {
      *P = Nil;
    }
    else if (IsUnerLeft(q))
    {
      *P = Left(q);
    }
    else if (IsUnerRight(q))
    {
      *P = Right(q);
    }
    else if (IsBiner(q))
    {
      /* Ambil Node kiri dari q */
      addrNode Parent = q;
      addrNode L = Left(q);
      /* AMbil Node terkanan dari L */
      boolean kiri = true;
      while (Right(L) != Nil)
      {
        kiri = false;
        Parent = L;
        L = Right(L);
      }
      /* dapet node terkanan */
      /* terkanan dihapus, P jadi terkanan */
      Akar(q) = Akar(L);
      q = L;
      L = Left(L);
      if (kiri)
      {
        Left(Parent) = Nil;
      }
      else
      {
        Right(Parent) = Nil;
      }
    }
    DealokNode(q);
  }
}
/* I.S. Pohon P tidak  kosong */
/* F.S. Nilai X yang dihapus pasti ada */
/* Sebuah node dengan nilai X dihapus */
